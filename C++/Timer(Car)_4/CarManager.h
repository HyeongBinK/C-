#pragma once
#include"BaseHeader.h"
#include"DrawManager.h"
#include"Car.h"

#define CARMAKECOOLTIME 3000

class CarManager
{
private:
	int m_iCarMakeTime;
	DrawManager D_M;
	list<Car> CARS;
	int m_iCarMake_Clock;
	
public:
	CarManager();
	//�������� �ð������ �������� ��ġ���
	void MakeCar(); //������
	void MoveCars(); //���̵�
	void DeleteCar(); //������
	void CarSpeedChange(); //Space �Է½� ���ӵ��� ����������� ������ ������ �ٲ��.
	void ClearCar(); //����� ��� ������ ����

	~CarManager();
};

