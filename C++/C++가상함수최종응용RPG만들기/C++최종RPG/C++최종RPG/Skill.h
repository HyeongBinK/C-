#pragma once
#include"BaseHeader.h"

class Skill
{
private:
protected:
	string m_strSkillName; //��ų�̸�
	int m_iSkillNumber; //��ų�����ĺ���ȣ
	int m_iSkillLevel; //��ų����
	int m_iSkillDammagePerCent; //��Ƽ�꽺ų�� ������ ��������
	int m_iSkillCoolTime; //��ų�г�Ƽ��
	int m_iSkillSpecialEffect; //����, ȭ��� �����̻��� �Ŵ� ��ų�ϰ��
	int m_iSkillMPCost; //�Ҹ� MP��
	bool m_bCanBeAcquired; //���氡�ɿ���
public:
	Skill();
	void AcquiredChange(); //������ ���氡�ɿ��κ���
	void SkillLevelUp(); //��ų�����
	void SkillDammageUp(int DammagePerCent); //��ų��������������
	void InputSkillData(string Name, int SkillNumber, int SkillLevel, int SkillDammagePerCent, int SkillCoolTime,
		int SkillSpecialEffect, int SkillMPCost, bool CanBeAcquired); //��ų�����ֱ�
	void SaveSkillData(ofstream& save); //��ų��������

	inline bool GetCanBeAcquired()
	{
		return m_bCanBeAcquired;
	}
	inline int GetSkillLevel()
	{
		return m_iSkillLevel;
	}
	inline string GetSkillName()
	{
		return m_strSkillName;
	}
	inline int GetSkillMPCost()
	{
		return m_iSkillMPCost;
	}
	inline int GetSkillCoolTime()
	{
		return m_iSkillCoolTime;
	}
	inline int GetSkillNumber()
	{
		return m_iSkillNumber;
	}
	inline int GetSkillSpecialEffect()
	{
		return m_iSkillSpecialEffect;
	}
	inline int GetSkillDammagePerCent()
	{
		return m_iSkillDammagePerCent;
	}
	~Skill();
};

