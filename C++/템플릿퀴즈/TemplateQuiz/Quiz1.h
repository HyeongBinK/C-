#pragma once
#include "BaseHeader.h"

template<typename Type>
Type Plus1(Type num);

class Quiz1
{
private:
	//�ڷ����� �÷�Ʈ�� �����ϸ� ���������� template�� 
	//��Ʈ���� ����Ʈ���� ���ΰ����ְԲ� �ڵ带������
	int m_inum; 
	float m_fnum;
protected:
public:
	void PlayQuiz1();
	void InputNumber();
	void ShowNumber();
};


