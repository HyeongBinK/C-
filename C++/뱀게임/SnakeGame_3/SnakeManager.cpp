#include "SnakeManager.h"

SnakeManager::SnakeManager()
{
	m_iSnakeCourse = STOP;
	m_iSpeed = BASESPEED;
	m_strSnakeHeadShape = "¡Ü";
	m_strSnakeTailShape = "¡Û";
	SnakeHead.m_iX_Location = HEAD_START_LOCATION_X;
	SnakeHead.m_iY_Location = HEAD_START_LOCATION_Y;
}

void SnakeManager::SpeedUp()
{
	if (m_iSpeed >= 100)
		m_iSpeed -= SPEEDUP_UNIT;
}

void SnakeManager::MakeTail()
{
	Point Tail;
	switch (m_iSnakeCourse)
	{
	case UP:
		Tail.m_iX_Location = SnakeHead.m_iX_Location;
		Tail.m_iY_Location = SnakeHead.m_iY_Location + 1;
		break;
	case DOWN:
		Tail.m_iX_Location = SnakeHead.m_iX_Location;
		Tail.m_iY_Location = SnakeHead.m_iY_Location - 1;
		break;
	case LEFT:
		Tail.m_iX_Location = SnakeHead.m_iX_Location + 1;
		Tail.m_iY_Location = SnakeHead.m_iY_Location;
		break;
	case RIGHT:
		Tail.m_iX_Location = SnakeHead.m_iX_Location - 1;
		Tail.m_iY_Location = SnakeHead.m_iY_Location;
		break;
	default:
		break;
	}
	SnakeTails.push_back(Tail);
}

void SnakeManager::CourseChange(char ch)
{
	switch (ch)
	{
	case UP:
		m_iSnakeCourse = UP;
		break;
	case DOWN:
		m_iSnakeCourse = DOWN;
		break;
	case RIGHT:
		m_iSnakeCourse = RIGHT;
		break;
	case LEFT:
		m_iSnakeCourse = LEFT;
		break;
	case STOP:
		m_iSnakeCourse = STOP;
		break;
	default:
		break;
	}
}

void SnakeManager::Move_Head()
{
	if (clock() - m_iSnakeMoveClock >= m_iSpeed)
	{
		EraseSnake();
		Move_Tails();
		switch (m_iSnakeCourse)
		{
		case UP:
			SnakeHead.m_iY_Location--;
			break;
		case DOWN:
			SnakeHead.m_iY_Location++;
			break;
		case RIGHT:
			SnakeHead.m_iX_Location++;
			break;
		case LEFT:
			SnakeHead.m_iX_Location--;
			break;
		default:
			break;
		}
		m_iSnakeMoveClock = clock();
		DrawSnake();
	}
}

void SnakeManager::Move_Tails()
{
	int iX_Memo, iY_Memo;
	iX_Memo = SnakeHead.m_iX_Location;
	iY_Memo = SnakeHead.m_iY_Location;

	for (auto iter = SnakeTails.begin(); iter != SnakeTails.end(); iter++)
	{
		int iX_tmp, iY_tmp;
		iX_tmp = iter->m_iX_Location;
		iY_tmp = iter->m_iY_Location;
		iter->m_iX_Location = iX_Memo;
		iter->m_iY_Location = iY_Memo;
		iX_Memo = iX_tmp;
		iY_Memo = iY_tmp;
	}
}

void SnakeManager::DrawSnake()
{
	D_M.DrawPoint(m_strSnakeHeadShape, SnakeHead.m_iX_Location, SnakeHead.m_iY_Location);
	for (auto iter = SnakeTails.begin(); iter != SnakeTails.end(); iter++)
	{
		D_M.DrawPoint(m_strSnakeTailShape, iter->m_iX_Location, iter->m_iY_Location);
	}
}

void SnakeManager::EraseSnake()
{
	D_M.ErasePoint(SnakeHead.m_iX_Location, SnakeHead.m_iY_Location);
	for (auto iter = SnakeTails.begin(); iter != SnakeTails.end(); iter++)
	{
		D_M.ErasePoint(iter->m_iX_Location, iter->m_iY_Location);
	}
}

bool SnakeManager::CheckHit(vector<Point>RandomWalls)
{
	int GameOverFlag = false;

	for (auto iter = RandomWalls.begin(); iter != RandomWalls.end(); iter++)
	{
		if (SnakeHead.m_iX_Location == iter->m_iX_Location && SnakeHead.m_iY_Location == iter->m_iY_Location)
			GameOverFlag = true;
	}

	for (auto iter = SnakeTails.begin(); iter != SnakeTails.end(); iter++)
	{
		if (SnakeHead.m_iX_Location == iter->m_iX_Location && SnakeHead.m_iY_Location == iter->m_iY_Location)
			GameOverFlag = true;
	}

	if (SnakeHead.m_iX_Location == 0)
		GameOverFlag = true;
	if (SnakeHead.m_iX_Location == BORDER_WIDTH)
		GameOverFlag = true;
	if (SnakeHead.m_iY_Location == 0)
		GameOverFlag = true;
	if (SnakeHead.m_iY_Location == BORDER_HEIGHT)
		GameOverFlag = true;

	if (GameOverFlag == true)
	{
		return true;
	}
	else
		return false;
}

void SnakeManager::ReSetSnake()
{
	SnakeTails.clear();
	m_iSpeed = BASESPEED;
	m_iSnakeMoveClock = clock();
	m_iSnakeCourse = STOP;
	SnakeHead.m_iX_Location = HEAD_START_LOCATION_X;
	SnakeHead.m_iY_Location = HEAD_START_LOCATION_Y;
}

//void SnakeManager::GetDammage()
//{
//	if(m_iLife >= 1)
//	m_iLife--;
//}

SnakeManager::~SnakeManager()
{
}
