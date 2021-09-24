#pragma once
#include"BaseHeader.h"
#include"Login.h"

class Computer : Login
{
private:
	string m_strComputerName, m_strPower, m_strGraphicCard, m_strCpuName;
	int m_iMemory;
	bool bPowerStatus;
public:
	Computer();
	void PowerOn();
	void PowerOff();
	void ShowBasicMenu();
	void ShowComputerStatus();
	void ShowToolMenu();
	void PlayTool();
	void SetComputerStatus(string ComputerName, string Power, string GraphicCard, string CpuName, int Memory);
	void PlayComputer();
	~Computer();
};

