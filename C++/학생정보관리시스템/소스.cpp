#include<Windows.h>
#include"StudentManager.h"


void main()
{
	StudentManager  SManager;

	string strTmp;
	bool bTmp;
	int iTmp;
	int iSelect;
 

	while (1)
	{
		SManager.ShowMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			SManager.AddStudent();
			system("pause");
			break;
		
		case 2:
			system("cls");
			SManager.ShowStudentList();
			system("pause");
			break;

		case 3:
			system("cls");
			SManager.ShowStudentClass();
			system("pause");
			break;

		case 4:
			system("cls");
			cout << "이름 입력 : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);
			if (bTmp == false)
				cout << "해당 학생이 없습니다." << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "학년 입력 : ";
			cin >> iTmp;
			bTmp = SManager.FindStudentClass(iTmp);
			if (bTmp == false)
				cout << "해당 학생이 없습니다." << endl;
			system("pause");
			break;
		case 6:
			SManager.FreeStudent();
			break;
		
		case 7:
			SManager.FreeStudentAll();
			break;

		case 8:
			SManager.FreeStudentAll();
			return;

		}

	}















}



