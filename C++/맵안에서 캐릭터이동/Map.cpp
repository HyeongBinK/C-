#include "Map.h"

Map::Map()
{
	cout << "�� x �Է� : ";
	cin >> m_ix;
	cout << "�� y �Է� : ";
	cin >> m_iy;
	cout << "�� ���� ���� �Է� : ";
	cin >> m_iWidth;
	cout << "�� ���� ���� �Է� : ";
	cin >> m_iHeight;
}

void Map::MapDraw()
{
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	CharacterSet();
	m_CharacterManager.MoveCharacter();
}

void Map::CharacterSet()
{
	m_CharacterManager.SetCharcaterBaseLoaction(m_ix, m_iy, m_iWidth, m_iHeight);
	m_CharacterManager.DrawCharacter();
}

void Map::CharacterMove()
{
}




Map::~Map()
{
}
