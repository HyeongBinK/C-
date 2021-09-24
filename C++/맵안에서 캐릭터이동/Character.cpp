#include "Character.h"

Character::Character()
{
}

void Character::SetCharcaterBaseLoaction(int Start_x, int Start_y, int Width, int Height)
{
	m_iStart_x = Start_x;
	m_iStart_y = Start_y;
	m_iWidth = Width;
	m_iHeight = Height;

	int XPlusPoint = Width;
	if (Start_x <= Width)
	{
		while ((Start_x + XPlusPoint) * 2 > Start_x + Width + 1)
		{
			XPlusPoint /= 2;
		}
	}
	if (Start_x > Width)
	{
		while ((Start_x + XPlusPoint) * 2 > Start_x + Width + 1)
			XPlusPoint -= 2;
	}
	
	m_iXCharcterLocation = (Start_x + XPlusPoint); 
	m_iYCharcterLocation = (Start_y +Height/2);

	if (m_iStart_x % 2 != 0)
		m_iXCharcterLocation += 1;
}

void Character :: DrawCharacter()
{
	m_DrawManager.DrawPoint("¡Ú", m_iXCharcterLocation, m_iYCharcterLocation);
}

void Character::MoveCharacter()
{
	char ch = NULL;

	

	while (ch != ESC)
	{
		ch = getch();


		m_DrawManager.gotoxy(m_iXCharcterLocation * 2, m_iYCharcterLocation);
		switch (ch)
		{
		case LEFT:
			if (m_iXCharcterLocation - 1 > m_iStart_x / 2)
			{
				m_iXCharcterLocation--;
				EraseCharacter(m_iXCharcterLocation + 1, m_iYCharcterLocation);
				DrawCharacter();
			}
			break;
		case RIGHT:
			if (m_iXCharcterLocation + 1 < m_iStart_x / 2 + m_iWidth - 1)
			{
				m_iXCharcterLocation++;
				EraseCharacter(m_iXCharcterLocation - 1, m_iYCharcterLocation);
				DrawCharacter();
			}
			break;
		case UP:
			if (m_iYCharcterLocation - 1 > m_iStart_y)
			{
				m_iYCharcterLocation--;
				EraseCharacter(m_iXCharcterLocation, m_iYCharcterLocation + 1);
				DrawCharacter();
			}
			break;
		case DOWN:
			if (m_iYCharcterLocation + 1 < m_iStart_y + m_iHeight - 1)
			{
				m_iYCharcterLocation++;
				EraseCharacter(m_iXCharcterLocation, m_iYCharcterLocation - 1);
				DrawCharacter();
			}
			break;

		}

	}
	system("cls");
		return;
	
}

void Character::EraseCharacter(int XCharcterLocation, int YCharcterLocation)
{
	m_DrawManager.ErasePoint(XCharcterLocation, YCharcterLocation);
}


Character::~Character()
{
}
