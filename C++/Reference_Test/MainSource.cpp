#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

//1��. �ΰ��� ���� �Է¹޾� ū�����
void Func1(int su1, int su2, int&num)
{
	if (su1 >= su2)
		num = su1;
	else
		num = su2;
}

//2��. �ϳ��� �� �Է¹޾� 1~100���� �ش���� ����� �� ���
void Func2(int&Num)
{
	int sum = 0;
	for (int i = 1; Num*i <= 100; i++)
	{
		sum += Num*i;
	}

	Num = sum;
}

//3��. �ϳ��� ���� �Է¹޾� �Ųٷ� ���
void Func3(int&Num)
{
	int Sum = 0;
	while(Num / 10 != 0)
	{
		Sum *= 10;
		Sum += Num % 10;
		Num /= 10;
	}
	Sum *= 10;
	Sum += Num;

	Num = Sum;
}

void main()
{
	int isu1, isu2, iNum;
	
	cout << "1.�ΰ��� ������ �Է����ּ��� : " << endl;
	cin >> isu1 >> isu2;
	Func1(isu1, isu2, iNum);
	cout << "��ū ���ڴ� " << iNum << endl;

	cout << "2.1~100������ ���� �ϳ��� �Է����ּ��� : ";
	cin >> iNum;
	while (iNum > 100 || iNum < 1)
	{
		cout << "1~100������ ���� �ٽ��Է����ּ���" << endl;
		cin >> iNum;
	}
	Func2(iNum);
	cout << "1~100���� �ش���� ����� �� : " << iNum << endl;

	cout << "3.�ϳ��� ���ڸ� �Է����ּ��� : ";
	cin >> iNum;
	Func3(iNum);
	cout << "�Ųٷ� ��µȼ� : " << iNum << endl;
	system("pause");
}