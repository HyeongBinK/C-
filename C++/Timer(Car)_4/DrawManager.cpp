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

void DrawManager::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void DrawManager::DrawCar(int x)
{
	gotoxy(x, CAR_BASE_LOCATION_Y);
	cout << "  ¦£¦¡¦¡¦¤  " ;
	gotoxy(x, CAR_BASE_LOCATION_Y +1);
	cout << "¦£¦¥    ¦¦¦¤" ;
	gotoxy(x, CAR_BASE_LOCATION_Y +2);
	cout << "¦¦¡Ý¦¡¦¡¡Ý¦¥";

}

void DrawManager::EraseCar(int x)
{
	gotoxy(x, CAR_BASE_LOCATION_Y);
	cout << "            ";
	gotoxy(x, CAR_BASE_LOCATION_Y + 1);
	cout << "            ";
	gotoxy(x, CAR_BASE_LOCATION_Y + 2);
	cout << "            ";
}

DrawManager::~DrawManager()
{
}
