#pragma once
#include"BaseHeader.h"

class WeaponSkill 
{
private :
	bool m_iIsWeaponSkill; //������ ��ų�������� Ʈ�� ������ �޽�
	string m_iWeapon_SkillName; //���⽺ų�̸�(������ ���� �̶� ǥ��)
	int m_iWeapon_AbnormalStateSkill_IntrinsicEffect; //���⿡ �����̻�ο��迭�� ��ų�� ������ �ش���� ������ 0

protected :
public :
	WeaponSkill();
	void SetDataByOutSide(bool IsWeaponSkill, string SkillName, int IntrinsicEffect);

	inline bool GetIsWeaponSkill()
	{
		return m_iIsWeaponSkill;
	}
	inline string GetWeaponSkillName()
	{
		return m_iWeapon_SkillName;
	}
	inline int GetWeaponIntrinsicEffect()
	{
		return m_iWeapon_AbnormalStateSkill_IntrinsicEffect;
	}

   ~WeaponSkill();

};

