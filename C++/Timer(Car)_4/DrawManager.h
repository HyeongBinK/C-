#pragma once
#include"BaseHeader.h"
#define CAR_BASE_LOCATION_Y 5

class DrawManager
{
public:
	DrawManager();
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawCar(int x);
	void EraseCar(int x);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~DrawManager();
};

