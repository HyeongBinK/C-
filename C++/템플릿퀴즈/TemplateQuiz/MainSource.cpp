#include "BaseHeader.h"
#include "Quiz1.h"
#include "Quiz2.h"
#include "Quiz3.h"

void main()
{
	Quiz1 quiz1;
	Quiz2 quiz2;
	Quiz3 quiz3;

	cout << "===1�� ����=== " << endl;
	quiz1.PlayQuiz1();

	system("pause");
	system("cls");

	cout << "===2�� ����=== " << endl;
	quiz2.PlayQuiz2();

	system("pause");
	system("cls");

	cout << "===3�� ����=== " << endl;
	quiz3.PlayQuiz3();
}