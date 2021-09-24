#include"Calculate.h"
#include<conio.h>

void main()
{
	int iSelect;
	Calculate Calculate;
	while (1)
	{
		Calculate.SelectMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			system("cls");
			Calculate.InPutWorkingPay();
			system("pause");
			break;
		case 2:
			system("cls");
			Calculate.InputAddSum();
			system("pause");
			break;
		case 3:
			system("cls");
			Calculate.InPutGuGuDan();
			system("pause");
			break;
		case 4:
			return;
		}
	}
}
