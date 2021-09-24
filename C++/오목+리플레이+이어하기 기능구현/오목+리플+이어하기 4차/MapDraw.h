#pragma once
#include"Mecro.h"


class MapDraw
{
public:
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	void DrawMap(int Start_x, int Start_y, int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void LostSpaceDraw(int x, int y, int Width, int Height);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	MapDraw();
	~MapDraw();
};

