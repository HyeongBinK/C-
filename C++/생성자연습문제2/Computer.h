#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

class Computer
{
private:
	string m_strComputerName, m_strPower, m_strGraphicCard, m_strCpuName;
	int m_iMemory;

public:
	void PowerOn();
	void PowerOff();
	void ShowBasicMenu();
	void ShowComputerStatus();
	void ShowToolMenu();
	void PlayTool();
	void SetComputerStatus(string ComputerName, string Power, string GraphicCard, string CpuName, int Memory);

	Computer();
	~Computer();
};

