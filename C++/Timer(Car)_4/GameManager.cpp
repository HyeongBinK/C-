#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::KeyMenu()
{
	D_M.gotoxy(10, 10);
	D_M.DrawMidText("SPACE : 속도변환" , 10, 11);
	D_M.DrawMidText("ESC : 종료", 10, 12);
	D_M.DrawMidText("A : 일시정지", 10, 13);
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
			if (ch == PAUSEKEY) //파일실행중에 중단점걸어서 디버깅하기위해 만듬
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
