#pragma once
#include"BaseHeader.h"
#include"DrawManager.h"
#include"BlockManager.h"
#include"FoodManager.h"
#include"SnakeManager.h"

#define TEST_A 65

class GameManager
{
private:
	int m_iGameScore;
	DrawManager D_M;
	BlockManager B_M;
	FoodManager F_M;
	SnakeManager S_M;

public:
	GameManager();
	void StartMenu();
	void Game();
	void ShowGameScore();
	void GameOver();
	void GamePlay();
	void ReSetStatus();
	~GameManager();
};

