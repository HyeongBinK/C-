#pragma once
#include"BaseHeader.h"
#include"DrawManager.h"
#define CARSTARTLOCATIONX 1
#define CARBASESPEED 200
#define CARFASTSPEED 50
#define CARDELETELOCATION 100


class Car
{
private:
	int m_iCar_X_Rotation;
	int m_iCarSpeed; //타임이 일치하면 위치값변하게끔
	int m_iCarMove_Clock;
	DrawManager D_M;
public:
	Car();
	void SpeedChange();
	void MoveCar();
	bool EraseCar();

	inline int GetCar_X_Rotation()
	{
		return m_iCar_X_Rotation;
	}
	~Car();
};

