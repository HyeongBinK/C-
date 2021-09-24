#pragma once
#include "BaseHeader.h"

#define BORDER_WIDTH 50
#define BORDER_HEIGHT 30

class DrawManager
{
public:
	DrawManager();
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void DrawMidText_int(string str, int num, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawBorders(int Width, int Height, string WallShape);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~DrawManager();
};

