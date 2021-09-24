#include "GameManager.h"

GameManager::GameManager()
{
	m_ix = 0;
	m_iy = 0;
	m_iWidth = 20;
	m_iHeight = 20;
	m_iGameTurn = 1;
	m_Player[0].FirstDataInpit("○", "○", m_iWidth, m_iHeight);
	m_Player[1].FirstDataInpit("●", "●", m_iWidth, m_iHeight);
	int Width = (m_iWidth * 2) + 1;
	int Height = m_iHeight + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
}

void GameManager::GamePlay()
{
	m_DrawManager.DrawMap(m_ix, m_iy, m_iWidth, m_iHeight);
	ReDrawMap();
	bool GetVictoryFlag = false;
	bool CheckVictory = false;
	int EndCode = ENDCODEOFF;

	while (1)
	{
		char ch = NULL;

			for (int i = 0; i < 2; i++)
			{
				GetVictoryFlag = m_Player[i].VictoryFlag2();
				if (GetVictoryFlag == true)
				{
					ShowGameVictory(m_Player[i].GetCharacterName());
					EndCode = ENDCODEON;
					return;
				}
			}

			if (m_iGameTurn % 2 != 0)
			ShowGameRuleAndStatus(&m_Player[0]);
			else 
			ShowGameRuleAndStatus(&m_Player[1]);
			
			if(m_iGameTurn % 2 != 0)
				m_Player[0].CharacterPlay(&m_Player[1], &ch, m_iGameTurn, &CheckVictory);
			else
			m_Player[1].CharacterPlay(&m_Player[0], &ch, m_iGameTurn, &CheckVictory);

			if (CheckVictory == true)
			{
				if (m_iGameTurn % 2 != 0)
				ShowGameVictory(m_Player[0].GetCharacterName());
				else
				ShowGameVictory(m_Player[1].GetCharacterName());
				EndCode = ENDCODEON;
				SaveGame("RePlay");
				break;
			}

			if (ch == KEY_ESC)
			{
				EndCode = ENDCODEON;
				SaveGame("ContinueGame");
				break;
			}
			if (ch == KEY_ENTER)
			m_iGameTurn++;
			if (ch == KEY_P || ch == KEY_SMALL_P)
			{
				OptionList(ch);
				m_DrawManager.DrawMap(m_ix, m_iy, m_iWidth, m_iHeight);

				ReDrawMap();

			}

			if (ch == KEY_N || ch == KEY_SMALL_N)
			{
				if (m_iGameTurn >= 2)
				{
					m_iGameTurn--;
					if (m_iGameTurn % 2 != 0)
						m_Player[0].Undo();
					else
						m_Player[1].Undo();

					//ReDrawMap();
				}
			}
	}

		if (EndCode == ENDCODEON)
		{
			m_iGameTurn = 1;
			return;
		}
		
	
}

void GameManager::ReDrawMap()
{
	for (int z = 0; z < m_iHeight; z++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			int CheckStoneFlag = true;

			if (CheckStoneFlag == m_Player[0].CheckStone(z, j))
				m_DrawManager.DrawPoint(m_Player[0].GetStoneShape(), z, j);
			if (CheckStoneFlag == m_Player[1].CheckStone(z, j))
				m_DrawManager.DrawPoint(m_Player[1].GetStoneShape(), z, j);

		}
	}
}

void GameManager::ShowGameRuleAndStatus(Character* character)
{

	string GameTurn, UndoCount, CharacterName;

	CharacterName = character->GetCharacterName();
	UndoCount = to_string(character->GetUndoCount());
	GameTurn = to_string(m_iGameTurn);
	
	m_DrawManager.DrawMidText("====조작키====", m_ix + m_iWidth, m_iy + m_iHeight);
	m_DrawManager.DrawMidText("이동 : 좌A우D상W하S 돌놓기 : ENTER", m_ix + m_iWidth, m_iy + m_iHeight + 1);
	m_DrawManager.DrawMidText("무르기 : N 옵션 : P 종료 : ESC", m_ix + m_iWidth, m_iy + m_iHeight + 2);
	m_DrawManager.DrawMidText("Player Name :       무르기 :   ", m_ix + m_iWidth, m_iy + m_iHeight + 3);
	m_DrawManager.TextDraw(CharacterName, m_ix + m_iWidth, m_iy + m_iHeight + 3);
	m_DrawManager.TextDraw(UndoCount, m_ix + m_iWidth + 14, m_iy + m_iHeight + 3);
	m_DrawManager.DrawMidText("Turn : ", m_ix + m_iWidth, m_iy + m_iHeight + 4);
	m_DrawManager.TextDraw(GameTurn, m_ix + m_iWidth + 5, m_iy + m_iHeight + 4);

	
}

void GameManager::GameNewPlayorRePlay()
{
	int num;

	m_DrawManager.DrawMap(m_ix, m_iy, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("1.처음부터 시작하기", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
	m_DrawManager.DrawMidText("2.이어하기", m_ix + m_iWidth, m_iy + m_iHeight / 2);
	m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
	cin >> num;

	switch (num)
	{
	case 1:
		CharacterNameInput();
		GamePlay();
		break;

	case 2:
		/*LoadMapSize("MapSize.txt");
		m_Player[0].LoadFile2("0P");
		m_Player[1].
		
		
		("1P");*/

		LoadGame("ContinueGame");
		m_iGameTurn = m_Player[0].GetStoneCount() + m_Player[1].GetStoneCount() + 1;
		GamePlay();
		break;

	default :
		return;
	}


}

void GameManager::ShowRePlay()
{
	/*LoadMapSize("re.MapSize.txt");
	m_Player[0].LoadFile2("0P.re");
	m_Player[1].LoadFile2("1P.re");*/
	
	LoadGame("RePlay");

	bool CheckVictory0 = false, CheckVictory1 = false;
	
	m_iGameTurn = 1;

	m_DrawManager.DrawMap(m_ix, m_iy, m_iWidth, m_iHeight);
	
	int i = 0, j = 0;

	while (1)
	{
		
		m_DrawManager.DrawPoint(m_Player[0].GetStoneShape(), m_Player[0].GetXLocation(i), m_Player[0].GetYLocation(i));
		ShowGameRuleAndStatus(&m_Player[0]);
		m_iGameTurn++;
		Sleep(1000);
		i++;
		
		if (i >= m_Player[0].GetStoneCount() && j >= m_Player[1].GetStoneCount())
			break;

		m_DrawManager.DrawPoint(m_Player[1].GetStoneShape(), m_Player[1].GetXLocation(j), m_Player[1].GetYLocation(j));
		ShowGameRuleAndStatus(&m_Player[1]);
		m_iGameTurn++;
		Sleep(1000);
		j++;

		if (i >= m_Player[0].GetStoneCount() && j >= m_Player[1].GetStoneCount())
			break;
		
	}

	
	CheckVictory0 = m_Player[0].VictoryFlag2();
	if (CheckVictory0 == true)
	{
		ShowGameVictory(m_Player[0].GetCharacterName());
		m_iGameTurn = 1;
		return;
	}
	CheckVictory1 = m_Player[1].VictoryFlag2();
	if (CheckVictory1 == true)
	{
		ShowGameVictory(m_Player[1].GetCharacterName());
		m_iGameTurn = 1;
		return;
	}
}

void GameManager::SaveGame(string FileName)
{
	ofstream save;

	char buf[30];
	char cstr[20];
	char str[20] = ".txt";

	strcpy(cstr, FileName.c_str());
	sprintf(buf, "%s%s", cstr, str);

	save.open(buf);
	{
		save << m_iWidth << endl;
		save << m_iHeight << endl;
		m_Player[0].SaveFile2(FileName);
		m_Player[1].SaveFile2(FileName);
		

		save.close();
	}

}

void GameManager::LoadGame(string FileName)
{
	ifstream load;
	char buf[30];
	char str[20] = ".txt";
	char cstr[20];
	strcpy(cstr, FileName.c_str());
	sprintf(buf, "%s%s", cstr, str);

	load.open(buf);

	while (!load.eof())
	{
		load >> m_iWidth;
		load >> m_iHeight;
		//ChangeMapSize(m_iWidth, m_iHeight);

		m_Player[0].LoadFile2(load);
		m_Player[1].LoadFile2(load);

		int Width = (m_iWidth * 2) + 1;
		int Height = m_iHeight + 5;
		char buf[256];
		sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
		system(buf);
	}

}

//이전 맵사이즈 저장불러오기 함수(안씀)
void GameManager::SaveMapSize(string FileName)
{
	ofstream save;
	char cstr[20];

	strcpy(cstr, FileName.c_str());
	save.open(cstr);

	if (save.is_open())
	{
		save << m_iWidth << endl;
		save << m_iHeight;
		save.close();
	}
}

void GameManager::LoadMapSize(string FileName)
{
	ifstream load;

	string Width, Height;

	char cstr[20];

	strcpy(cstr, FileName.c_str());

	int NewWidth, NewHeight;
	load.open(cstr);

	while (!load.eof())
	{
		getline(load, Width);
		getline(load, Height);

	}
	NewWidth = atoi(Width.c_str());
	NewHeight = atoi(Height.c_str());
	ChangeMapSize(NewWidth, NewHeight);

}

void GameManager::SelectList()
{
	while (1)
	{
		string str;
		char ch = 0;
		system("cls");

		m_DrawManager.DrawMap(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("★ 오목 ★", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 5);
		m_DrawManager.DrawMidText("1.게임 시작", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 3);
		m_DrawManager.DrawMidText("2.옵션 설정", m_ix + m_iWidth, m_iy + m_iHeight / 2  - 1);
		m_DrawManager.DrawMidText("3.이전 게임 RePlay보기", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 1);
		m_DrawManager.DrawMidText("4.게임 종료", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 3);
		m_DrawManager.DrawMidText("┌───────────┐", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 5);
		m_DrawManager.DrawMidText("└───────────┘", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 7);
		m_DrawManager.DrawMidText("│                      │", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 6);
	
		m_DrawManager.TextDraw(str, m_ix + m_iWidth, m_iy + m_iHeight / 2 + 6);
		cin >> str;
		int iNewstr = atoi(str.c_str());
		switch (iNewstr)
		{
		case 1:
			GameNewPlayorRePlay();
			m_Player[0].ChangeMap(m_iWidth, m_iHeight);
			m_Player[1].ChangeMap(m_iWidth, m_iHeight);
			break;
		case 2:
			OptionList(ch);
			break;
		case 3:
			ShowRePlay();
			m_Player[0].ChangeMap(m_iWidth, m_iHeight);
			m_Player[1].ChangeMap(m_iWidth, m_iHeight);
			break;
		case 4:
			return;
		default:
			break;

		}

	}
}

void GameManager::ChangeUndo()
{
	while (1)
	{
		string str;
		system("cls");
		m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("무르기 횟수 입력(최대 10회)", m_ix + m_iWidth, m_iy + m_iHeight / 2);
		m_DrawManager.TextDraw(str, m_ix + m_iWidth + 15, m_iy + m_iHeight / 2);
		cin >> str;
		int iNewstr = atoi(str.c_str());
		
		if (iNewstr >= 0 && iNewstr <= 10)
		{
			m_Player[0].ChangeUndoCount(iNewstr);
			m_Player[1].ChangeUndoCount(iNewstr);
			return;
		}
		else 
			m_DrawManager.DrawMidText("범위가 맞지 않습니다(0~10)", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
	}
}

void GameManager::SetUndo()
{
	while (1)
	{
		string str;
		system("cls");

		m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("= Set Undo =", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 4);
		m_DrawManager.DrawMidText("1.Set Undo Count", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
		m_DrawManager.DrawMidText("2.Undo Off", m_ix + m_iWidth, m_iy + m_iHeight / 2);
		m_DrawManager.DrawMidText("3.Return", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
		m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 4);
		m_DrawManager.TextDraw(str, m_ix + m_iWidth + 3, m_iy + m_iHeight / 2 + 4);
		
		cin>>str;

		int iNewstr = atoi(str.c_str());

		switch (iNewstr)
		{
		case 1:
			ChangeUndo();
			break;
		case 2:
			m_Player[0].ChangeUndoCount(0);
			m_Player[1].ChangeUndoCount(0);
			break;
		case 3:
			return;
		default:
			break;
		}

	}
}

void GameManager::CharacterNameInput()
{
	string str1, str2;

	system("cls");
	m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
	m_DrawManager.DrawMidText("P1 이름", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 5);
	m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 -4);
	m_DrawManager.TextDraw(str1, m_ix + m_iWidth + 3, m_iy + m_iHeight / 2 - 4);
	cin >> str1;
	m_DrawManager.DrawMidText("P2 이름", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 3);
	m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 4);
	m_DrawManager.TextDraw(str2, m_ix + m_iWidth + 3, m_iy + m_iHeight / 2 + 4);
	cin >> str2;
	m_Player[0].PlayerNameInput(str1);
	m_Player[1].PlayerNameInput(str2);
}


void GameManager::OptionList(char ch)
{
	while (1)
	{
		string str;
		system("cls");
		m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("= Option =", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 6);
		m_DrawManager.DrawMidText("1.Map Size Set", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 4);
		m_DrawManager.DrawMidText("2.Cursor Custom", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
		m_DrawManager.DrawMidText("3.Stone Custom", m_ix + m_iWidth, m_iy + m_iHeight / 2);
		m_DrawManager.DrawMidText("4.Undo Count Set", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
		m_DrawManager.DrawMidText("5.Return", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 4);
		m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 6);

		m_DrawManager.TextDraw(str, m_ix + m_iWidth + 3, m_iy + m_iHeight / 2 + 6);
		cin >> str;

		int iNewstr = atoi(str.c_str());
		
		if (ch != 0)
		{
			if (iNewstr == 1 || iNewstr == 4)
			{
				system("cls");
				m_DrawManager.DrawMidText("접근 불가능", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
				m_DrawManager.DrawMidText("(Game Play중)", m_ix + m_iWidth, m_iy + m_iHeight / 2);
				m_DrawManager.DrawMidText(" ", m_ix + m_iWidth - 19, m_iy + m_iHeight / 2 + 2);
				system("pause");
				continue;
			}
		}

		switch (iNewstr)
		{
		case 1:
			NewMapSize();
			break;
		case 2:
		case 3:
			SelectCursorAndStoneList(iNewstr);
			break;
		case 4:
			SetUndo();
			break;
		case 5:

			return;
		default:
				break;

		}
	}
}

void GameManager::SelectCursorAndStoneList(int num)
{
		string str;
		system("cls");
		m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("= Set Cursor or Stone =", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 6);
		m_DrawManager.DrawMidText("1.○,●", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 4);
		m_DrawManager.DrawMidText("2.♡,♥", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
		m_DrawManager.DrawMidText("3.☞,☜", m_ix + m_iWidth, m_iy + m_iHeight / 2);
		m_DrawManager.DrawMidText("4.①,②", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
		m_DrawManager.DrawMidText("5.Return", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 4);
		m_DrawManager.DrawMidText("입력 : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 6);

		m_DrawManager.TextDraw(str, m_ix + m_iWidth + 3, m_iy + m_iHeight / 2 + 6);
		cin >> str;
		int iNewstr = atoi(str.c_str());
		
		if (iNewstr >= 5)
			return;
		if (num == 2)
			CursorSet(iNewstr);
		if (num == 3)
			StoneSet(iNewstr);
}

void GameManager::ShowGameVictory(string str)
{
	string str2 = "팀 승리!!";
	str += str2;

	m_DrawManager.DrawMidText(str, m_ix + m_iWidth, m_iy + m_iHeight / 2);
	m_DrawManager.DrawMidText(" ", m_ix + m_iWidth - 19, m_iy + m_iHeight / 2 + 2);
	system("pause");
}

void GameManager::NewMapSize()
{
	bool b = false;

	while (b == false)
	{
		string strNewWidth, strNewHeight;

		system("cls");
		m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
		m_DrawManager.DrawMidText("Width : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
		m_DrawManager.TextDraw(strNewWidth, m_ix + m_iWidth + 5, m_iy + m_iHeight / 2 - 2);
		cin >> strNewWidth;
		m_DrawManager.DrawMidText("Height : ", m_ix + m_iWidth, m_iy + m_iHeight / 2 + 2);
		m_DrawManager.TextDraw(strNewHeight, m_ix + m_iWidth + 5, m_iy + m_iHeight / 2 + 2);
		cin >> strNewHeight;

		int iNewWidth = atoi(strNewWidth.c_str());
		int iNewHeight = atoi(strNewHeight.c_str());

		if (iNewWidth >= WIDTHMIN && iNewWidth <= WIDTHMAX)
		{
			if (iNewHeight >= HEIGHTMIN && iNewHeight <= HEIGHTMAX)
			{
				ChangeMapSize(iNewWidth, iNewHeight);
				b = true;
				return;
			}
		}
		system("cls");
			m_DrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
			m_DrawManager.DrawMidText("변경불가능", m_ix + m_iWidth, m_iy + m_iHeight / 2 - 2);
			m_DrawManager.DrawMidText("가로 : 20~90, 세로 : 20~45", m_ix + m_iWidth, m_iy + m_iHeight / 2);
			m_DrawManager.DrawMidText(" ", m_ix + m_iWidth - 19, m_iy + m_iHeight / 2 + 2);
			system("pause");
	}
}

void GameManager::ChangeMapSize(int NewWidth, int NewHeight)
{
	m_iWidth = NewWidth;
	m_iHeight = NewHeight;

	int Width = (m_iWidth * 2) + 1;
	int Height = m_iHeight + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);

	m_Player[0].ChangeMap(m_iWidth, m_iHeight);
	m_Player[1].ChangeMap(m_iWidth, m_iHeight);
}


void GameManager::CursorSet(int num)
{

	switch (num)
	{
	case 1:
		m_Player[0].ChangeCursorShape("○");
		m_Player[1].ChangeCursorShape("●");

		break;
	case 2:
		m_Player[0].ChangeCursorShape("♡");
		m_Player[1].ChangeCursorShape("♥");

		break;
	case 3:
		m_Player[0].ChangeCursorShape("☞");
		m_Player[1].ChangeCursorShape("☜");

		break;
	case 4:
		m_Player[0].ChangeCursorShape("①");
		m_Player[1].ChangeCursorShape("②");

		break;
	}

}

void GameManager::StoneSet(int num)
{
	switch (num)
	{
	case 1:
		m_Player[0].ChangeStoneShape("○");
		m_Player[1].ChangeStoneShape("●");

		break;
	case 2:
		m_Player[0].ChangeStoneShape("♡");
		m_Player[1].ChangeStoneShape("♥");

		break;
	case 3:
		m_Player[0].ChangeStoneShape("☞");
		m_Player[1].ChangeStoneShape("☜");

		break;
	case 4:
		m_Player[0].ChangeStoneShape("①");
		m_Player[1].ChangeStoneShape("②");

		break;
	}

}



GameManager::~GameManager()
{
}
