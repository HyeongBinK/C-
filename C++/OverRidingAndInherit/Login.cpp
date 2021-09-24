#include "Login.h"

Login::Login()
{
	m_iMemberNum = 0; // ���� ����� ����� ǥ��
	m_iMemo_ID_Num = 0;

}

void Login::FirstMenu()
{
	cout << "=====Login=====" << "<ȸ����[" << m_iMemberNum << "��]" << endl;
	cout << "1. ȸ������" << endl;
	cout << "2. �α���" << endl;
	cout << "3. ����" << endl;
	cout << "�Է� :" << endl;
}

void Login::CheckID()
{
	string IdCheck, SecretNumCheck;

	while (1)
	{
		int ID_PASS = NOPASS, PW_PASS = NOPASS;
		system("cls");
		cout << "���̵� �Է� : ";
		cin >> IdCheck;
		cout << "��й�ȣ �Է� : ";
		cin >> SecretNumCheck;

		for (auto iter = MD_L.begin(); iter != MD_L.end(); iter++)
		{
			if (IdCheck == iter->m_strID)
			{
				ID_PASS = PASS;
				if (SecretNumCheck == iter->m_strSecretNumber)
				{
					PW_PASS = PASS;
					if (ID_PASS == PASS && PW_PASS == PASS)
					m_iMemo_ID_Num = iter->m_iMemberNum;
				}
				break;
			}
		}

		if (ID_PASS == NOPASS)
		{
			cout << "���̵� �������� �ʽ��ϴ�" << endl;
			system("pause");
		}
		if (ID_PASS == PASS  && PW_PASS == NOPASS)
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			system("pause");
		}
		if (ID_PASS == PASS && PW_PASS == PASS)
			break;
		
	}

}


void Login::ShowInformation()
{
	system("cls");
	for (auto iter = MD_L.begin(); iter != MD_L.end(); iter++)
	{
		if (iter->m_iMemberNum == m_iMemo_ID_Num)
		{
			cout << "==========ȸ�� ����==========" << endl;
			cout << "ID : " << iter->m_strID << endl;
			cout << "�г��� : " << iter->m_strNickName << endl;
			cout << "���� : " << iter->m_iAge << endl;
			cout << "�޴��� ��ȣ : " << iter->m_strPhoneNumber << endl;
			cout << "���ϸ��� : " << iter->m_iMilage << endl;
			break;
		}
	}
}

void Login::ReMakeNickName(string* NickName)
{
	string Memo;
	cout << "���� �г���" << *NickName << endl;
	Memo = *NickName;
	cout << "������ �г��� �Է�: ";
	cin >> (*NickName);
	cout << Memo << "->" << *NickName;
	system("pause");
}

void Login::ReAgeInput(int* Age)
{
	int Memo;
	cout << "���� ����" << *Age << endl;
	Memo = *Age;
	cout << "������ ���� �Է�: ";
	cin >> (*Age);
	cout << Memo << "->" << *Age;
	system("pause");
}

void Login::ReInputPhoneNumber(string* PhoneNumber)
{
	string Memo;
	cout << "���� ����ȣ" << *PhoneNumber << endl;
	Memo = *PhoneNumber;
	cout << "������ ����ȣ �Է�: ";
	cin >> (*PhoneNumber);
	cout << Memo << "->" << *PhoneNumber;
	system("pause");
}

void Login::DataChangeMenu()
{
	cout << "===============================" << endl;
	cout << "1.�г��� ����" << endl;
	cout << "2.���� ����" << endl;
	cout << "3.�޴�����ȣ ����" << endl;
	cout << "4.���ư���" << endl;
	cout << "�Է� : ";
}

void Login::MakeData()
{
	MemberData MD;
	int Length_Pass, English_Pass, NUMBER_PASS;
	int Check_OverLap;
	string checksecret;

	while (1)
	{
		Length_Pass = NOPASS;
		English_Pass = PASS;

		while (1)
		{
			Check_OverLap = PASS; //Id �ߺ� Ȯ��

			system("cls");
			cout << "���̵� �Է�<[3���ڡ�]AND[���� �����ڸ�]> :";
			cin >> (MD.m_strID);

			for (auto iter = MD_L.begin(); iter != MD_L.end(); iter++)
			{
				if (iter->m_strID == MD.m_strID)
				{
					cout << "������ ���̵� �����մϴ�" << endl;
					Check_OverLap = NOPASS;
					system("pause");
				}

			}

			if (Check_OverLap == PASS)
				break;
		}

		if ((MD.m_strID).length() >= 3)
			Length_Pass = PASS;
		else
			cout << "ID�� 3���� �����Դϴ�." << endl;


		for (int i = 0; i < (MD.m_strID).length(); i++)
		{
			if ((MD.m_strID)[i] < 'A' || (MD.m_strID)[i] > 'z')
				English_Pass = NOPASS;
			if ((MD.m_strID)[i] > 'Z' && (MD.m_strID)[i] < 'a')
				English_Pass = NOPASS;
		}
		if (English_Pass == NOPASS)
			cout << "�����ڸ� ������ּ���" << endl;

		if (Length_Pass == PASS && English_Pass == PASS)
			break;
		else
			system("pause");
	}

	while (1)
	{
		system("cls");
		Length_Pass = NOPASS, English_Pass = PASS, NUMBER_PASS = NOPASS;

		cout << "��й�ȣ�Է�<[8���ڡ�]AND[���ڸ� �����Ͽ� ���� �Ǵ� �����ڸ�]> :";
		cin >> (MD.m_strSecretNumber);
		if ((MD.m_strSecretNumber).length() >= PASSWORD_LENGTH_MIN)
			Length_Pass = PASS;
		else
			cout << "SecretNumber�� 8���� �����Դϴ�." << endl;


		for (int i = 0; i < (MD.m_strSecretNumber).length(); i++)
		{
			if ((MD.m_strSecretNumber)[i] < 'A' || (MD.m_strSecretNumber)[i] > 'z')
			{
				if ((MD.m_strSecretNumber)[i] > '9' || (MD.m_strSecretNumber)[i] < '0')
				{
					English_Pass = NOPASS;
				}
				else
					NUMBER_PASS = PASS;
			}

			if ((MD.m_strSecretNumber)[i] > 'Z' && (MD.m_strSecretNumber)[i] < 'a')
				English_Pass = NOPASS;
		}

		if (English_Pass == NOPASS)
			cout << "�����ڿ� ���ڸ��� ������ּ���" << endl;

		if (NUMBER_PASS == NOPASS)
			cout << "���ڸ� �ѹ��̻� �Է����ּ���" << endl;

		if (Length_Pass == PASS && English_Pass == PASS && NUMBER_PASS == PASS)
		{
			cout << "��й�ȣ Ȯ��: ";
			cin >> checksecret;
			if (checksecret == (MD.m_strSecretNumber))
				break;
			else
			{
				cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
				system("pause");
			}
		}
		else
			system("pause");
	}

	system("cls");
	cout << "�г��� �Է�: ";
	cin >> MD.m_strNickName;
	cout << "���� �Է�: ";
	cin >> MD.m_iAge;
	cout << "�޴�����ȣ �Է�: ";
	cin >> MD.m_strPhoneNumber;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	MD.m_iMilage = 1000;
	MD.m_iMemberNum = m_iMemberNum;
	
	MD_L.push_back(MD);
	m_iMemberNum++;
	system("pause");
}

void Login::DataChange()
{
	int Select;
	while (1)
	{
		for (auto iter = MD_L.begin(); iter != MD_L.end(); iter++)
		{
			system("cls");
			if (iter->m_iMemberNum == m_iMemo_ID_Num)
			{
				cout << "==========ȸ�� ����==========" << endl;
				cout << "ID : " << iter->m_strID << endl;
				cout << "�г��� : " << iter->m_strNickName << endl;
				cout << "���� : " << iter->m_iAge << endl;
				cout << "�޴��� ��ȣ : " << iter->m_strPhoneNumber << endl;
				cout << "���ϸ��� : " << iter->m_iMilage << endl;
				DataChangeMenu();
				cin >> Select;
				switch (Select)
				{
				case 1:
					ReMakeNickName(&iter->m_strNickName);
					break;
				case 2:
					ReAgeInput(&iter->m_iAge);
					break;
				case 3:
					ReInputPhoneNumber(&iter->m_strPhoneNumber);
					break;
				case 4:
					return;
				}
			}
		}

	}
}

Login::~Login()
{
}
