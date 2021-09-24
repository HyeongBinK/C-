#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Character.h"

#define ENDCODEON 999
#define ENDCODEOFF 0

#define WIDTHMAX 90
#define WIDTHMIN 20
#define HEIGHTMAX 45
#define HEIGHTMIN 20
#define REFLAGON 1000

class GameManager
{
private:
	int m_ix;
	int m_iy;
	int m_iWidth;
	int m_iHeight;

	int m_iGameTurn;
	MapDraw m_DrawManager;

	Character m_Player[2];

public:
	GameManager();
	void GamePlay();
	void CursorSet(int num);
	void StoneSet(int num);
	void ShowGameRuleAndStatus(Character* character);
	void SelectList();
	void OptionList(char ch);
	void SetUndo();
	void ChangeUndo();
	void CharacterNameInput();
	void ShowGameVictory(string str);
	void SelectCursorAndStoneList(int num);
	void NewMapSize();
	void ChangeMapSize(int NewWidth, int NewHeight);
	
	//맵초기화후 맵다시그리기
	void ReDrawMap();

	//이어하기or 다시하기 선택함수
	void GameNewPlayorRePlay();
	//리플레이 함수
	void ShowRePlay();
	//맵크기저장함수
	void SaveMapSize(string FileName);
	//맵크기불러오기함수
	void LoadMapSize(string FileName);
	
	//게임저장함수
	void SaveGame(string FileName);
	//게임불러오기함수
	void LoadGame(string FileName);
	
	~GameManager();
};

