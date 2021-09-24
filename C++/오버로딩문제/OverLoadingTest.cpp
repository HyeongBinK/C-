#include "OverLoadingTest.h"

OverLoadingTest::OverLoadingTest()
{
}
void OverLoadingTest::OverLoading1(int iNum1, int iNum2)
{
	int iResult=1;
	
		for (int i = 0; i < iNum2; i++)
		{
			iResult *= iNum1;
		}

		if (iNum2 == 0)
			iResult = 1;

	cout << iNum1 << "의" << iNum2 << "승 : " << iResult << endl;

}

void OverLoadingTest::OverLoading1(char chA, int iNum)
{
	char cResult;
	int iMemoNum;

	iMemoNum = iNum;

	while(iMemoNum > 25)
	iMemoNum -= 25;

	cResult = chA + iMemoNum;
		
	if(chA < 'Z' && cResult > 'Z')
		cResult -= 26;
	if (chA > 'a' && cResult > 'z')
		cResult -= 26;
		
	cout << "입력받은 단일문자 : " << chA << " 입력받은 정수 : " << iNum << " 결과값 : " << cResult << endl;
}

void OverLoadingTest::OverLoading2(string strA)
{
	cout << strA << "->";

	for (int i = strA.length()-1; i >= 0; i--)
	{
		cout << strA[i];
	}
	cout << endl;
}

void OverLoadingTest::OverLoading2(string strA, string strB)
{
	cout << strA << " + " << strB << " = " << strA + strB << endl;
}

void OverLoadingTest::OverLoading3(int iarr[Arr_MAX])
{
	int itmp;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (iarr[i] > iarr[j])
			{
				itmp = iarr[i];
				iarr[i] = iarr[j];
				iarr[j] = itmp;
			}
		}
	}


	cout << "========= iarr =========" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		cout << "arr[" << i << "] : " << iarr[i] << endl;
	}
}

void OverLoadingTest::OverLoading3(char charr[Arr_MAX])
{
	char chtmp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (charr[i] < charr[j])
			{
				chtmp = charr[i];
				charr[i] = charr[j];
				charr[j] = chtmp;
			}
		}
	}


	cout << "========= Carr =========" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "arr[" << i << "] : " << charr[i] << endl;
	}



}






OverLoadingTest::~OverLoadingTest()
{
}
