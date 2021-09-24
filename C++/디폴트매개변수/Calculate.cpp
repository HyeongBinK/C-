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
		cout << "몇일 근무했나?";
		cin >> iWorkDay;
		if (iWorkDay < 0)
		continue;
		cout << "시간와 시급을 입력 하겠나?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "시급입력 : ";
			cin >> iWorkPay;
			cout << "시간 입력 : ";
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
			cout << "1또는 2만 입력";
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
	cout << "시급 : " << m_iWorkPay << endl;
	cout << "시간 : " << m_iWorkTime << endl;
	cout << "일수 : " << m_iWorkDay << endl;
	cout << "급여 : " << m_iWorkPay*m_iWorkTime*m_iWorkDay;
}

void Calculate::InputAddSum()
{
	int iSelect;
	int iNum;
	const int DefaultNum = 10;
	bool bPassStatus = true;

	while (bPassStatus)
	{
		cout << "최종 값을 변경 하겠나?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "최대값 입력 : (현재 : "<<DefaultNum<<")";
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
			cout << "1또는 2만 입력";
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
	cout << "1 ~" << m_iNum << "총 합 : " << iSum;	
}

void Calculate::InPutGuGuDan()
{
	int iSelect;
	int iStartDan, iEndDan;
	bool bPassStatus = true;

	while (bPassStatus)
	{
		cout << "값을 변경 하겠는가?" << endl;
		cout << "(Yes: 1, No: 2)";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "시작 단 입력 : ";
			cin >> iStartDan;
			cout << "끝 단 입력 : ";
			cin >> iEndDan;
			if (iEndDan < iStartDan)
			{
				cout << "끝단이 시작단 보다 작을 순 없습니다" << endl;
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
			cout << "1또는 2만 입력";
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
				cout << "=====" << i << "단=====\t";

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
	cout << "문제 1. 시급 계산" << endl;
	cout << "문제 2. 1~x수 까지의 합" << endl;
	cout << "문제 3. 구구단 출력" << endl;
	cout << "    4. 종료" << endl;
	cout << "입력 : ";
}

Calculate::~Calculate()
{
}
