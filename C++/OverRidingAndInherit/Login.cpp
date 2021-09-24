#include "Login.h"

Login::Login()
{
	m_iMemberNum = 0; // 현재 저장된 멤버수 표시
	m_iMemo_ID_Num = 0;

}

void Login::FirstMenu()
{
	cout << "=====Login=====" << "<회원수[" << m_iMemberNum << "명]" << endl;
	cout << "1. 회원가입" << endl;
	cout << "2. 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "입력 :" << endl;
}

void Login::CheckID()
{
	string IdCheck, SecretNumCheck;

	while (1)
	{
		int ID_PASS = NOPASS, PW_PASS = NOPASS;
		system("cls");
		cout << "아이디 입력 : ";
		cin >> IdCheck;
		cout << "비밀번호 입력 : ";
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
			cout << "아이디가 존재하지 않습니다" << endl;
			system("pause");
		}
		if (ID_PASS == PASS  && PW_PASS == NOPASS)
		{
			cout << "비밀번호가 틀렸습니다." << endl;
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
			cout << "==========회원 정보==========" << endl;
			cout << "ID : " << iter->m_strID << endl;
			cout << "닉네임 : " << iter->m_strNickName << endl;
			cout << "나이 : " << iter->m_iAge << endl;
			cout << "휴대폰 번호 : " << iter->m_strPhoneNumber << endl;
			cout << "마일리지 : " << iter->m_iMilage << endl;
			break;
		}
	}
}

void Login::ReMakeNickName(string* NickName)
{
	string Memo;
	cout << "현재 닉네임" << *NickName << endl;
	Memo = *NickName;
	cout << "변경할 닉네임 입력: ";
	cin >> (*NickName);
	cout << Memo << "->" << *NickName;
	system("pause");
}

void Login::ReAgeInput(int* Age)
{
	int Memo;
	cout << "현재 나이" << *Age << endl;
	Memo = *Age;
	cout << "변경할 나이 입력: ";
	cin >> (*Age);
	cout << Memo << "->" << *Age;
	system("pause");
}

void Login::ReInputPhoneNumber(string* PhoneNumber)
{
	string Memo;
	cout << "현재 폰번호" << *PhoneNumber << endl;
	Memo = *PhoneNumber;
	cout << "변경할 폰번호 입력: ";
	cin >> (*PhoneNumber);
	cout << Memo << "->" << *PhoneNumber;
	system("pause");
}

void Login::DataChangeMenu()
{
	cout << "===============================" << endl;
	cout << "1.닉네임 변경" << endl;
	cout << "2.나이 변경" << endl;
	cout << "3.휴대폰번호 변경" << endl;
	cout << "4.돌아가기" << endl;
	cout << "입력 : ";
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
			Check_OverLap = PASS; //Id 중복 확인

			system("cls");
			cout << "아이디 입력<[3글자↑]AND[오직 영문자만]> :";
			cin >> (MD.m_strID);

			for (auto iter = MD_L.begin(); iter != MD_L.end(); iter++)
			{
				if (iter->m_strID == MD.m_strID)
				{
					cout << "동일한 아이디가 존재합니다" << endl;
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
			cout << "ID가 3글자 이하입니다." << endl;


		for (int i = 0; i < (MD.m_strID).length(); i++)
		{
			if ((MD.m_strID)[i] < 'A' || (MD.m_strID)[i] > 'z')
				English_Pass = NOPASS;
			if ((MD.m_strID)[i] > 'Z' && (MD.m_strID)[i] < 'a')
				English_Pass = NOPASS;
		}
		if (English_Pass == NOPASS)
			cout << "영문자만 사용해주세요" << endl;

		if (Length_Pass == PASS && English_Pass == PASS)
			break;
		else
			system("pause");
	}

	while (1)
	{
		system("cls");
		Length_Pass = NOPASS, English_Pass = PASS, NUMBER_PASS = NOPASS;

		cout << "비밀번호입력<[8글자↑]AND[숫자를 포함하여 숫자 또는 영문자만]> :";
		cin >> (MD.m_strSecretNumber);
		if ((MD.m_strSecretNumber).length() >= PASSWORD_LENGTH_MIN)
			Length_Pass = PASS;
		else
			cout << "SecretNumber가 8글자 이하입니다." << endl;


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
			cout << "영문자와 숫자만을 사용해주세요" << endl;

		if (NUMBER_PASS == NOPASS)
			cout << "숫자를 한번이상 입력해주세요" << endl;

		if (Length_Pass == PASS && English_Pass == PASS && NUMBER_PASS == PASS)
		{
			cout << "비밀번호 확인: ";
			cin >> checksecret;
			if (checksecret == (MD.m_strSecretNumber))
				break;
			else
			{
				cout << "비밀번호가 일치하지 않습니다" << endl;
				system("pause");
			}
		}
		else
			system("pause");
	}

	system("cls");
	cout << "닉네임 입력: ";
	cin >> MD.m_strNickName;
	cout << "나이 입력: ";
	cin >> MD.m_iAge;
	cout << "휴대폰번호 입력: ";
	cin >> MD.m_strPhoneNumber;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
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
				cout << "==========회원 정보==========" << endl;
				cout << "ID : " << iter->m_strID << endl;
				cout << "닉네임 : " << iter->m_strNickName << endl;
				cout << "나이 : " << iter->m_iAge << endl;
				cout << "휴대폰 번호 : " << iter->m_strPhoneNumber << endl;
				cout << "마일리지 : " << iter->m_iMilage << endl;
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
