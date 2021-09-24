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
	//차생성은 시간에기반 차삭제는 위치기반
	void MakeCar(); //차생성
	void MoveCars(); //차이동
	void DeleteCar(); //차삭제
	void CarSpeedChange(); //Space 입력시 차속도가 빠르면느리게 느리면 빠르게 바뀐다.
	void ClearCar(); //종료시 모든 차정보 삭제

	~CarManager();
};

