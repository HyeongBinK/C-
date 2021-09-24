#pragma once
#include "BaseHeader.h"

class Ward
{
private:
	int m_iLocationX; //X��ǥ
	int m_iLocationY; //Y��ǥ
	string m_strWard;
	int m_iTimer;
	int m_iFallenDelay;
	bool m_bDead;
	bool m_SuccessAttack;

protected:
public:
	void Warddraw(); //ȭ�鿡 �ܾ�׸���
	void Warddrop(); //�ܾ� ����Ʈ����(Y��ǥ�� ����)
	void Live(int NewTimer); //�ܾ ���� �������� ���� 
	void Die(); //�ܾ �÷��̾ �Է����Ͽ��ų� �ٴڿ� ��Ƽ� �Ҹ�
	void MakeNewWard(string NewWard, int XLocation, int NewFallenDelay); //�ܺο��� �����Ͱ� ����� �Է¹ް� �׿ܿ� ����Ʈ��(�����Ѱ�)���� 
	void UserUseSpeedItem(int NewSpeed); //������ �������� ����Ͽ� ���ϼӵ� (m_iFallenDelay) �� ������ �־� ���ϼӵ�����

	inline string GetWard() const
	{
		return m_strWard;
	}
	inline int GetXLocation() const
	{
		return m_iLocationX;
	}
	inline int GetYLocation() const
	{
		return m_iLocationY;
	}
	inline bool GetDie() const
	{
		return m_bDead;
	}
	inline bool GetAttackSuccees() const
	{
		return m_SuccessAttack;
	}
};

