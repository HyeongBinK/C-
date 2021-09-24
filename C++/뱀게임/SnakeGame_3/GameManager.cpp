#include "GameManager.h"

GameManager::GameManager()
{
	int Width = (BORDER_WIDTH * 2) + 1;
	int Height = BORDER_HEIGHT + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	m_iGameScore = 0;
}

void GameManager::StartMenu()
{
	system("cls");
	B_M.MakeBorders();
	D_M.DrawMidText("☆ ★ ☆ Snake Game ☆ ★ ☆", BORDER_WIDTH, 8);
	D_M.DrawMidText("1. 게임 시작", BORDER_WIDTH, 11);
	D_M.DrawMidText("2. 게임 종료", BORDER_WIDTH, 14);
	ShowGameScore();
	D_M.DrawMidText("선택 :", BORDER_WIDTH, 17);
}

void GameManager::GameOver()
{
	system("cls");
	B_M.MakeBorders();
	D_M.DrawMidText("☆ ★ ☆ Game Over ☆ ★ ☆", BORDER_WIDTH, BORDER_HEIGHT / 2 - 3);
	D_M.DrawMidText("아무키나 누르면 선택창으로돌아갑니다", BORDER_WIDTH, BORDER_HEIGHT / 2);
	ShowGameScore();
	getch();
}

void GameManager::ShowGameScore()
{
	D_M.DrawMidText_int("Score : ", m_iGameScore, BORDER_WIDTH - 5, BORDER_HEIGHT + 2);
	D_M.gotoxy(0, 0);
}

void GameManager::Game()
{
	B_M.MakeBorders();
	int iSelect;

	while (true)
	{
		StartMenu();
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			GamePlay();
			break;
		case 2:
			return;
		case 3:
			GameOver();
			break;
		default:
			break;
		}
	}
}

void GameManager::GamePlay()
{
	char ch = NULL;
	system("cls");
	B_M.MakeBorders();
	B_M.MakeRandomWall(S_M.GetHeadLocation());
	ShowGameScore();
	ch = STOP;

	while (1)
	{
		if (kbhit())
		{
			ch = getch();
			S_M.CourseChange(ch);
			if (ch == TEST_A) //파일실행도중 디버깅하기위한 용도 (대문자 A)
				getch();
		}
		F_M.MakeFood(S_M.GetSnakeTailLocation(), B_M.GetRandomWalls(), S_M.GetHeadLocation());

		F_M.EatFood(S_M.GetHeadLocation());
		S_M.Move_Head();

		if (F_M.EatFood(S_M.GetHeadLocation()) == true)
		{
			m_iGameScore++;
			ShowGameScore();
			S_M.MakeTail();
			S_M.SpeedUp();
		}

		if (S_M.CheckHit(B_M.GetRandomWalls()) == true)
		{
			GameOver();
			ReSetStatus();
			return;
		}
	}
}

void GameManager::ReSetStatus()
{
	m_iGameScore = 0;
	S_M.ReSetSnake();
	B_M.ReSetWall();
	F_M.ReSetFood();
	getch();
}

GameManager::~GameManager()
{
}
