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
	cout << "1_1������. ���� 2�� �Է� : ";
	while (bPassStatus)
	{
		cin >> iNum1 >> iNum2;

		if (iNum2 < 0)
		{
			cout << iNum2 << "�� 0���� �۽��ϴ�" << endl;
			continue;
		}

		bPassStatus = false;
	}
	OLT.OverLoading1(iNum1, iNum2);

	bPassStatus = true;

	cout << "1_2������. ���Ϲ��ڿ� ���� �Է� : ";
	while (bPassStatus)
	{
		cin >> chA >> iNum1;
		if (chA < 'A' || chA > 'z' || (chA > 'Z' && chA < 'a'))
		{
			cout << "�ش繮�ڰ� ���ĺ��� �ƴմϴ�." << endl;
			continue;
		}
		bPassStatus = false;
	}
	OLT.OverLoading1(chA, iNum1);

	cout << "2_1������. ���ڿ� �ϳ� �Է� : ";
	cin >> strA;
	OLT.OverLoading2(strA);

	cout << "2_2������. ���ڿ� �ΰ� �Է� : ";
	cin >> strA >> strB;
	OLT.OverLoading2(strA, strB);

	cout << "3_1������. ���� 5�� �Է� : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> iNum_List[i];
	}
	OLT.OverLoading3(iNum_List);

	cout << "3_2������. ���Ϲ��� 5�� �Է� : ";
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