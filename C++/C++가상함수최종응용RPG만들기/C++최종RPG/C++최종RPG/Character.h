#pragma once
#include"BaseHeader.h"

struct Point
{
	int m_iX_Location;
	int m_iY_Location;
};

class Character
{
protected:
	string m_strCharacterImage; //ĳ�������̹���
	int m_iClassNumber; //����, ���ʹ� ����������
	string m_strName; //ĳ�����̸� or �����̸�
	int m_iLevel; //���緹��
	int m_iMaxHP; //�ִ�ü��
	int m_iHP; //����ü��
	int m_iAtk; //���ݷ�
	int m_iShield; //�������
	int m_iAttackSpeed; //���ݼӵ�
	int m_iLifeStatus; //�����̻� �̳� �׾��ų� ��Ұų� ����
public:
	Character();
	void Get_Dammage(int TrueDammage);
	void InputCharacterImage(string str);
	void LifeStatusChange(int LifeStatus);
	void ChangeAttackSpeedByParalysys(int Speed);//������·����� �ӵ�����

	inline string GetCharacterImage()
	{
		return m_strCharacterImage;
	}
	inline string GetName()
	{
		return m_strName;
	}
	inline int GetClassNumber()
	{
		return m_iClassNumber;
	}
	inline int GetLevel()
	{
		return m_iLevel;
	}
	inline int GetMaxHP()
	{
		return m_iMaxHP;
	}
	inline int GetHP()
	{
		return m_iHP;
	}
	inline int GetAtk()
	{
		return m_iAtk;
	}
	inline int GetShield()
	{
		return m_iShield;
	}
	inline int GetAttackSpeed()
	{
		return m_iAttackSpeed;
	}
	inline int GetLifeStatus()
	{
		return m_iLifeStatus;
	}
	~Character();
};

