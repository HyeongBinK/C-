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

//�����������Ұ�
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

	//�����ִ��� üũ�ϴ� �Լ�
	inline bool CheckStone(int x, int y);
	//�ʻ�������� ���ʱ����������Լ�
	void ChangeMap(int x, int y);

	//�ʱ����� �Է��Լ�
	void FirstDataInpit(string Cursor, string Stone, int Width, int Height);

	void SetStone(int x, int y);
	void CharacterPlay(Character* EnemyStone, char* ch, int GameTurn, bool* VictoryCheck);
	
	//�¸�üũ�Լ�
	bool VictoryFlag2();
	bool CheckVictory2(int x, int y, int AddX, int AddY);

	//����ġ���������Լ�
	void SaveStoneFile(string Player);
	// ����ġ ���� ����� ���� ����
	void SaveFile(string Player);
	//����ġ�����ҷ������Լ�
	void LoadStoneFile(string Player, int StoneNum);
	//����ġ ���� ����� ���� �ҷ����� �Լ�
	void LoadFile(string Player);

	//������ �ϰ� �����Լ�
	void SaveFile2(string SaveFileName);
	//������ �ϰ� �ε��Լ�
	void LoadFile2(ifstream& load);

	inline string GetCharacterName()
	{
		return m_strCharacterName;
	}

	inline int GetUndoCount()
	{
		return m_iUndoCount;
	}

	//�����������
	inline Position* ExportStoneLocation()
	{
		return SaveStone;
	}

	//�̹��� ������ ����
	inline Position GetStoneLocation()
	{
		return SaveStone[m_iStoneCount];
	}

	//��X��ǥ����
	inline int GetXLocation(int i)
	{
		return SaveStone[i].m_iLocationX;
	}
	//��Y��ǥ ����
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
	//�������Լ�
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

