#include "MapDraw.h"

MapDraw::MapDraw()
{
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << " ";
	return;
}

void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void MapDraw::DrawMap(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
				cout << "¦£";
				for (int x = 1; x < Width - 1; x++)
					cout << "¦¨";
				cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦ª";
			cout << "¦¥";
		}
		else
		{
			cout << "¦§";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦«";
			cout << "¦©";
		}
	}
}

void MapDraw::LostSpaceDraw(int x, int y, int Width, int Height)
{
	string str;
	
		if (y == 0)
		{
			if (x == 0)
				str = "¦£";
			else if (x == Width - 1)
				str = "¦¤";
			else
				str = "¦¨";

		}
		else if (y == Height - 1)
		{
			if (x == 0)
				str = "¦¦";
			else if (x == Width - 1)
				str = "¦¥";
			else
				str = "¦ª";
		}
		else
		{
			if(x == 0)
			str = "¦§";
			else if(x == Width -1)
			str = "¦©";
			else
			str = "¦«";
		}
		DrawPoint(str, x, y);
}

void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "¦¢";
		}
	}
}


MapDraw::~MapDraw()
{
}
