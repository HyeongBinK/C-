#pragma once
#include"BaseHeader.h"
#include"Character.h"

class Monster: public virtual Character
{

protected:
	int m_iMonsterNumber; //���͹�ȣ
	int m_iGiveExp; //��������ִ� ����ġ	
	int m_iGiveMaxMoney; //��������ִ� �ִ� ���
	Point Location; //������ǥ �޸��忡�� �Ⱥҷ����� ���͸Ŵ������� ���ͻ����� �Է�
public:
	Monster();
	void InputMonsterData(string CharacterImage, int ClassNumber, int MonsterNumber, string Name, int Level, int MaxHP
		, int Atk, int Shield, int AttackSpeed, int LifeStatus, int GiveExp, int GiveMaxMoney);
	void ChangeMonsterLocation(int NewX, int NewY)
	{
		Location.m_iX_Location = NewX;
		Location.m_iY_Location = NewY;
	}
	inline Point GetMonsterLocation()
	{
		return Location;
	}
	inline int GetMonsterNumber()
	{
		return m_iMonsterNumber;
	}
	inline int GetMonsterGiveMoney()
	{
		return m_iGiveMaxMoney;
	}
	inline int GetMonsterGiveExp()
	{
		return m_iGiveExp;
	}
	~Monster();
};

