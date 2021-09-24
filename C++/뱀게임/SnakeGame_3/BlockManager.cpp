#include "BlockManager.h"

BlockManager::BlockManager()
{
	m_strWallShape = "■";
}

void BlockManager::MakeBorders()
{
	D_M.DrawBorders(BORDER_WIDTH, BORDER_HEIGHT, m_strWallShape);
}

void BlockManager::MakeRandomWall(Point SnakeHead) //벽은 중복되어도 됨 
{
	int MakeFlag;
	Point Wall;
	for (int i = 0; i < MAXWALL; i++)
	{
		MakeFlag = true;

		Wall.m_iX_Location = (rand() % BORDER_WIDTH - 2) + 1;
		Wall.m_iY_Location = (rand() % BORDER_HEIGHT - 2) + 1;
		if (Wall.m_iX_Location == SnakeHead.m_iX_Location && Wall.m_iY_Location == SnakeHead.m_iY_Location)
			MakeFlag = false;

		if (MakeFlag == true)
			RandomWalls.push_back(Wall);
	}

	for (auto iter = RandomWalls.begin(); iter != RandomWalls.end(); iter++)
	{
		D_M.DrawPoint(m_strWallShape, iter->m_iX_Location, iter->m_iY_Location);
	}

}

void BlockManager::ReSetWall()
{
	RandomWalls.clear();
}

BlockManager::~BlockManager()
{
}
