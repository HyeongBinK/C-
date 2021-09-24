#include "SkillManager.h"

SkillManager::SkillManager()
{
}


void SkillManager::SaveSkillData(string SaveFileName)
{
	ofstream save;

	char buf[30];
	char cstr[20];
	string Tail = ".txt";
	string FileName;
	FileName = SaveFileName + Tail;
	save.open(FileName);
	if (save.is_open())
	{
		for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
		{
			iter->SaveSkillData(save);
			if (iter == Skills.end()-1)
			{
				save << "END";
				break;
			}
			else
				save << "NEXT" << endl;
		}
		save.close();
	}
	//save.close();
}

void SkillManager::LoadSkillData(string LoadFileName)
{
	Skill skill;
	string SkillName;
	int SkillNumber, SkillLevel, SkillDammagePerCent, SkillCoolTime, SkillSpecialEffect, SkillMPCost;
	bool CanBeAcquired;
	string str2;
	ifstream load;
	string Tail = ".txt";
	string FileName;
	FileName = LoadFileName + Tail;
	load.open(FileName);
	while (!load.eof())
	{
		load >> SkillName >> SkillNumber >> SkillLevel >> SkillDammagePerCent >> SkillCoolTime >> SkillSpecialEffect >> SkillMPCost >> CanBeAcquired;
		load >> str2;
		if (str2 == "NEXT" || str2 == "END")
		{
			skill.InputSkillData(SkillName, SkillNumber, SkillLevel, SkillDammagePerCent, SkillCoolTime, SkillSpecialEffect, SkillMPCost, CanBeAcquired);
			Skills.push_back(skill);
			if (str2 == "END")
				break;
		}
	}
	//load.close();
}

//void SkillManager::SetSkillData(int SkillNumber)
//{
//	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
//	{
//		if (SkillNumber == iter->GetSkillNumber())
//		{
//			UseSkill.InputSkillData(iter->GetSkillName(), iter->GetSkillNumber(), iter->GetSkillLevel(), iter->GetSkillDammagePerCent(), iter->GetSkillCoolTime(),
//				iter->GetSkillSpecialEffect(), iter->GetSkillMPCost(), iter->GetCanBeAcquired());
//			return;
//		}
//	}
//}

void SkillManager::UseSkillInBattlePhase()
{
	Draw_Manager.DrawMidText("1.�Ŀ�������",Draw_Manager.GetWidth(), 17);
	ShowCanLearn(SKILLNAME_ePOWERSLASH, 18);
	Draw_Manager.DrawMidText("2.Active:�޺����Ʈ", Draw_Manager.GetWidth(), 20);
	ShowCanLearn(SKILLNAME_eCOMBOASSULT, 21);
	Draw_Manager.DrawMidText("3.Active:�޺��ͽ��ü�(���� �����ൿ�Ұ�)", Draw_Manager.GetWidth(), 23);
	ShowCanLearn(SKILLNAME_eCOMBOEXTINGSION, 24);
	Draw_Manager.DrawMidText("4.���ư���", Draw_Manager.GetWidth(), 26);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 27);
}

void SkillManager::SkillLevelUp(int SkillNumber)
{
	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
	{
		if (SkillNumber == iter->GetSkillNumber())
		{
			if (iter->GetCanBeAcquired() == false)
			{
				ShowCanNotLearnSkill();
				return;
			}
			else
			{
				iter->SkillLevelUp();
				switch (SkillNumber)
				{
				case SKILLNAME_ePOWERSLASH:
					iter->SkillDammageUp(1);
				case SKILLNAME_eCOMBOASSULT:
					iter->SkillDammageUp(3);
				case SKILLNAME_eCOMBOEXTINGSION:
					iter->SkillDammageUp(10);
				}
			}
		}
	}
}

void SkillManager::UpGradeSkill(int PlayerClassNumber, int* SkillPoint)
{
	int Select;
	while (1)
	{
		ShowAndUpgradeSkill(PlayerClassNumber, *SkillPoint);
		cin >> Select;
		switch (Select)
		{
		case SKILLNAME_ePOWERSLASH:
			if ((*SkillPoint) > 0)
			{
				SkillLevelUp(SKILLNAME_ePOWERSLASH);
				(*SkillPoint)--;
			}
			else
				SkillPointError();
			break;
		case SKILLNAME_eCOMBOASSULT:
			if ((*SkillPoint) > 0)
			{
				SkillLevelUp(SKILLNAME_eCOMBOASSULT);
				(*SkillPoint)--;
			}
			else
				SkillPointError();
			break;
		case SKILLNAME_eCOMBOEXTINGSION:
			if ((*SkillPoint) > 0)
			{
				SkillLevelUp(SKILLNAME_eCOMBOEXTINGSION);
				(*SkillPoint)--;
			}
			else
				SkillPointError();
			break;
		case SKILLNAME_eRETURN:
			return;
		default: break;
		}
	}
}

Skill SkillManager::GetSkillAllDataBySkillNumber(int SKillNumber)
{
	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
	{
		if (SKillNumber == iter->GetSkillNumber())
		{
			return *iter;
		}
	}
}

void SkillManager::SkillPointError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("��ų����Ʈ�� ������ ��ų�� �����Ҽ������ϴ�.", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawMidText("���� �����Ҽ����� ��ų�Դϴ�.", Draw_Manager.GetWidth(), 16);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawPauseByGameScreen(18);
	//system("pause");
}

void SkillManager::ChangeSkillCanBeAcquiredBySkillNumber(int SkillNumber)
{
	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
	{
		if (SkillNumber == iter->GetSkillNumber())
		{
			iter->AcquiredChange();
		}
	}
}

void SkillManager::ShowAndUpgradeSkill(int PlayerClass, int SkillPoint)
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText_PlusHeadInt(SkillPoint, "�� ��ų����Ʈ ������", Draw_Manager.GetWidth(), 4);

	Draw_Manager.DrawMidText("�����������ĺ��� ���氡��", Draw_Manager.GetWidth(), 7);
	Draw_Manager.DrawMidText("1.Active:�Ŀ�������(�Ѹ������� ���� ����)", Draw_Manager.GetWidth(), 8);
	ShowCanLearn(SKILLNAME_ePOWERSLASH, 9);

	Draw_Manager.DrawMidText("������������ĺ��� ���氡��", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText("2.Active:�޺����Ʈ(�Ѹ������� �ſ� ���� ����)", Draw_Manager.GetWidth(), 13);
	ShowCanLearn(SKILLNAME_eCOMBOASSULT, 14);
	Draw_Manager.DrawMidText("3.Active:�޺��ͽ��ü�(���� �����ൿ�Ұ�)", Draw_Manager.GetWidth(), 16);
	ShowCanLearn(SKILLNAME_eCOMBOEXTINGSION, 17);
	Draw_Manager.DrawMidText("4.���ư���", Draw_Manager.GetWidth(), 19);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 21);
}

void SkillManager::ShowCanLearn(int SkillNumber, int Line)
{
	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
	{
		if (SkillNumber == iter->GetSkillNumber())
			if (iter->GetCanBeAcquired() == true)
			{
				Draw_Manager.DrawMidText_PlusTailInt(iter->GetSkillLevel(), "���緹�� : ", Draw_Manager.GetWidth(), Line); 
					return;
			}
	}
	Draw_Manager.DrawMidText("���� ���/����Ұ���", Draw_Manager.GetWidth(), Line);
}

void SkillManager::SkillUseError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("���������������� ��ų�̿��� ����Ҽ� �����ϴ�", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawPauseByGameScreen(18);
}

void SkillManager::ShowCanNotLearnSkill()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("���� �������� ��ų�Դϴ�(�����ʿ�)", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawPauseByGameScreen(18);
}

//int SkillManager::GetSkillDammageBySkillNumber(int SkillNumber)
//{
//	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
//	{
//		if (SkillNumber == iter->GetSkillNumber())
//			return iter->GetSkillDammagePerCent();
//	}
//}
//
//int SkillManager::GetSkillMpCostbySkillNumber(int SKillNumber)
//{
//	for (auto iter = Skills.begin(); iter != Skills.end(); iter++)
//	{
//		if (SKillNumber == iter->GetSkillNumber())
//			return iter->GetSkillMPCost();
//	}
//}

void SkillManager::ClearSkillData()
{
	Skills.clear();
}

SkillManager::~SkillManager()
{
}
