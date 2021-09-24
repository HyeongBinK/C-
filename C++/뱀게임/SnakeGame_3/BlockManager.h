#pragma once
#include"BaseHeader.h"
#include"DrawManager.h"

#define MAXWALL 50

class BlockManager
{
private:
	string m_strWallShape;
	DrawManager D_M;
	vector<Point> RandomWalls;
public:
	BlockManager();
	void MakeRandomWall(Point SnakeHead);
	void MakeBorders();
	void ReSetWall();

	vector<Point> inline GetRandomWalls()
	{
		return RandomWalls;
	}

	~BlockManager();
};

