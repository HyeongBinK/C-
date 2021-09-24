#include "Car.h"

Car::Car()
{
	//�ʱ���ġ�� �ʱ⽺�ǵ�
	m_iCar_X_Rotation = CARSTARTLOCATIONX;
	m_iCarSpeed = CARBASESPEED;
	m_iCarMove_Clock = clock();
}

void Car :: SpeedChange()
{
	if (m_iCarSpeed == CARBASESPEED)
		m_iCarSpeed = CARFASTSPEED;
	else
		m_iCarSpeed = CARBASESPEED;
}

void Car::MoveCar()
{
	if (clock() - m_iCarMove_Clock > m_iCarSpeed)
	{
		m_iCar_X_Rotation++;
		m_iCarMove_Clock = clock();
		D_M.DrawCar(m_iCar_X_Rotation);
	}		
}

bool Car::EraseCar()
{
	if (m_iCar_X_Rotation > CARDELETELOCATION)
	{
		D_M.EraseCar(m_iCar_X_Rotation);
		return true;
	}
	else
		return false;
}

Car::~Car()
{
}
