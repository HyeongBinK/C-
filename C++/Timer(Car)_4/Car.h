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
	int m_iCarSpeed; //Ÿ���� ��ġ�ϸ� ��ġ�����ϰԲ�
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

