#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Character.h"

class Map
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;
	MapDraw m_DrawManager;
	Character m_CharacterManager;

public:
	void MapDraw();
	void CharacterSet();
	void CharacterMove();
	Map();
	~Map();
};

