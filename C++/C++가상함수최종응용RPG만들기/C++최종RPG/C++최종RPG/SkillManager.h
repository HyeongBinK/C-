#pragma once
#include"BaseHeader.h"
#include"Skill.h"
#include"DrawManager.h"

class SkillManager  
{
private:
	DrawManager Draw_Manager;
	vector<Skill> Skills;
	//Skill UseSkill;
protected:
public:
	SkillManager();
	//�����Ͱ����κ�
	void SaveSkillData(string SaveFileName); //��ų������(����� ����) ����
	void LoadSkillData(string LoadFileName); //��ų������ �ҷ�����
	void ClearSkillData(); //�������ᳪ �߰��ε�� �����������ʱ�ȭ

	//����Լ��κ�
	void ChangeSkillCanBeAcquiredBySkillNumber(int SkillNumber); //��ų��ȣ�� �޾ƿͼ� ��ų���氡�ɺҰ��ɿ��� ����
	//void SetSkillData(int SkillNumber); //����ѽ�ų������ �޾ƿ�
	void UpGradeSkill(int PlayerClassNumber, int* SkillPoint); //��ų�����
	void SkillLevelUp(int SKillNumber); //��ų������� ��ų���º���
	void UseSkillInBattlePhase(); //��Ʋ������� ��ų����Է½� ǥ�õ� ��ų����â
	Skill GetSkillAllDataBySkillNumber(int SkillNumber); //��ų��ȣ�� ��ų����ȸ�ؼ� �׽�ų�����͸� ���ΰ�����
	//int GetSkillMpCostbySkillNumber(int SkillNumber); //��ų��ȣ�� �Ҹ�Ǵ� ������ ������ 
	//int GetSkillDammageBySkillNumber(int SkillNumber); //��ų��ȣ�� �����������ۼ�Ʈ ������
	//�������̽�
	void ShowAndUpgradeSkill(int PlayerClass, int SkillPoint); //��ų����Ʈ�й�� ǥ����â
	void ShowCanLearn(int SkillNumber, int Line); //�����ִ���������
	void SkillUseError(); //����Ҽ����� ��ų�� ����Ϸ������� ǥ���ϴ� ����â
	void ShowCanNotLearnSkill(); //�����Ҽ����� ��ų�� ���������� ǥ���ϴ� ����â
	void SkillPointError(); //��ų����Ʈ������ ǥ�õǴ� â
	/*inline Skill GetUseSkillData()
	{
		return UseSkill;
	}*/
	~SkillManager();
};

