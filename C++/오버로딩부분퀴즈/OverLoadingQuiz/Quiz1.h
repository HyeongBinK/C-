#pragma once
#include "MainHeader.h"

class Quiz1
{
private : 
	int m_iX;
	int m_iY;
	//X,Y�� float �� �����ϸ� �ʿ�����ڵ����� ���ܸ�ó�����ʿ䵵�����Ƿ� �̷�������θ����ý��ϴ�
	//���������� ū���� �������ְ� ����ó���ϱ����� �߰�
	float m_iDummyX;
	float m_iDummyY;
protected :
public :
	Quiz1();
	Quiz1(int num1, int num2);
	void ShowNumber();
	Quiz1 operator /(Quiz1 tmp);

	~Quiz1();
};

