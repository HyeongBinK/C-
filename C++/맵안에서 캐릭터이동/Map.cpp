#include "Map.h"

Map::Map()
{
	cout << "¸Ê x ÀÔ·Â : ";
	cin >> m_ix;
	cout << "¸Ê y ÀÔ·Â : ";
	cin >> m_iy;
	cout << "¸Ê °¡·Î ±æÀÌ ÀÔ·Â : ";
	cin >> m_iWidth;
	cout << "¸Ê ¼¼·Î ±æÀÌ ÀÔ·Â : ";
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
