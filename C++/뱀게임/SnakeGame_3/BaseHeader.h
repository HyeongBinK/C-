#pragma once

#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stack>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<crtdbg.h>

using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define X_STARTLOCATION 50
#define Y_STARTLOCATION 50
#define HEAD_START_LOCATION_X 10
#define HEAD_START_LOCATION_Y 10
#define STOP 32

struct Point
{
	int m_iX_Location;
	int m_iY_Location;
};