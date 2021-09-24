#pragma once
#include "DrawManager.h"
#include "BaseHeader.h"

#define BASESPEED 500
#define SPEEDUP_UNIT 20

class SnakeManager
{
private :
	int m_iSpeed; //속도
	int m_iSnakeCourse; //방향
	int m_iSnakeMoveClock; //뱀머리이동시간

	string m_strSnakeHeadShape;
	string m_strSnakeTailShape;

	Point SnakeHead;
	vector<Point> SnakeTails;
	DrawManager D_M;
public:
	SnakeManager();
	void SpeedUp();
	//void GetDammage();
	void CourseChange(char ch);
	void Move_Head();
	void Move_Tails();
	void MakeTail();
	void DrawSnake();
	void EraseSnake();
	bool CheckHit(vector<Point>RandomWalls);
	void ReSetSnake();

	Point inline GetHeadLocation()
	{
		return SnakeHead;
	}

	vector<Point> inline GetSnakeTailLocation()
	{
		return SnakeTails;
	}
	~SnakeManager();
};

