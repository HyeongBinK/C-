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
	
	//���ʱ�ȭ�� �ʴٽñ׸���
	void ReDrawMap();

	//�̾��ϱ�or �ٽ��ϱ� �����Լ�
	void GameNewPlayorRePlay();
	//���÷��� �Լ�
	void ShowRePlay();
	//��ũ�������Լ�
	void SaveMapSize(string FileName);
	//��ũ��ҷ������Լ�
	void LoadMapSize(string FileName);
	
	//���������Լ�
	void SaveGame(string FileName);
	//���Ӻҷ������Լ�
	void LoadGame(string FileName);
	
	~GameManager();
};

