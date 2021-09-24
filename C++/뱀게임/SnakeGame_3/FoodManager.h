#pragma once
#include "BaseHeader.h"
#include "DrawManager.h"

#define MAXFOOD 10
#define MAKEFOODCOOLTIME 300

class FoodManager
{
private:
	int m_iMakeFoodClock; //���̻����ð�
	int m_iFood; //������̰���
	string m_strFoodShape;
	vector<Point> Foods;
	DrawManager D_M;
public:
	FoodManager();
	void MakeFood(vector<Point> SnakeTails, vector<Point> RandomWalls, Point SnakeHead);
	bool EatFood(Point SnakeHead);
	void ReSetFood();
	~FoodManager();
};

