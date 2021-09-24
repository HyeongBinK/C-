#include "OverLoadingTest.h"
#include<conio.h>
#include<Windows.h>

#define NULL 0

void main()
{
	OverLoadingTest OLT;
	int iNum1,iNum2;
	char chA;
	string strA, strB;
	int iNum_List[Arr_MAX] = { NULL };
	char chChar_List[Arr_MAX] = { NULL };

	bool bPassStatus = true;
	cout << "1_1번문제. 정수 2개 입력 : ";
	while (bPassStatus)
	{
		cin >> iNum1 >> iNum2;

		if (iNum2 < 0)
		{
			cout << iNum2 << "가 0보다 작습니다" << endl;
			continue;
		}

		bPassStatus = false;
	}
	OLT.OverLoading1(iNum1, iNum2);

	bPassStatus = true;

	cout << "1_2번문제. 단일문자와 정수 입력 : ";
	while (bPassStatus)
	{
		cin >> chA >> iNum1;
		if (chA < 'A' || chA > 'z' || (chA > 'Z' && chA < 'a'))
		{
			cout << "해당문자가 알파벳이 아닙니다." << endl;
			continue;
		}
		bPassStatus = false;
	}
	OLT.OverLoading1(chA, iNum1);

	cout << "2_1번문제. 문자열 하나 입력 : ";
	cin >> strA;
	OLT.OverLoading2(strA);

	cout << "2_2번문제. 문자열 두개 입력 : ";
	cin >> strA >> strB;
	OLT.OverLoading2(strA, strB);

	cout << "3_1번문제. 숫자 5개 입력 : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> iNum_List[i];
	}
	OLT.OverLoading3(iNum_List);

	cout << "3_2번문제. 단일문자 5개 입력 : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> chChar_List[i];
	}
	OLT.OverLoading3(chChar_List);

/*
	OLT.OverLoading3();
*/
	getch();
}