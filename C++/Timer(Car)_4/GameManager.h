#pragma once
#include"BaseHeader.h"
#include"CarManager.h"
#include"DrawManager.h"

#define PAUSEKEY 65
#define ESC 27
#define SPACE 32

class GameManager
{
private:
	CarManager C_M;
	DrawManager D_M;
public:
	GameManager();
	void KeyMenu();//조작키설명
	void PlayGame(); //전체진행
	~GameManager();
};

