#include "Calculate.h"

Calculate::Calculate()
{
}
void Calculate::InPutWorkingPay()
{
	int iWorkDay, iWorkPay, iWorkTime;
	int iSelect;
	bool bPassStatus = true;

	while (bPassStatus)
	{
		cout << "���� �ٹ��߳�?";
		cin >> iWorkDay;
		if (iWorkDay < 0)
		continue;
		cout << "�ð��� �ñ��� �Է� �ϰڳ�?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "�ñ��Է� : ";
			cin >> iWorkPay;
			cout << "�ð� �Է� : ";
			cin >> iWorkTime;
			if (iWorkPay < 0 || iWorkTime < 0)
				continue;

			SetWorkingPay(iWorkDay, iWorkPay, iWorkTime);
			bPassStatus = false;
			break;
		case 2:
			SetWorkingPay(iWorkDay);
			bPassStatus = false;
			break;
		default:
			cout << "1�Ǵ� 2�� �Է�";
			break;
		}
		
	}
	ShowWorkingPay();

}

void Calculate::SetWorkingPay(int iWorkDay, int iWorkPay, int iWorkTime)
{
	m_iWorkDay = iWorkDay;
	m_iWorkPay = iWorkPay;
	m_iWorkTime = iWorkTime;
	
}

void Calculate::ShowWorkingPay()
{
	cout << "�ñ� : " << m_iWorkPay << endl;
	cout << "�ð� : " << m_iWorkTime << endl;
	cout << "�ϼ� : " << m_iWorkDay << endl;
	cout << "�޿� : " << m_iWorkPay*m_iWorkTime*m_iWorkDay;
}

void Calculate::InputAddSum()
{
	int iSelect;
	int iNum;
	const int DefaultNum = 10;
	bool bPassStatus = true;

	while (bPassStatus)
	{
		cout << "���� ���� ���� �ϰڳ�?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "�ִ밪 �Է� : (���� : "<<DefaultNum<<")";
			cin >> iNum;
			if (iNum < 1)
				continue;
			SetAddSum(iNum);
			bPassStatus = false;
			break;
		case 2:
			SetAddSum();
			bPassStatus = false;
			break;
		default:
			cout << "1�Ǵ� 2�� �Է�";
			break;
		}
	}
	ShowAddSum();
}

void Calculate::SetAddSum(int iNum)
{
	m_iNum = iNum;
}

void Calculate::ShowAddSum()
{
	int iSum = 0;
	for (int i = 1; i <= m_iNum; i++)
	iSum += i;
	cout << "1 ~" << m_iNum << "�� �� : " << iSum;	
}

void Calculate::InPutGuGuDan()
{
	int iSelect;
	int iStartDan, iEndDan;
	bool bPassStatus = true;

	while (bPassStatus)
	{
		cout << "���� ���� �ϰڴ°�?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "���� �� �Է� : ";
			cin >> iStartDan;
			cout << "�� �� �Է� : ";
			cin >> iEndDan;
			if (iEndDan < iStartDan)
			{
				cout << "������ ���۴� ���� ���� �� �����ϴ�" << endl;
				continue;
			}
			SetGuGuDan(iStartDan, iEndDan);
			bPassStatus = false;
			break;
		case 2:
			SetGuGuDan();
			bPassStatus = false;
			break;
		default:
			cout << "1�Ǵ� 2�� �Է�";
			break;
			}
		}
	ShowGuGuDan();
}

void Calculate::SetGuGuDan(int iStartDan, int iEndDan)
{
	m_iStartDan = iStartDan;
	m_iEndDan = iEndDan;
}

void Calculate::ShowGuGuDan()
{

			for (int i = m_iStartDan; i <= m_iEndDan; i++)
				cout << "=====" << i << "��=====\t";

			cout << endl;
			for (int j = GUGUDANSTART; j <= GUGUDANEND; j++)
			{

				for (int i = m_iStartDan; i <= m_iEndDan; i++)
				{

					cout << "    " << i << "x" << j << "=" << i*j << "\t";

				}
				cout << endl;
			}
			
}

void Calculate :: SelectMenu()
{
	system("cls");
	cout << "���� 1. �ñ� ���" << endl;
	cout << "���� 2. 1~x�� ������ ��" << endl;
	cout << "���� 3. ������ ���" << endl;
	cout << "    4. ����" << endl;
	cout << "�Է� : ";
}

Calculate::~Calculate()
{
}
