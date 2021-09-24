#pragma once
#include"Mecro.h"
#include"MapDraw.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

class Character
{
private:
	int m_iXCharcterLocation, m_iYCharcterLocation;
	int m_iStart_x;
	int m_iStart_y;
	int m_iWidth;
	int m_iHeight;
	MapDraw m_DrawManager;
public:
	void SetCharcaterBaseLoaction(int Start_x, int Start_y, int Width, int Height);
	void DrawCharacter();
	void EraseCharacter(int XCharcterLocation, int YCharcterLocation);
	void MoveCharacter();

	Character();
	~Character();
};

