#include "CarManager.h"

CarManager::CarManager()
{
	m_iCarMakeTime = CARMAKECOOLTIME;
	m_iCarMake_Clock = clock();
}

void CarManager::MakeCar()
{
	//게임매니저의 타임함수를 이용해 시간별로 이함수를 불러와 차생성
	if (clock() - m_iCarMake_Clock > m_iCarMakeTime)
	{
		Car car;
		CARS.push_back(car);
		m_iCarMake_Clock = clock();
	}
}

void CarManager::MoveCars()
{
	//Car 의 x 좌표변경(++)를 통해 구현
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
	//게임메니저에서  스페이스입력받고 모든 카의 속도 변경되게끔
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
