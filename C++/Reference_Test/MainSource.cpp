#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

//1번. 두개의 정수 입력받아 큰수출력
void Func1(int su1, int su2, int&num)
{
	if (su1 >= su2)
		num = su1;
	else
		num = su2;
}

//2번. 하나의 수 입력받아 1~100사이 해당수의 배수의 합 출력
void Func2(int&Num)
{
	int sum = 0;
	for (int i = 1; Num*i <= 100; i++)
	{
		sum += Num*i;
	}

	Num = sum;
}

//3번. 하나의 숫자 입력받아 거꾸로 출력
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
	
	cout << "1.두개의 정수를 입력해주세요 : " << endl;
	cin >> isu1 >> isu2;
	Func1(isu1, isu2, iNum);
	cout << "더큰 숫자는 " << iNum << endl;

	cout << "2.1~100사이의 수중 하나를 입력해주세요 : ";
	cin >> iNum;
	while (iNum > 100 || iNum < 1)
	{
		cout << "1~100사이의 수로 다시입력해주세요" << endl;
		cin >> iNum;
	}
	Func2(iNum);
	cout << "1~100사이 해당수의 배수의 합 : " << iNum << endl;

	cout << "3.하나의 숫자를 입력해주세요 : ";
	cin >> iNum;
	Func3(iNum);
	cout << "거꾸러 출력된수 : " << iNum << endl;
	system("pause");
}