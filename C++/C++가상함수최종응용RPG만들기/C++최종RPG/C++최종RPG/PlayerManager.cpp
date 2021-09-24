#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	
}

void PlayerManager::LevelUp()
{
	while (1)
	{
		if (m_iGetExp >= m_iNeedExp)
		{
			int Memo;
			Memo = m_iGetExp - m_iNeedExp;
			m_iLevel++;
			NeedExp_Change();
		
			m_iGetExp = Memo;
			m_iSkillPoint += 3;
			m_iStatPoint += 5;
			StatStatusChange();
			m_iHP = m_iMaxHP;
			m_iMP = m_iMaxMP;
		}
		else
			return;
	}
}

void PlayerManager::Use_Gold(int Gold)
{
	if (m_iOwnedGold >= Gold)
	m_iOwnedGold -= Gold;
}

void PlayerManager::MakePlayerName(string Name)
{
	m_strName = Name;
}

void PlayerManager::StatStatusChange()
{
	 m_iMaxHP = 50 + 10*m_iStr + 10*m_iLevel; 
	 m_iMaxMP = 20 + 5 * m_iLevel; 
	 m_iAtk = 10 + 5 * m_iStr + 2 * m_iDex;
	 m_iShield = 5 + 3 * m_iStr + m_iDex;
	 m_iAttackSpeed = 500 - 2* m_iDex; 
}

void PlayerManager::NeedExp_Change()
{
	m_iNeedExp = 10 + m_iLevel ^ 2;
}

void PlayerManager::Get_EXP(int GiveExp)
{
	m_iGetExp += GiveExp;
	LevelUp();
}

void PlayerManager::GetDeadPenalty()
{
	m_iGetExp *= 0.9;
	m_iHP = m_iMaxHP / 2;
	m_iMP = m_iMaxMP / 2;

}

bool PlayerManager::Use_Mp(int SkillMP)
{
	if (m_iMP - SkillMP >= 0)
	{
		m_iMP -= SkillMP;
		return true;
	}
	else
	{
		cout << "��ų��������" << endl;
		return false;
	}
}

void PlayerManager::ClassChange(int Num)
{
	m_iClassNumber = Num;
}

void PlayerManager::LocationChange(int LocationX, int LocationY)
{
	Location.m_iX_Location = LocationX;
	Location.m_iY_Location = LocationY;
}

//void PlayerManager::ChangeMapSize(int Width, int Height)
//{
//	m_iWidth = Width;
//	m_iHeight = Height;
//
//	PlayerLocationXY.m_iX_Location = Width * 0.5f;
//	PlayerLocationXY.m_iY_Location = Height * 0.5f;
//}

//void PlayerManager::PlayerMoveinDunGeon(char* ch)
//{
//	while (1)
//	{
//			DrawCharacter();
//
//			*ch = getch();
//
//			Draw_Manager.ErasePoint(PlayerLocationXY.m_iX_Location, PlayerLocationXY.m_iY_Location);
//
//		
//
//			switch (*ch)
//			{
//			case KEY_LEFT: //����
//				if (PlayerLocationXY.m_iX_Location - 2 >= 0)
//					PlayerLocationXY.m_iX_Location--;
//				break;
//			case KEY_RIGHT: //������
//				if (PlayerLocationXY.m_iX_Location + 2 < Draw_Manager.GetWidth())
//					PlayerLocationXY.m_iX_Location++;
//				break;
//			case KEY_UP: //����
//				if (PlayerLocationXY.m_iY_Location - 2 >= 0)
//					PlayerLocationXY.m_iY_Location--;
//				break;
//			case KEY_DOWN: //�Ʒ���
//				if (PlayerLocationXY.m_iY_Location + 2 < Draw_Manager.GetHeight())
//					PlayerLocationXY.m_iY_Location++;
//				break;
//			case KEY_ENTER: //�δ����� �޴�â�ҷ�����
//				return;
//			case KEY_ESC: //���ӵ��� ��������
//				return;
//			default:
//				break;
//			/*default:
//				break;*/
//			}
//		}
//	
//}

void PlayerManager::DrawCharacter()
{
	Draw_Manager.DrawPoint(m_strCharacterImage, Location.m_iX_Location, Location.m_iY_Location);
}

void PlayerManager::SavePlayerCharacter(string SaveFileName, int i)
{
	ofstream save;
	string FileName;
	char cstr[50];
	string Tail = ".txt";

	FileName = SaveFileName + to_string(i) + Tail;

	strcpy(cstr, FileName.c_str());
	save.open(cstr);
	if (save.is_open())
	{
		save << m_strCharacterImage << endl;
		save << m_iClassNumber << endl;
		save << m_strName << endl;
		save << m_iLevel << endl;
		save << m_iMaxHP << endl;
		save << m_iMaxMP << endl;
		save << m_iHP << endl;
		save << m_iMP << endl;
		save << m_iAtk << endl;
		save << m_iShield << endl;
		save << m_iAttackSpeed << endl;
		save << m_iGetExp << endl;
		save << m_iNeedExp << endl;
		save << m_iLifeStatus << endl;
		
		save << m_iStatPoint << endl;
		save << m_iSkillPoint << endl;
		save << m_iStr << endl;
		save << m_iDex << endl;
		save << m_iOwnedGold << endl;

		//save << m_iWidth << endl;
		//save << m_iHeight << endl;
		save << m_iEquipWeaponNumber << endl;
		save << "END" << endl;
		save.close();
	}
	FileName = "SkillData" + to_string(i);
	Skill_Manager.SaveSkillData(FileName);
	return;
}

void PlayerManager::LoadPlayerCharacter(string LoadFileName, int i)
{
	ifstream load;
	char buf[30];
	string Tail = ".txt";
	char cstr[20];
	string str2;
	string FileName;
	
	if (i != 0)
		FileName = LoadFileName + to_string(i) + Tail;
	else
		FileName = LoadFileName + Tail;

	load.open(FileName);
	while (!load.eof())
	{
		load >> m_strCharacterImage;
		load >> m_iClassNumber;
		load >> m_strName;
		load >> m_iLevel;
		load >> m_iMaxHP;
		load >> m_iMaxMP;
		load >> m_iHP;
		load >> m_iMP;
		load >> m_iAtk;
		load >> m_iShield;
		load >> m_iAttackSpeed;
		load >> m_iGetExp;
		load >> m_iNeedExp;
		load >> m_iLifeStatus;
	
		load >> m_iStatPoint;
		load >> m_iSkillPoint;
		load >> m_iStr;
		load >> m_iDex;
		load >> m_iOwnedGold;

		//load >> m_iWidth;
		//load >> m_iHeight;
		load >> m_iEquipWeaponNumber;
		load >> str2;
		if (str2 == "END")
			break;
	}
	load.close();
	if(LoadFileName == "BasePlayerCharacter")
	Skill_Manager.LoadSkillData("BaseSkillData");
	else if (LoadFileName == "PlayerCharacterData")
	{
		FileName = "SkillData" + to_string(i);
		Skill_Manager.LoadSkillData(FileName);
	}
}

void PlayerManager::ItemEquip(int WeaponNumber)
{
	m_iEquipWeaponNumber = WeaponNumber;
}

void PlayerManager::ShowTotalStatus()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText_TwoString("ĳ�����̹��� : ", m_strCharacterImage, Draw_Manager.GetWidth(), 3);
	Draw_Manager.DrawMidText_TwoString("ĳ�������� : ", ClassNumbertoClassName(m_iClassNumber), Draw_Manager.GetWidth(), 4);
	Draw_Manager.DrawMidText_TwoString("ĳ�����̸� : ", m_strName, Draw_Manager.GetWidth(), 5);
	Draw_Manager.DrawMidText_PlusTailInt(m_iLevel, "���緹�� :", Draw_Manager.GetWidth(), 6);
	Draw_Manager.DrawMidText_PlusTailInt(m_iMaxHP, "�ִ�ü�� :", Draw_Manager.GetWidth(), 7);
	Draw_Manager.DrawMidText_PlusTailInt(m_iHP, "����ü�� :", Draw_Manager.GetWidth(), 8);
	Draw_Manager.DrawMidText_PlusTailInt(m_iMaxMP, "�ִ븶���� :", Draw_Manager.GetWidth(), 9);
	Draw_Manager.DrawMidText_PlusTailInt(m_iMP, "���� ������ :", Draw_Manager.GetWidth(), 10);
	Draw_Manager.DrawMidText_PlusTailInt(m_iStr, "�������ڵ� STR :", Draw_Manager.GetWidth(), 11);
	Draw_Manager.DrawMidText_PlusTailInt(m_iDex, "�������ڵ� DEX :", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText_PlusTailInt(m_iAtk, "���ݷ� :", Draw_Manager.GetWidth(), 13);
	Draw_Manager.DrawMidText_PlusTailInt(m_iShield, "���� :", Draw_Manager.GetWidth(), 14);
	Draw_Manager.DrawMidText_PlusTailInt(m_iAttackSpeed, "����ġ :", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawMidText_PlusTailInt(m_iGetExp, "������������Ѱ���ġ :", Draw_Manager.GetWidth(), 16);
	Draw_Manager.DrawMidText_PlusTailInt(m_iNeedExp, "��������ʿ��Ѱ���ġ :", Draw_Manager.GetWidth(), 17);
	Draw_Manager.DrawMidText_PlusTailInt(m_iStatPoint, "�������� ��������Ʈ :", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawMidText_PlusTailInt(m_iSkillPoint, "�������� ��ų����Ʈ :", Draw_Manager.GetWidth(), 19);
	Draw_Manager.DrawMidText_PlusTailInt(m_iOwnedGold, "�������� ��� :", Draw_Manager.GetWidth(), 20);
	Draw_Manager.DrawMidText_PlusTailInt(m_iEquipWeaponNumber, "�������ι����ȣ :", Draw_Manager.GetWidth(), 21);
	Draw_Manager.DrawPauseByGameScreen(22);

}

void PlayerManager::ClearSkillData()
{
	Skill_Manager.ClearSkillData();
}

string PlayerManager::ClassNumbertoClassName(int ClassNumber)
{
	switch (ClassNumber)
	{
	case CLASS_eCIVILIAN : 
		return "�ù�";
	case CLASS_eWARRIOR :
		return "����";
	case CLASS_eHERO :
		return "�����";
	default:
		return "Ŭ������ȣ�ε��߿����߻�";
	}
}

void PlayerManager::UpGradeStatusPoint()
{
	int Select;
	while (1)
	{
		system("cls");
		Draw_Manager.DrawBorder();
		Draw_Manager.DrawMidText_PlusHeadInt(m_iStatPoint, "�� ��������Ʈ ������", Draw_Manager.GetWidth(), 5);

		Draw_Manager.DrawMidText_PlusTailInt(m_iStr, "����������ڵ� STR :", Draw_Manager.GetWidth(), 7);
		Draw_Manager.DrawMidText_PlusTailInt(m_iDex, "����������ڵ� DEX :", Draw_Manager.GetWidth(), 9);
		Draw_Manager.DrawMidText("1.STR(���ݷ¿� ����)", Draw_Manager.GetWidth(), 11);
		Draw_Manager.DrawMidText("2.DEX(���ݼӵ��� ����)", Draw_Manager.GetWidth(), 13);
		/*
		DrawMidText("2.INT(������迭���¹� �ִ븶������ ����)", BASEWIDTH, 9);
		DrawMidText("3.DEX(�ü��迭���ݷ¹� ���ݼӵ��� ����)", BASEWIDTH, 11);
		*/
		Draw_Manager.DrawMidText("3.���ư���", Draw_Manager.GetWidth(), 15);
		Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 17);
		cin >> Select;
		switch (Select)
		{
		case STATUS_eSTR:
			if (m_iStatPoint > 0)
			{
				m_iStatPoint--;
				m_iStr++;
				StatStatusChange();
			}
			else 
				StatPointError();
			break;;
		case STATUS_eDEX:
			if (m_iStatPoint > 0)
			{
				m_iStatPoint--;
				m_iDex++;
				StatStatusChange();

			}
			else 
				StatPointError();
			break;
		case STATUS_eRETURN :
			return;
		default:
			break;
		}

	}
}

void PlayerManager::GetGold(int Gold)
{
	m_iOwnedGold += Gold;
}

void PlayerManager::ShowClassChange()
{
	system("cls");
	Draw_Manager.DrawBorder();
	int Select;

	switch (m_iClassNumber)
	{
	case CLASS_eCIVILIAN:
		Draw_Manager.DrawMidText("LV10�̻��Ͻ� ��������", Draw_Manager.GetWidth(), 9);
		Draw_Manager.DrawMidText("1.����", Draw_Manager.GetWidth(), 11);

		/*	DrawMidText("2.�ü�(Str���̽� 2���� �н����δ�,������ ����)", BASEWIDTH,14);
			DrawMidText("3.������(Int���̽� 2���� ��,������ũ������ ����)", BASEWIDTH, 17);*/
		break;
	case CLASS_eWARRIOR:
		Draw_Manager.DrawMidText("LV50�̻��Ͻ� ��������", Draw_Manager.GetWidth(), 9);
		Draw_Manager.DrawMidText("1.�����", Draw_Manager.GetWidth(), 11);
		/*
		DrawMidText("2.�巡�������(�ֹ���: â))", BASEWIDTH, 14);
			break;
		case m_eARCHER:
			DrawMidText("1.�н����δ�(�ֹ���: ���̼�Ʈ����)", BASEWIDTH, 11);
			DrawMidText("2.������(�ֹ���: Ȱ)", BASEWIDTH, 14);
			break;
		case m_eMAGICIAN:
			DrawMidText("1.�Ҿ�ũ������)", BASEWIDTH, 11);
			DrawMidText("2.������ũ������)", BASEWIDTH, 14);
			break;
		*/
		break;
	default:
		return;
	}
	Draw_Manager.DrawMidText("2.���ư���", Draw_Manager.GetWidth(), 13);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 15);
	cin >> Select;

	switch (Select)
	{
	case 1:
		if (m_iClassNumber == CLASS_eCIVILIAN)
		{
			if (m_iLevel >= 10)
			{
				ClassChange(CLASS_eWARRIOR);
				Draw_Manager.DrawMidText("���谡���� ����� ���������� ������ �����Ͽ����ϴ�", Draw_Manager.GetWidth(), 12);
			}
			else
				Draw_Manager.DrawMidText("�����̺����մϴ�", Draw_Manager.GetWidth(), 12);
			cout << endl;
		}
		else if (m_iClassNumber == CLASS_eWARRIOR)
		{
			if (m_iLevel >= 50)
			{
				ClassChange(CLASS_eHERO);
				Draw_Manager.DrawMidText("���翡�� ����η� ���������� ������ �����Ͽ����ϴ�", Draw_Manager.GetWidth(), 12);
			}

			else
				Draw_Manager.DrawMidText("�����̺����մϴ�", Draw_Manager.GetWidth(), 12);
			cout << endl;
		}

		Draw_Manager.DrawPauseByGameScreen(15);
		break;
	case 2:
		return;
	}
	if (m_iClassNumber == CLASS_eWARRIOR)
	{
		Skill_Manager.ChangeSkillCanBeAcquiredBySkillNumber(SKILLNAME_ePOWERSLASH);
	}
	else if (m_iClassNumber == CLASS_eHERO)
	{
		Skill_Manager.ChangeSkillCanBeAcquiredBySkillNumber(SKILLNAME_eCOMBOASSULT);
		Skill_Manager.ChangeSkillCanBeAcquiredBySkillNumber(SKILLNAME_eCOMBOEXTINGSION);
	}

}

void PlayerManager::UpgradeSkill_PlusPlayerData()
{
	Skill_Manager.UpGradeSkill(m_iClassNumber ,&m_iSkillPoint);
}

void PlayerManager::ShowMakeNameMenu()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("ĳ�����̸��Է� : ", Draw_Manager.GetWidth(), 15);
}

void PlayerManager::ShowSkillLearnError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("���������Ҽ����� ��ų�Դϴ�.", Draw_Manager.GetWidth(), 15);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawPauseByGameScreen(18);
}

void PlayerManager::GoldError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("��尡������ �������� �����Ҽ������ϴ�.", Draw_Manager.GetWidth(), 15);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawPauseByGameScreen(18);
}

void PlayerManager::StatPointError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("��������Ʈ�������Ͽ� �����������������ϴ�", Draw_Manager.GetWidth(), 15);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawPauseByGameScreen(18);
	
}

void PlayerManager::MPError()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("MP�� ������ ��ų�� ����Ҽ������ϴ�", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawPauseByGameScreen(18);
}

PlayerManager::~PlayerManager()
{

}