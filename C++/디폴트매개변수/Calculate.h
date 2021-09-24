#pragma once
#include<iostream>
#include<windows.h>

using namespace std;

#define GUGUDANSTART 1
#define GUGUDANEND 9

class Calculate
{
private:
	int m_iWorkDay, m_iWorkTime, m_iWorkPay;
	int m_iNum;
	int m_iStartDan, m_iEndDan;

public:
	void InPutWorkingPay();
	void SetWorkingPay(int iWorkDay, int iWorkTime = 8, int iWorkPay = 7500);
	void ShowWorkingPay();
	void InputAddSum();
	void SetAddSum(int iNum= 10);
	void ShowAddSum();
	void InPutGuGuDan();
	void SetGuGuDan(int iStartDan = 2, int iEndDan = 9);
	void ShowGuGuDan();
	void SelectMenu();
	Calculate();
	~Calculate();
};
