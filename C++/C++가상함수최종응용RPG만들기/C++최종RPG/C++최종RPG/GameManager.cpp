#include "GameManager.h"

GameManager::GameManager()
{
	ScreenSizeSetting();
	m_bGameEndFlag = false;
	m_bExitDungeonFlag = false;
	m_bPlayerDeadFlag = false;
}

void GameManager::PlayGame()
{
	int Select;
	while (1)
	{
		m_bGameEndFlag = false;

		ShowStartMenu();
		cin >> Select;
		switch (Select)
		{
		case 1:
			NewGame();
			GameManipulation();
			break;
		case 2:
			if (LoadSlot() == true)
				GameManipulation();
			else 
				break;
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void GameManager::NewGame()
{
	string Name;
	Player_Manager.LoadPlayerCharacter("BasePlayerCharacter", 0);
	Weapon_Manager.LoadWeaponsData("BaseWeaponData");
	Monster_Manager.LoadMonsterData("BaseMonsterData");
	Player_Manager.ShowMakeNameMenu();
	cin >> Name;
	Player_Manager.MakePlayerName(Name);
}

void GameManager::SaveGame(int i)
{
	Player_Manager.SavePlayerCharacter("PlayerCharacterData" , i);
	Weapon_Manager.SaveWeaponsData("WeaponData"+ to_string(i));
	//Player_Manager.SavePlayerCharacter("PlayerCharacterData");
	//Weapon_Manager.SaveWeaponsData("WeaponData");
	ShowSaveAndLoadComplete();
}

void GameManager::LoadGame(int i)
{
	DataClear();
	Player_Manager.LoadPlayerCharacter("PlayerCharacterData" , i);
	Weapon_Manager.LoadWeaponsData("WeaponData" + to_string(i));
	/*Player_Manager.LoadPlayerCharacter("PlayerCharacterData");
	Weapon_Manager.LoadWeaponsData("WeaponData");*/
	Monster_Manager.LoadMonsterData("BaseMonsterData");
	ShowSaveAndLoadComplete();
}

void GameManager::DataClear()
{
	Monster_Manager.ResetMonsterInDungeon();
	Monster_Manager.EraseMonsterData();
	Weapon_Manager.ClearWeaponData();
	Player_Manager.ClearSkillData();
}

void GameManager::SaveSlot()
{
	string PlayerDataName = "PlayerCharacterData";
	string WeaponDataName = "WeaponData";
	string FileName;
	string Tail = ".txt";
	char FileNametoChar[30];
	int FileSlotNumber;
	int Select;
	FILE* f;

	//ifstream load;
	while (1)
	{
		system("cls");
		Draw_Manager.DrawBorder();
		Draw_Manager.DrawMidText("=====Save=====", Draw_Manager.GetWidth(), 10);
		//printf("=====Save=====\n");
		for (FileSlotNumber = 1; FileSlotNumber <= SAVELOADSLOTMAX; FileSlotNumber++)
		{
			char ch;
			FileName = PlayerDataName + to_string(FileSlotNumber)+ Tail;
			strcpy(FileNametoChar, FileName.c_str());
			f = fopen(FileNametoChar, "r");
			if (f == NULL)
				ch = 'x';
			else
				ch = 'o';
			//printf("%d������ : <���Ͽ��� : %c>\n", i, ch);
			//cout << i << "������ : <���Ͽ��� :" + ch + '>' << endl;
			Draw_Manager.DrawMidText(to_string(FileSlotNumber) + "������ : <���Ͽ��� :" + ch + '>', Draw_Manager.GetWidth(), 10 + FileSlotNumber);
		}
		Draw_Manager.DrawMidText(to_string(FileSlotNumber) + "�ǵ��ư���", Draw_Manager.GetWidth(), 10 + FileSlotNumber);
		Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 10 + FileSlotNumber + 2);
		cin >> Select;
		if (Select == FileSlotNumber)
			return;
		else if (Select > FileSlotNumber || Select < 1)
		{
			system("cls");
			Draw_Manager.DrawBorder();
			Draw_Manager.DrawMidText("1~10������ ���Կ��� ����ε��ϼ���!", Draw_Manager.GetWidth(), 15);
		}
		else if (Select >= 1 && Select <= SAVELOADSLOTMAX)
		{
			SaveGame(Select);
			return;
		}
	}
}

bool GameManager::LoadSlot()
{
	string PlayerDataName = "PlayerCharacterData";
	//string WeaponDataName = "WeaponData";
	string FileName;
	string Tail = ".txt";
	char FileNametoChar[30];
	int FileSlotNumber;
	int Select;
	bool LoadStateFlag = false;
	FILE* f;

	//ifstream load;
	while (1)
	{
		system("cls");
		Draw_Manager.DrawBorder();

		Draw_Manager.DrawMidText("=====Load=====", Draw_Manager.GetWidth(), 10);
		for (FileSlotNumber = 1; FileSlotNumber <= SAVELOADSLOTMAX; FileSlotNumber++)
		{
			char ch;
			FileName = PlayerDataName + to_string(FileSlotNumber)+ Tail;
			strcpy(FileNametoChar, FileName.c_str());
			f = fopen(FileNametoChar, "r");
			if (f == NULL)
				ch = 'x';
			else
				ch = 'o';
			Draw_Manager.DrawMidText(to_string(FileSlotNumber) + "������ : <���Ͽ��� :" + ch + '>', Draw_Manager.GetWidth(), 10 + FileSlotNumber);
		}
		Draw_Manager.DrawMidText(to_string(FileSlotNumber) + "�ǵ��ư���", Draw_Manager.GetWidth(), 10 + FileSlotNumber);
		Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 10 + FileSlotNumber + 2);
		cin >> Select;
		if (Select == FileSlotNumber)
			break;
		else if (Select > FileSlotNumber || Select < 1)
		{
			system("cls");
			Draw_Manager.DrawBorder();
			Draw_Manager.DrawMidText("1~10������ ���Կ��� ����ε��ϼ���!", Draw_Manager.GetWidth(), 15);
		}
		else if (Select >= 1 && Select <= SAVELOADSLOTMAX)
		{
			FileName = PlayerDataName + to_string(Select) + Tail;
			strcpy(FileNametoChar, FileName.c_str());
			f = fopen(FileNametoChar, "r");
			if (f == NULL)
			{
				system("cls");
				Draw_Manager.DrawBorder();
				Draw_Manager.DrawMidText("�ش罽�Կ� ���̺������̾����ϴ�", Draw_Manager.GetWidth(), 15);
				Draw_Manager.DrawPauseByGameScreen(16);
			}
			else
			{
				DataClear();
				LoadGame(Select);
				LoadStateFlag = true;
				break;
			}
		}
	}
	return LoadStateFlag;
}

void GameManager::ScreenSizeSetting()
{
	int Width = (Draw_Manager.GetWidth() * 2) + 1;
	int Height = Draw_Manager.GetHeight() + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
}

void GameManager::GameManipulation() 
{
	while (m_bGameEndFlag == false)
	{
		OutDungeonManipulation();
	}
	DataClear();
}

void GameManager::OutDungeonManipulation()
{
	if (m_bGameEndFlag == true)
		return;
	
	int Select;
	Draw_Manager.DrawBorder();
	ShowOutDungeonMenu();
	
	cin >> Select;
	switch (Select)
	{
		case OUTDUNGEON_eGOBSHOME : 
			InDungeonManipulation(MOBNAME_eGOB);
			break;
		case OUTDUNGEON_eMINOTASHOME :
			InDungeonManipulation(MOBNAME_eMINOTAURS);
			break;
		case OUTDUNGEON_eCULSEDTEMPLE :
			InDungeonManipulation(MOBNAME_eDEVIL);
			break;
		case OUTDUNGEON_eDRAGONNEST :
			InDungeonManipulation(MOBNAME_eWYVERN);
			break;
		case OUTDUNGEON_eWEAPONTRADER :
			Player_Manager.Use_Gold(Weapon_Manager.WeaponTrader(Player_Manager.GetOwnedGold()));
			break;
		case OUTDUNGEON_eCHARACTERINFORMATION :
			CharacterMenuManipulation();
			break;
		case OUTDUNGEON_eGAMESAVE :
			SaveSlot();
			break;
		case OUTDUNGEON_eGAMELOAD :
			LoadSlot();
			return;
		case OUTDUNGEON_eENDGAME :
			m_bGameEndFlag = true;
			return;
		default :
			break;
	}
}

void GameManager::InDungeonManipulation(int MonsterNumber)
{
	m_bExitDungeonFlag = false;
	//bool HitMonsterFlag = false;
	char ch = NULL;
	system("cls");
	Draw_Manager.DrawBorder();
	ShowInDungeonKeyRule();
	Monster_Manager.ChangeMonsterMakeClock(clock());
	Player_Manager.LocationChange(Draw_Manager.GetWidth() * 0.5f, Draw_Manager.GetHeight() * 0.5f);
	Player_Manager.DrawCharacter();
	while (m_bExitDungeonFlag == false)
	{
		Monster_Manager.MakeMonsterInDungeon(MonsterNumber, Player_Manager.GetPlayerLocation());
		if (kbhit())
		{
			ch = getch();
			Draw_Manager.ErasePoint(Player_Manager.GetPlayerLocation().m_iX_Location, Player_Manager.GetPlayerLocation().m_iY_Location);
			switch (ch)
			{
			case KEY_LEFT: //����
				if (Player_Manager.GetPlayerLocation().m_iX_Location - 2 >= 0)
					Player_Manager.LocationChange(Player_Manager.GetPlayerLocation().m_iX_Location - 1, Player_Manager.GetPlayerLocation().m_iY_Location);
				break;
			case KEY_RIGHT: //������
				if (Player_Manager.GetPlayerLocation().m_iX_Location + 2 < Draw_Manager.GetWidth())
					Player_Manager.LocationChange(Player_Manager.GetPlayerLocation().m_iX_Location + 1, Player_Manager.GetPlayerLocation().m_iY_Location);
				break;
			case KEY_UP: //����
				if (Player_Manager.GetPlayerLocation().m_iY_Location - 2 >= 0)
					Player_Manager.LocationChange(Player_Manager.GetPlayerLocation().m_iX_Location, Player_Manager.GetPlayerLocation().m_iY_Location - 1);
				break;
			case KEY_DOWN: //�Ʒ���
				if (Player_Manager.GetPlayerLocation().m_iY_Location + 2 < Draw_Manager.GetHeight())
					Player_Manager.LocationChange(Player_Manager.GetPlayerLocation().m_iX_Location, Player_Manager.GetPlayerLocation().m_iY_Location + 1);
				break;
			case KEY_ENTER: //�δ����� �޴�â�ҷ�����
				InDungeonSelectManipulation();
				ReDrawMap();
				Monster_Manager.ChangeMonsterMakeClock(clock());
				break;
			case KEY_ESC: //���ӵ��� ��������
				m_bGameEndFlag = true;
				return;
			default:
				break;
			}
			Player_Manager.DrawCharacter();
		}
		if (Monster_Manager.GetInDungeonMonsterVectorFileSize() != NULL)
		{
			if (Monster_Manager.MonsterJowCheck(Player_Manager.GetPlayerLocation()) != false)
			{
				BattlePhase(Monster_Manager.MonsterJowCheck(Player_Manager.GetPlayerLocation()));
				if (m_bPlayerDeadFlag == true)
				{
					Monster_Manager.ResetMonsterInDungeon();
					m_bPlayerDeadFlag = false;
					return;
				}
				Monster_Manager.FieldMonsterDie(Player_Manager.GetPlayerLocation());
				ReDrawMap();
				Monster_Manager.ChangeMonsterMakeClock(clock());
			}
		}
	}
}

void GameManager::InDungeonSelectManipulation()
{
	system("cls");
	int Select;
	Draw_Manager.DrawBorder();
	ShowInDungeonMenu();

	cin >> Select;
	switch (Select)
	{
	case INDUNGEON_eCHARACTERINFORMATION :
		CharacterMenuManipulation();
		break;
	case INDUNGEON_eDUNGEONEXIT :
		Monster_Manager.ResetMonsterInDungeon();
		m_bExitDungeonFlag = true;
		return;
	case INDUNGEON_eRETURNTODUNGEON :
		return;
	default :
		break;
	}
}

void GameManager::ReDrawMap()
{
	system("cls");
	Draw_Manager.DrawBorder();
	ShowInDungeonKeyRule();
	Player_Manager.DrawCharacter();
	Monster_Manager.DrawMonster();
}

void GameManager::BattlePhase(int MonsterNumber)
{
	//int BattleTurn = 1;
	int Select;
	int MemoPlayerOriginalSpeed = Player_Manager.GetAttackSpeed(); //��������϶� ���ǵ尪�� �ٲ�⿡ �������ǵ尪 ���
	int SpecialDropItemNumber = 0; //����Ⱦ����۵�ӽ� �׾������� ��ȣ 0�Ͻÿ��� ����ȵȰ��Դϴ�
	bool PhaseSkipFlag = false; //�ݵ��� ��뿩��
	bool BattleResult = false;
	Monster_Manager.SetJowMobData(MonsterNumber);
	Weapon_Manager.SetWeaponAtkShieldSkillByNumber(Player_Manager.GetEquipWeaponNumber());
	//Weapon EquipWeaponData;
	//Weapon_Manager.SetEquipWeaponData(Player_Manager.GetEquipWeaponNumber());
	Monster Mob = Monster_Manager.GetJowMobData();
	system("cls");
	Draw_Manager.DrawBorder();
	while (1)
	{
		system("cls");
		//Draw_Manager.DrawMidText_PlusTailInt(BattleTurn, "����� : ", Draw_Manager.GetWidth(), 2);
		//Draw_Manager.DrawMidText(Monster_Manager.GetJowMobData().GetCharacterImage(), Draw_Manager.GetWidth(), 2);
		Draw_Manager.DrawMidText_PlusTailInt(Mob.GetLevel(), Monster_Manager.GetJowMobData().GetName() + " LV : ", Draw_Manager.GetWidth(), 2);
		Draw_Manager.DrawMidText_PlusTailInt(Mob.GetHP(), "����ü�� : ", Draw_Manager.GetWidth(), 3);

		Draw_Manager.DrawMidText("VS", Draw_Manager.GetWidth(), 5);

		//Draw_Manager.DrawMidText(Player_Manager.GetCharacterImage(), Draw_Manager.GetWidth(), 6);
		Draw_Manager.DrawMidText_PlusTailInt(Player_Manager.GetLevel(), Player_Manager.GetName() + " LV : ", Draw_Manager.GetWidth(), 7);
		Draw_Manager.DrawMidText_PlusTailInt(Player_Manager.GetHP(), "����ü�� : ", Draw_Manager.GetWidth(), 8);
		Draw_Manager.DrawMidText_PlusTailInt(Player_Manager.GetCharacterMP(), "�������� : ", Draw_Manager.GetWidth(), 9);
		//�ݵ����� ���� �÷��̾ ������������ 
		if (PhaseSkipFlag == true)
		{
			PhaseSkipFlag = false;
			DontMoveByCoolTime();
			BattlePhase_MonsterDammage(&Mob, Weapon_Manager.GetEquipWeaponShield());
			if (Player_Manager.GetHP() <= 0)
			{
				if (PlayerDeadByMonster(MemoPlayerOriginalSpeed) == true)
					return;
			}
		}


		Draw_Manager.DrawMidText("===============================================", Draw_Manager.GetWidth(), 12);
		Draw_Manager.DrawMidText("1.�⺻���� 2.��ų���� 3.��������", Draw_Manager.GetWidth(), 13);
		Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 14);
		cin >> Select;

		Draw_Manager.DrawMidText("===============================================", Draw_Manager.GetWidth(), 15);
		switch (Select)
		{
		case BATTLEPHASESELECT_eNORMALATTACK:
			//Player_Manager.GetSkillData().SetSkillData(SKILLNAME_eNORMALATTACK);
			BattleDammageCalculate(&Mob, Weapon_Manager.GetEquipWeaponAtk(), Weapon_Manager.GetEquipWeaponShield(), Weapon_Manager.GetEquipWeaponSKillData(), Player_Manager.GetSkillData().GetSkillAllDataBySkillNumber(SKILLNAME_eNORMALATTACK));
			break;
		case BATTLEPHASESELECT_eSKILLATTACK:
			int SkillSelect;
			Player_Manager.GetSkillData().UseSkillInBattlePhase();
			cin >> SkillSelect;
			if (SkillSelect == SKILLNAME_eRETURN)
				break;
			//Player_Manager.GetSkillData().SetSkillData(SkillSelect);
			if (Player_Manager.GetSkillData().GetSkillAllDataBySkillNumber(SkillSelect).GetSkillLevel() > 0)
			{
				if (Player_Manager.Use_Mp(Player_Manager.GetSkillData().GetSkillAllDataBySkillNumber(SkillSelect).GetSkillMPCost()) == true)
				{
					BattleDammageCalculate(&Mob, Weapon_Manager.GetEquipWeaponAtk(), Weapon_Manager.GetEquipWeaponShield(), Weapon_Manager.GetEquipWeaponSKillData(), Player_Manager.GetSkillData().GetSkillAllDataBySkillNumber(SkillSelect));
					if (Player_Manager.GetSkillData().GetSkillAllDataBySkillNumber(SkillSelect).GetSkillCoolTime() != 0)
						PhaseSkipFlag = true;
				}
				else
				{
					Player_Manager.MPError();
					break;
				}
			}
			else
				Player_Manager.GetSkillData().SkillUseError();
			break;
		case BATTLEPHASESELECT_eRUNFROMBATTLE:
			return;
		}

		//������°��ɽ� ���ǵ尪�϶�
		if (Mob.GetLifeStatus() == LIFESTATUS_eON_PARALYSIS)
			Mob.ChangeAttackSpeedByParalysys(9999);
		if (Player_Manager.GetLifeStatus() == LIFESTATUS_eON_PARALYSIS)
			Player_Manager.ChangeAttackSpeedByParalysys(9999);
		
		
		//�Ѵ� ���̳� ��Ÿ���� ������ �ǰ� 0�̵Ǿ����ÿ� �÷��̾ ��������
		if (Mob.GetHP() <= 0)
		{
			Mob.LifeStatusChange(LIFESTATUS_eDEAD);
		}
		else if (Player_Manager.GetHP() <= 0)
		{
			Player_Manager.LifeStatusChange(LIFESTATUS_eDEAD);
		}

		//�������� �������� ���(����)â���
		if (PlayerDeadByMonster(MemoPlayerOriginalSpeed) == true)
			return;
		if (Mob.GetLifeStatus() == LIFESTATUS_eDEAD)
		{
			//���� ������
			int RandomMoney = 0;
			while (1)
			{
				RandomMoney = (rand() % Monster_Manager.GetJowMobData().GetMonsterGiveMoney());
				if (RandomMoney >= Monster_Manager.GetJowMobData().GetMonsterGiveMoney() / 2)
					break;
			}
			Player_Manager.GetGold(RandomMoney);
			//������Ư�������� ������úκ� �ߺ�ȹ��� ��ǰ������ ����ȹ��
			SpecialDropItemNumber = Monster_Manager.MonsterSpecialItemDrop(Monster_Manager.GetJowMobData().GetMonsterNumber());
			if (Weapon_Manager.FindWeaponGotFlag(SpecialDropItemNumber) == true)
			{
				Player_Manager.GetGold(Weapon_Manager.WeaponNumberToWeaponPride(SpecialDropItemNumber));
			}
			else 
				Weapon_Manager.WeaponGet(SpecialDropItemNumber);
			//�������ͼ�ȯ���������úκ�
			Monster_Manager.BossSummonCountUp();
			if (Monster_Manager.GetJowMobData().GetClassNumber() == CLASS_eBOSSMONSTER)
				Monster_Manager.ResetBossSummonCount();
			//�¸��������̽� 
			ShowVictory(Monster_Manager.GetJowMobData().GetMonsterGiveExp(), RandomMoney, SpecialDropItemNumber);
			//����ġȹ��
			Player_Manager.Get_EXP(Monster_Manager.GetJowMobData().GetMonsterGiveExp());
			Player_Manager.ChangeAttackSpeedByParalysys(MemoPlayerOriginalSpeed);
			return;
		}
	}
}

bool GameManager::PlayerDeadByMonster(int MemoPlayerOriginalSpeed)
{
	if (Player_Manager.GetLifeStatus() == LIFESTATUS_eDEAD)
	{
		Player_Manager.GetDeadPenalty();
		YouDied();
		Player_Manager.LifeStatusChange(LIFESTATUS_eNORMAL);
		Player_Manager.ChangeAttackSpeedByParalysys(MemoPlayerOriginalSpeed);
		m_bPlayerDeadFlag = true;
		return true;
	}
	return false;
}

void GameManager::BattleDammageCalculate(Monster* JowMob, int WeaponAtk, int WeaponShield, WeaponSkill WeaponSkillData, Skill UseSKill)
{
	int TrueDammage;
	//���񵶻���üũ(��������Ͻ� ���ǵ尪�� 2�谡�Ǿ� ������(��ġ���������ϼ���))(���� �ִ�ü���� 5�������ӵ�����)
	//���ǵ��ġ�� �������� ����
	//���ǵ尡 ������ �÷��̾����� ����
	
	//�÷��̾��
	if (Player_Manager.GetAttackSpeed() <= Monster_Manager.GetJowMobData().GetAttackSpeed())
	{
		BattlePhase_PlayerDammage(JowMob, WeaponAtk, WeaponSkillData, UseSKill);
		if (JowMob->GetLifeStatus() == LIFESTATUS_eDEAD)
		{
			cout << endl;
			Draw_Manager.DrawPauseByGameScreen(12);
			return;
		}
		else
			Draw_Manager.DrawPauseByGameScreen(12);
		BattlePhase_MonsterDammage(JowMob, WeaponShield);
		Draw_Manager.DrawPauseByGameScreen(12);
	}
	//���ͼ���
	else if (Player_Manager.GetAttackSpeed() > Monster_Manager.GetJowMobData().GetAttackSpeed())
	{
		BattlePhase_MonsterDammage(JowMob, WeaponShield);
		if (Player_Manager.GetLifeStatus() == LIFESTATUS_eDEAD)
		{
			cout << endl;
			Draw_Manager.DrawPauseByGameScreen(12);
			return;
		}
		else
			Draw_Manager.DrawPauseByGameScreen(12);
		BattlePhase_PlayerDammage(JowMob, WeaponAtk, WeaponSkillData, UseSKill);
		Draw_Manager.DrawPauseByGameScreen(12);

	}

	return;
}

void GameManager::BattlePhase_MonsterDammage(Monster* JowMob, int WeaponShield)
{
	int TrueDammage = 0;
	//�÷��̾��� �������Դ¹��
	if (JowMob->GetAtk() - Player_Manager.GetShield() - WeaponShield <= 0)
		TrueDammage = 0;
	else
		TrueDammage = JowMob->GetAtk() - Player_Manager.GetShield() - WeaponShield;

	Player_Manager.Get_Dammage(TrueDammage);
	Draw_Manager.DrawBattleDammage(Player_Manager.GetName() + "��(��) ", TrueDammage, "�� �������� " + Monster_Manager.GetJowMobData().GetName() + "�� ���� �Ծ���", Draw_Manager.GetWidth(), 10);

	//�������Ͻ� �������� ���� ���������
	if (JowMob->GetLifeStatus() == LIFESTATUS_eON_POISON)
	{
		JowMob->Get_Dammage(JowMob->GetMaxHP() /20 );
		Draw_Manager.DrawBattleDammage(JowMob->GetName() + "�� ��������", JowMob->GetMaxHP() / 20, "�� ���������Ծ���", Draw_Manager.GetWidth(), 11);
	}
}

void GameManager::BattlePhase_PlayerDammage(Monster* JowMob, int WeaponAtk, WeaponSkill WeaponSkillData, Skill UseSKill)
{
	int TrueDammage = 0;
	if ((Player_Manager.GetAtk() + WeaponAtk) * UseSKill.GetSkillDammagePerCent() / 100 - JowMob->GetShield() <= 0)
		TrueDammage = 0;
	else
		TrueDammage = (Player_Manager.GetAtk() + WeaponAtk) * UseSKill.GetSkillDammagePerCent() / 100;

	JowMob->Get_Dammage(TrueDammage);
	if (WeaponSkillData.GetWeaponIntrinsicEffect() == SPECIALEFFECT_ePOISON_EFFECT)
		JowMob->LifeStatusChange(LIFESTATUS_eON_POISON);
	if (WeaponSkillData.GetWeaponIntrinsicEffect() == SPECIALEFFECT_ePARAIYSIS_EFFECT)
		JowMob->LifeStatusChange(LIFESTATUS_eON_PARALYSIS);

	Draw_Manager.DrawBattleDammage(JowMob->GetName() + "��(��) ", TrueDammage, "�� �������� " + Player_Manager.GetName() + "�� ���� �Ծ���", Draw_Manager.GetWidth(), 10);
	//�������Ͻ� �������� ���� ���������
	if (Player_Manager.GetLifeStatus() == LIFESTATUS_eON_POISON)
	{
		Player_Manager.Get_Dammage(Player_Manager.GetMaxHP() / 20);
		Draw_Manager.DrawBattleDammage("�����¿�����", Player_Manager.GetMaxHP() / 20, "�� ���������Ծ���", Draw_Manager.GetWidth(), 11);
	}
}

//void GameManager::WeaponTraderManipulation()
//{
//	
//	int Select;
//	Draw_Manager.DrawBorder();
//	ShowWeaponTraderMenu();
//	cin >> Select;
//	switch (Select)
//	{
//	case WEAPONNAME_eSHORTSWORD :
//		if (Player_Manager.Use_Gold(WEAPONPRIDE_eSHORTSWORD) == true)
//		{
//			Weapon_Manager.WeaponGet(WEAPONNAME_eSHORTSWORD);
//		}
//		else
//			Player_Manager.GoldError();
//		break;
//	case WEAPONNAME_eLONGSWORD :
//		if (Player_Manager.Use_Gold(WEAPONPRIDE_eLONGSWORD) == true)
//		{
//			Weapon_Manager.WeaponGet(WEAPONNAME_eLONGSWORD);
//		}
//		else
//			Player_Manager.GoldError();
//		break;
//	case WEAPONNAME_eBUSTERSWORD :
//		if (Player_Manager.Use_Gold(WEAPONPRIDE_eBUSTERSWORD) == true)
//		{
//			Weapon_Manager.WeaponGet(WEAPONNAME_eBUSTERSWORD);
//		}
//		else
//			Player_Manager.GoldError();
//		break;
//	default :
//		break;
//	}
//}


void GameManager::CharacterMenuManipulation()
{
	int MemoWeaponNumber = 0;
	int Select;
	while (1)
	{
		Draw_Manager.DrawBorder();
		ShowCharacterMenu();
		cin >> Select;
		switch (Select)
		{
		case CHARACTERINFORMATION_eSTATUS:
			Player_Manager.ShowTotalStatus();
			break;
		case CHARACTERINFORMATION_eUPGRADESTATUS:
			Player_Manager.UpGradeStatusPoint();
			break;
		case CHARACTERINFORMATION_eSKILL:
			Player_Manager.UpgradeSkill_PlusPlayerData();
			break;
		case CHARACTERINFORMATION_eCLASSCHANGE :
			Player_Manager.ShowClassChange();
			break;
		case CHARACTERINFORMATION_eWEAPON :
			MemoWeaponNumber = Weapon_Manager.WeaponChange(Player_Manager.GetEquipWeaponNumber(), Player_Manager.GetLevel());
			if (MemoWeaponNumber != 0)
				Player_Manager.ItemEquip(MemoWeaponNumber);
			break;
		case CHARACTERINFORMATION_eRETURN :
			return;
		default :
			break;
		}
	}
}

//void GameManager::ChangeWeaponMenu()
//{
//	int Select;
//	while (1)
//	{
//		Weapon_Manager.ShowWeaponMenu(Player_Manager.GetEquipWeaponNumber());
//		cin >> Select;
//		switch (Select)
//		{
//		case WEAPONNAME_eSHORTSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eSHORTSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eSHORTSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eLONGSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eLONGSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eLONGSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eBUSTERSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eBUSTERSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eBUSTERSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eGOBKINGSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eGOBKINGSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eGOBKINGSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eMISRILLSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eMISRILLSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eMISRILLSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eDEMONKINGSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eDEMONKINGSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eDEMONKINGSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eDRAGONSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eDRAGONSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eDRAGONSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eETERNALSWORD :
//			if (Weapon_Manager.FindWeaponEquipLimitLevel(WEAPONNAME_eETERNALSWORD) <= Player_Manager.GetLevel())
//				ChangeWeapon(WEAPONNAME_eETERNALSWORD);
//			else
//				Weapon_Manager.ShowWeaponEquipError();
//			break;
//		case WEAPONNAME_eRETURN :
//			return; 
//		default :
//			break;
//		}
//	}
//}

void GameManager::ChangeWeapon(int WeaponNumber)
{

	if (Weapon_Manager.FindWeaponGotFlag(WeaponNumber) == true)
		Player_Manager.ItemEquip(WeaponNumber);
	else
		Weapon_Manager.ShowWeaponEquipError();
}

//void GameManager::UpgradeSkill()
//{
//	int Select;
//	while (1)
//	{
//		Skill_Manager.ShowAndUpgradeSkill(Player_Manager.GetClassNumber(), Player_Manager.GetSkillPoint());
//		cin >> Select;
//		switch (Select)
//		{
//		case SKILLNAME_ePOWERSLASH:
//			if (Player_Manager.Use_SkillPoint() == true)
//				Skill_Manager.SkillLevelUp(SKILLNAME_ePOWERSLASH);
//			break;
//		case SKILLNAME_eCOMBOASSULT:
//			if (Player_Manager.Use_SkillPoint() == true)
//				Skill_Manager.SkillLevelUp(SKILLNAME_eCOMBOASSULT);
//			break;
//		case SKILLNAME_eCOMBOEXTINGSION:
//			if (Player_Manager.Use_SkillPoint() == true)
//				Skill_Manager.SkillLevelUp(SKILLNAME_eCOMBOEXTINGSION);
//			break;
//		case SKILLNAME_eRETURN:
//			return;
//		default: break;
//		}
//	}
//}


void GameManager::ShowStartMenu()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("RPG Game", Draw_Manager.GetWidth(), 7);
	Draw_Manager.DrawMidText("1. NewGame", Draw_Manager.GetWidth(), 10);
	Draw_Manager.DrawMidText("2. LoadGame", Draw_Manager.GetWidth(), 13);
	Draw_Manager.DrawMidText("3. EndGame", Draw_Manager.GetWidth(), 16);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 19);
}

void GameManager::ShowVictory(int GiveExp, int Gold, int SpecialItem)
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("���Ϳ��Լ� �¸��Ͽ����ϴ�.", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText_PlusHeadInt(GiveExp, "�� ����ġ�� ȹ���Ͽ����ϴ�.", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawMidText_PlusHeadInt(Gold, "�� ��带 ȹ���Ͽ����ϴ�.", Draw_Manager.GetWidth(), 17);
	if(SpecialItem != 0)
	Draw_Manager.DrawMidText_TwoString(Weapon_Manager.WeaponNumberToWeaponName(SpecialItem), "�� Ư���������� ȹ���Ͽ����ϴ�.", Draw_Manager.GetWidth(), 19);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 21);
	cout << endl;
	Draw_Manager.DrawPauseByGameScreen(22);
	//DrawMidText_PlusInt(KillNum, "�� �ش���͸� ����Ͽ����ϴ�.", m_iWidth, 18);
}

void GameManager::YouDied()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("YOU DIED", Draw_Manager.GetWidth(), 13);
	Draw_Manager.DrawMidText("Continue?(press AnyKey)", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawMidText("��Ƽ���� �г�Ƽ��", Draw_Manager.GetWidth(), 17);
	Draw_Manager.DrawMidText("����ġȹ�淮 �϶� & ü�¸���ġ�������� ��Ȱ", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawPauseByGameScreen(20);
}

void GameManager::ShowInDungeonMenu()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("1.ĳ��������", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText("2.����������", Draw_Manager.GetWidth(), 15);
	Draw_Manager.DrawMidText("3.�������εǵ��ư���", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 20);
}

void GameManager::ShowCharacterMenu()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("1.�������ͽ�", Draw_Manager.GetWidth(), 8);
	Draw_Manager.DrawMidText("2.�������ͽ�����", Draw_Manager.GetWidth(), 10);
	Draw_Manager.DrawMidText("3.��ų������Ȳ�� ����", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText("4.�����ϱ�", Draw_Manager.GetWidth(), 14);
	Draw_Manager.DrawMidText("5.����������", Draw_Manager.GetWidth(), 16);
	Draw_Manager.DrawMidText("6.�ǵ��ư���", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 20);
}

void GameManager::ShowOutDungeonMenu()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("1.����������� ���Ѵ�", Draw_Manager.GetWidth(), 4);
	Draw_Manager.DrawMidText("2.�̳�Ÿ��罺�� ������ ���Ѵ�", Draw_Manager.GetWidth(), 6);
	Draw_Manager.DrawMidText("3.���ֹ����������� ���Ѵ�", Draw_Manager.GetWidth(), 8);
	Draw_Manager.DrawMidText("4.���ǵ����� ���Ѵ�", Draw_Manager.GetWidth(), 10);
	Draw_Manager.DrawMidText("5.�������", Draw_Manager.GetWidth(), 12);
	Draw_Manager.DrawMidText("6.ĳ��������", Draw_Manager.GetWidth(), 14);
	Draw_Manager.DrawMidText("7.��������", Draw_Manager.GetWidth(), 16);
	Draw_Manager.DrawMidText("8.���Ӻҷ�����", Draw_Manager.GetWidth(), 18);
	Draw_Manager.DrawMidText("9.��������", Draw_Manager.GetWidth(), 20);
	Draw_Manager.DrawMidText("���� : ", Draw_Manager.GetWidth(), 22);
}

void GameManager::ShowSaveAndLoadComplete()
{
	system("cls");
	Draw_Manager.DrawBorder();
	Draw_Manager.DrawMidText("���� ����/�ε� �Ϸ�", Draw_Manager.GetWidth(), 15);
	//Draw_Manager.DrawMidText("�ƹ�Ű�������� ����â���� �̵�", Draw_Manager.GetWidth(), 18);
	cout << endl;
	Draw_Manager.DrawPauseByGameScreen(18);
}

void GameManager::ShowInDungeonKeyRule()
{
	Draw_Manager.DrawMidText("Enter Key�� ���� �޴�â�����̵�", Draw_Manager.GetWidth(), Draw_Manager.GetHeight()+1);
	Draw_Manager.DrawMidText("Ű�������Ű : ĳ�����̵�", Draw_Manager.GetWidth(), Draw_Manager.GetHeight() + 2);
	Draw_Manager.DrawMidText("ESC : ��������(��ó��â����)", Draw_Manager.GetWidth(), Draw_Manager.GetHeight() + 3);
}

void GameManager::DontMoveByCoolTime()
{
	Draw_Manager.DrawMidText("�ݵ����� ���� �����ϼ� ����", Draw_Manager.GetWidth(), 11);
	cout << endl;
	Draw_Manager.DrawPauseByGameScreen(12);
	return;
}

GameManager::~GameManager()
{

}