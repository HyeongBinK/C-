#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::KeyMenu()
{
	D_M.gotoxy(10, 10);
	D_M.DrawMidText("SPACE : �ӵ���ȯ" , 10, 11);
	D_M.DrawMidText("ESC : ����", 10, 12);
	D_M.DrawMidText("A : �Ͻ�����", 10, 13);
}

void GameManager::PlayGame()
{
	char ch = NULL;
	KeyMenu();
	while (ch != ESC)
	{
		if (kbhit())
		{
			ch = getch();
			if (ch == SPACE)
				C_M.CarSpeedChange();
			if (ch == PAUSEKEY) //���Ͻ����߿� �ߴ����ɾ ������ϱ����� ����
				system("pause");
		}
		C_M.MoveCars();
		C_M.MakeCar();
		C_M.DeleteCar();
	}
}

GameManager::~GameManager()
{
}
