#include "MainHeader.h"
#include "Quiz1.h"
#include "Time.h"

void main()
{
	cout << "1������" << endl;
	Quiz1 q1(10,20), q2(5,40);
	q1.ShowNumber();
	q2.ShowNumber();
	cout << "q1/q2(��ü/��ü)" << endl;
	q1.operator/(q2).ShowNumber();

	system("pause");

	int Select = 0;
	int Day = 1;
	int NewHour, NewMinute;
	Time TotalTime;

	while (Select != 2)
	{
		system("cls");
		cout << "2������" << endl;
		TotalTime.ShowTime();
		cout << "====���� �ð� ���� ���α׷�<" << Day << "Day>====" << endl;
		cout << "1.�ð����" << endl;
		cout << "2.����" << endl;
		cout << "�Է� : ";
		cin >> Select;

		if (Select == 1)
		{
			cout << "�ð� : ";
			cin >> NewHour;
			cout << "�� : ";
			cin >> NewMinute;

			Time NewTime(NewHour, NewMinute);
			TotalTime.operator+(NewTime);
			Day++;
		}

	}







}
