#pragma once
#include"Mecro.h"
#include"MapDraw.h"

enum KEY
{
	KEY_LEFT = 'A',
	KEY_LEFT2 = 'a',
	KEY_RIGHT = 'D',
	KEY_RIGHT2 = 'd',
	KEY_UP= 'W',
	KEY_UP2 = 'w',
	KEY_DOWN = 'S',
	KEY_DOWN2 = 's',
	KEY_ESC = 27,
	KEY_ENTER = 13,
	KEY_N = 78,
	KEY_SMALL_N = 110,
	KEY_P = 80,
	KEY_SMALL_P =112
};

#define MYSTONEFLAG 10
#define ENEMYSTONEFLAG 20
#define OMOCCLEAR 5

//돌정보저장할것
struct Position
{
	int m_iLocationX;
	int m_iLocationY;
};

class Character
{
private:
	int m_iWidth;
	int m_iHeight;

	//int m_iXCharcterLocation;
	//int m_iYCharcterLocation;

	int m_iUndoCount;
	int m_iMemoUndoCount;
	int m_iStoneMax;
	int m_iStoneCount;

	string m_strCharacterName;
	string m_strCursor;
	string m_strStone;
	
	MapDraw m_DrawManager;
	
	Position Cursor;
	Position* SaveStone;

public:
	Character();

	//돌이있는지 체크하는 함수
	inline bool CheckStone(int x, int y);
	//맵사이즈변경후 맵초기정보변경함수
	void ChangeMap(int x, int y);

	//초기정보 입력함수
	void FirstDataInpit(string Cursor, string Stone, int Width, int Height);

	void SetStone(int x, int y);
	void CharacterPlay(Character* EnemyStone, char* ch, int GameTurn, bool* VictoryCheck);
	
	//승리체크함수
	bool VictoryFlag2();
	bool CheckVictory2(int x, int y, int AddX, int AddY);

	//돌위치정보저장함수
	void SaveStoneFile(string Player);
	// 돌위치 정보 재외한 정보 저장
	void SaveFile(string Player);
	//돌위치정보불러오기함수
	void LoadStoneFile(string Player, int StoneNum);
	//돌위치 정보 재외한 정보 불러오기 함수
	void LoadFile(string Player);

	//돌정보 일괄 저장함수
	void SaveFile2(string SaveFileName);
	//돌정보 일괄 로드함수
	void LoadFile2(ifstream& load);

	inline string GetCharacterName()
	{
		return m_strCharacterName;
	}

	inline int GetUndoCount()
	{
		return m_iUndoCount;
	}

	//돌정보들송출
	inline Position* ExportStoneLocation()
	{
		return SaveStone;
	}

	//이번턴 돌정보 송출
	inline Position GetStoneLocation()
	{
		return SaveStone[m_iStoneCount];
	}

	//돌X좌표송출
	inline int GetXLocation(int i)
	{
		return SaveStone[i].m_iLocationX;
	}
	//돌Y좌표 송출
	inline int GetYLocation(int i)
	{
		return SaveStone[i].m_iLocationY;
	}

	inline int  GetStoneCount()
	{
		return m_iStoneCount;
	}

	inline string GetStoneShape()
	{
		return m_strStone;
	}

	inline void PlayerNameInput(string str)
	{
		m_strCharacterName = str;
	}

	inline void ChangeCursorShape(string str)
	{
		m_strCursor = str;
	}

	inline void ChangeStoneShape(string str)
	{
		m_strStone = str;
	}

	inline void ChangeUndoCount(int num)
	{
		m_iUndoCount = num;
		m_iMemoUndoCount = m_iUndoCount;

	}
	//무르기함수
	inline void Undo()
	{
		m_iStoneCount--;
	}

	inline int GetStoneMax()
	{
		return m_iStoneMax;
	}

	~Character();
};

