#include "CarManager.h"

CarManager::CarManager()
{
	m_iCarMakeTime = CARMAKECOOLTIME;
	m_iCarMake_Clock = clock();
}

void CarManager::MakeCar()
{
	//���ӸŴ����� Ÿ���Լ��� �̿��� �ð����� ���Լ��� �ҷ��� ������
	if (clock() - m_iCarMake_Clock > m_iCarMakeTime)
	{
		Car car;
		CARS.push_back(car);
		m_iCarMake_Clock = clock();
	}
}

void CarManager::MoveCars()
{
	//Car �� x ��ǥ����(++)�� ���� ����
	for (auto iter = CARS.begin(); iter != CARS.end(); iter++)
	{
		iter->MoveCar();
	}
}

void CarManager::DeleteCar()
{
	for (auto iter = CARS.begin(); iter != CARS.end(); iter++)
	{
		if(iter->EraseCar() == true)
			iter = CARS.erase(iter);
		
	}
}

void CarManager::CarSpeedChange()
{
	//���Ӹ޴�������  �����̽��Է¹ް� ��� ī�� �ӵ� ����ǰԲ�
	for (auto iter = CARS.begin(); iter != CARS.end(); iter++)
	{
		iter->SpeedChange();
	}
}

void CarManager::ClearCar()
{
	CARS.clear();
}

CarManager::~CarManager()
{
}
