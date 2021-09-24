#include "FoodManager.h"

FoodManager::FoodManager()
{
	m_iFood = 0;
	m_strFoodShape = "¡Ú";
	m_iMakeFoodClock = clock();
}

void FoodManager::MakeFood(vector<Point> SnakeTails, vector<Point> RandomWalls, Point SnakeHead)
{
	int MakeFlag;
	Point Food;
	if (clock() - m_iMakeFoodClock >= MAKEFOODCOOLTIME)
	{
		if (m_iFood <= MAXFOOD)
		{
			MakeFlag = true;

			Food.m_iX_Location = (rand() % BORDER_WIDTH - 5) + 3;
			Food.m_iY_Location = (rand() % BORDER_HEIGHT - 5) + 3;

			if (Food.m_iX_Location == SnakeHead.m_iX_Location && Food.m_iY_Location == SnakeHead.m_iY_Location)
				MakeFlag = false;
			for (auto iter = SnakeTails.begin(); iter != SnakeTails.end(); iter++)
			{
				if (Food.m_iX_Location == iter->m_iX_Location && Food.m_iY_Location == iter->m_iY_Location)
					MakeFlag = false;
			}

			for (auto iter = RandomWalls.begin(); iter != RandomWalls.end(); iter++)
			{
				if (Food.m_iX_Location == iter->m_iX_Location && Food.m_iY_Location == iter->m_iY_Location)
					MakeFlag = false;
			}

			if (Food.m_iX_Location == 0 || Food.m_iX_Location == BORDER_WIDTH)
				MakeFlag = false;

			if (Food.m_iY_Location == 0 || Food.m_iY_Location == BORDER_HEIGHT)
				MakeFlag = false;

			if (MakeFlag == true)
			{
				Foods.push_back(Food);
				D_M.DrawPoint(m_strFoodShape, Food.m_iX_Location, Food.m_iY_Location);
				m_iFood++;
				m_iMakeFoodClock = clock();
				return;
			}
			else
				MakeFood(SnakeTails, RandomWalls, SnakeHead);
		}
	}
}

bool FoodManager::EatFood(Point SnakeHead)
{
	for (auto iter = Foods.begin(); iter != Foods.end(); iter++)
	{
		if (SnakeHead.m_iX_Location == iter->m_iX_Location && SnakeHead.m_iY_Location == iter->m_iY_Location)
		{
			iter = Foods.erase(iter);
			m_iFood--;
			return true;
		}
	}
	return false;
}

void FoodManager::ReSetFood()
{
	for (auto iter = Foods.begin(); iter != Foods.end(); iter++)
	{
		D_M.ErasePoint(iter->m_iX_Location, iter->m_iY_Location);
	}
	Foods.clear();
	m_iMakeFoodClock = clock();
	m_iFood = 0;
}

FoodManager::~FoodManager()
{
}
