#include "Character.h"

Character::Character()
{
}

void Character::FirstDataInpit(string CursorShape, string Stone, int Width, int Height)
{
	m_strCursor = CursorShape;
	m_strStone = Stone;
	m_iUndoCount = 5;
	m_iMemoUndoCount = m_iUndoCount;
	m_iWidth = Width;
	m_iHeight = Height;
	Cursor.m_iLocationX = Width*0.5f;
	Cursor.m_iLocationY = Height*0.5f;
	m_iStoneMax = Width*Height*0.5f;
	m_iStoneCount = 0;
	SaveStone = new Position[m_iStoneMax];
}

//신규 승리체크코드 축입력해서 체크하는 코드
bool Character::VictoryFlag2()
{
	if(CheckVictory2(SaveStone[m_iStoneCount - 1].m_iLocationX, SaveStone[m_iStoneCount - 1].m_iLocationY, 0, 1))
	return true;
	else if(CheckVictory2(SaveStone[m_iStoneCount - 1].m_iLocationX, SaveStone[m_iStoneCount - 1].m_iLocationY, 1, 0))
	return true;
	else if (CheckVictory2(SaveStone[m_iStoneCount - 1].m_iLocationX, SaveStone[m_iStoneCount - 1].m_iLocationY, 1, 1))
	return true;
	else if(CheckVictory2(SaveStone[m_iStoneCount - 1].m_iLocationX, SaveStone[m_iStoneCount - 1].m_iLocationY, 1, -1))
	return true;
	else
	return false;
}

//새로작성한 승리체크코드
bool Character::CheckVictory2(int x, int y, int AddX, int AddY)
{
	int StoneCheckCount = 0;
	int EndWhile = 0;
	int MemoBeforeCount;

	while (EndWhile != 2)
	{
		for (x += AddX, y += AddY; x >= 0 && x < m_iWidth && y >= 0 && y < m_iHeight; x += AddX, y += AddY)
		{
			MemoBeforeCount = StoneCheckCount;

			for (int i = 0; i < m_iStoneCount; i++)
			{
				if (x == SaveStone[i].m_iLocationX && y == SaveStone[i].m_iLocationY)
					StoneCheckCount++;
			}
			if (MemoBeforeCount == StoneCheckCount)
				break;
		}
		x -= AddX*StoneCheckCount;
		y -= AddY*StoneCheckCount;
		AddX *= -1;
		AddY *= -1;
		EndWhile++;
	}
	if (StoneCheckCount == 5)
		return true;
	else
		return false;
}



bool Character::CheckStone(int x, int y)
{
	for (int i = 0; i < m_iStoneCount; i++)
	{
		if (x == SaveStone[i].m_iLocationX)
		{
			if (y == SaveStone[i].m_iLocationY)
				return true;
		}
	}

	return false;
}

void Character::SetStone(int x, int y)
{
	SaveStone[m_iStoneCount].m_iLocationX = x;
	SaveStone[m_iStoneCount].m_iLocationY = y;
	m_iStoneCount++;
}

void Character::ChangeMap(int Width, int Height)
{
	m_iWidth = Width;
	m_iHeight = Height;

	Cursor.m_iLocationX = Width*0.5f;
	Cursor.m_iLocationY = Height*0.5f;

	m_iStoneMax = Width*Height*0.5f;
	m_iStoneCount = 0;
	m_iUndoCount = m_iMemoUndoCount;

	if (SaveStone != NULL)
		delete SaveStone;
	SaveStone = new Position[m_iStoneMax];
	
}

void Character::CharacterPlay(Character* EnemyStone, char* ch, int GameTurn, bool* VictoryCheck)
{
	bool CheckStoneFlag = true;
	
	
	while (1)
	{
		m_DrawManager.DrawPoint(m_strCursor, Cursor.m_iLocationX, Cursor.m_iLocationY);
	

		*ch = getch();

		m_DrawManager.ErasePoint(Cursor.m_iLocationX, Cursor.m_iLocationY);

		if (CheckStoneFlag == CheckStone(Cursor.m_iLocationX, Cursor.m_iLocationY))
			m_DrawManager.DrawPoint(m_strStone, Cursor.m_iLocationX, Cursor.m_iLocationY);

		else if(CheckStoneFlag == EnemyStone->CheckStone(Cursor.m_iLocationX, Cursor.m_iLocationY))
			m_DrawManager.DrawPoint(EnemyStone->GetStoneShape(), Cursor.m_iLocationX, Cursor.m_iLocationY);
		
		else
			m_DrawManager.LostSpaceDraw(Cursor.m_iLocationX, Cursor.m_iLocationY, m_iWidth, m_iHeight);

		switch (*ch)
		{
		case KEY_LEFT:
		case KEY_LEFT2:
			if (Cursor.m_iLocationX - 1 >= 0)
				Cursor.m_iLocationX--;
			break;
		case KEY_RIGHT:
		case KEY_RIGHT2:
			if (Cursor.m_iLocationX + 1 < m_iWidth)
				Cursor.m_iLocationX++;
			break;
		case KEY_UP:
		case KEY_UP2:
			if (Cursor.m_iLocationY - 1 >= 0)
				Cursor.m_iLocationY--;
			break;
		case KEY_DOWN:
		case KEY_DOWN2:
			if (Cursor.m_iLocationY + 1 < m_iHeight)
				Cursor.m_iLocationY++;
			break;
		case KEY_N:
		case KEY_SMALL_N:
			if (GameTurn == 1)
				break;
			if (m_iUndoCount == 0)
				break;
			else
			{
				m_DrawManager.ErasePoint(Cursor.m_iLocationX, Cursor.m_iLocationY);
				m_DrawManager.LostSpaceDraw(Cursor.m_iLocationX, Cursor.m_iLocationY, m_iWidth, m_iHeight);
				m_DrawManager.ErasePoint(EnemyStone->SaveStone[EnemyStone->GetStoneCount() -1].m_iLocationX, EnemyStone->SaveStone[EnemyStone->GetStoneCount() - 1].m_iLocationY);
				m_DrawManager.LostSpaceDraw(EnemyStone->SaveStone[EnemyStone->GetStoneCount() - 1].m_iLocationX, EnemyStone->SaveStone[EnemyStone->GetStoneCount() - 1].m_iLocationY, m_iWidth, m_iHeight);
				m_iUndoCount--;
				return;
			}
		case KEY_P:
		case KEY_SMALL_P:
			return;
		case KEY_ENTER:
			if (CheckStoneFlag == CheckStone(Cursor.m_iLocationX, Cursor.m_iLocationY))
				break;
			else if (CheckStoneFlag == EnemyStone->CheckStone(Cursor.m_iLocationX, Cursor.m_iLocationY))
				break;
			else
			{
				m_DrawManager.ErasePoint(Cursor.m_iLocationX, Cursor.m_iLocationY);
				SetStone(Cursor.m_iLocationX, Cursor.m_iLocationY);
				//SaveStoneFile(m_strCharacterName);
				*VictoryCheck = VictoryFlag2();
				m_DrawManager.DrawPoint(m_strStone, Cursor.m_iLocationX, Cursor.m_iLocationY);
				
				return;
			}
		case KEY_ESC:
			return;
		default:
			break;



		}

	}

}

void Character::SaveFile2(string SaveFileName)
{
	ofstream save;

	char buf[30];
	char cstr[20];
	char str[20] = ".txt";

	strcpy(cstr, SaveFileName.c_str());
	sprintf(buf, "%s%s", cstr, str);
	save.open(buf, ios::app);
	if (save.is_open())
	{
		save << m_strCharacterName << endl;
		save << m_strCursor << endl;
		save << m_strStone << endl;
		save << m_iUndoCount << endl;
		save << m_iStoneMax << endl;
		save << m_iStoneCount << endl;
		save << m_iWidth << endl;
		save << m_iHeight << endl;

		for (int i = 0; i < m_iStoneCount; i++)
		{
			save << SaveStone[i].m_iLocationX << endl;

			save << SaveStone[i].m_iLocationY << endl;
		}

		save << "END" << endl;
		save.close();
	}
}

void Character::LoadFile2(ifstream& load )
{
	string str;

	while (!load.eof())
	{
		load >> m_strCharacterName;
		load >> m_strCursor;
		load >> m_strStone;
		load >> m_iUndoCount;
		load >> m_iStoneMax;
		load >> m_iStoneCount;
		load >> m_iWidth;
		load >> m_iHeight;

		for (int i = 0; i < m_iStoneCount; i++)
		{
			load >> SaveStone[i].m_iLocationX;
			load >> SaveStone[i].m_iLocationY;
		}

		load >> str;
		if (str == "END")
			break;
	}

	
}


//이전코드 : 돌하나하나 txt파일로저장,로드함


// 돌위치 정보 재외한 정보 저장
void Character::SaveFile(string Player)
{
	ofstream save;

	char buf[20];
	char str[20] = "OMOCDATA.txt";
	char cstr[20];

	strcpy(cstr, Player.c_str());

	sprintf(buf, "%s의%s", cstr, str);
	save.open(buf);

	if (save.is_open())
	{
		save << m_strCharacterName << endl;
		save << m_strCursor << endl;
		save << m_strStone << endl;
		save << m_iUndoCount << endl;
		save << m_iStoneMax << endl;
		save << m_iStoneCount;
		save.close();
	}

}

void Character::SaveStoneFile(string Player)
{
	ofstream save;

	char buf[20];
	char buf2[30];

	char str[20] = "번쨰StoneData.txt";
	char cstr[20];

	strcpy(cstr, Player.c_str());

	sprintf(buf, "%d%s", m_iStoneCount, str);
	sprintf(buf2, "%s의%s", cstr, buf);

	save.open(buf2);
	if (save.is_open())
	{
		save << SaveStone[m_iStoneCount - 1].m_iLocationX << endl;
		save << SaveStone[m_iStoneCount - 1].m_iLocationY;
	}
	save.close();
}

void Character::LoadFile(string Player)
{
	ifstream load;

	string stonemax, stonecount, charactername, cursor, stone, undo;
	

	char buf[30];
	char str[20] = "OMOCDATA.txt";
	char cstr[20];

	strcpy(cstr, Player.c_str());

		sprintf(buf, "%s의%s", cstr, str);
		
		load.open(buf);

		while (!load.eof())
		{
			getline(load, charactername);
			getline(load, cursor);
			getline(load, stone);
			getline(load, undo);
			getline(load, stonemax);
			getline(load, stonecount);
		}

		m_strCharacterName = charactername;
		m_strCursor = cursor;
		m_strStone = stone;
		m_iUndoCount = atoi(undo.c_str());
		m_iStoneMax = atoi(stonemax.c_str());
		m_iStoneCount = atoi(stonecount.c_str());
}

void::Character::LoadStoneFile(string Player, int StoneNum)
{
	ifstream load;
	
	char buf[20];
	char buf2[30];

	char str[20] = "번쨰StoneData.txt";
	char cstr[20];

	strcpy(cstr, Player.c_str());
	sprintf(buf, "%d%s", StoneNum, str);
	sprintf(buf2, "%s의%s", cstr, buf);

	load.open(buf2);

	string X, Y;

	while (!load.eof())
	{
			getline(load, X);
			getline(load, Y);
	}
		
	
	SaveStone[StoneNum - 1].m_iLocationX = atoi(X.c_str());
	SaveStone[StoneNum - 1].m_iLocationY = atoi(Y.c_str());
	
}





Character::~Character()
{
	if (SaveStone != NULL)
		delete SaveStone;
}
