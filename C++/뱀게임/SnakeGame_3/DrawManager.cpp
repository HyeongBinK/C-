#include "DrawManager.h"

DrawManager::DrawManager()
{
}

void DrawManager::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << " ";
	return;
}

void DrawManager::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	return;
}

void DrawManager::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void DrawManager::DrawMidText_int(string str, int num, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str << num;
	return;
}

void DrawManager::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void DrawManager::DrawBorders(int Width, int Height, string WallShape)
{
	for (int i = 0; i < Height; i++)
	{
		cout << WallShape;
		for (int j = 0; j < Width - 2; j++)
		{
			if (i == 0 || i == Height - 1)
				cout << WallShape;
			else
				cout << "  ";

		}
		cout << WallShape << endl;
	}
}

DrawManager::~DrawManager()
{
}
