#pragma once
#include"BaseHeader.h"
#include"DrawManager.h"
#include"PlayerManager.h"
#include"MonsterManager.h"
#include"WeaponManager.h"

#define SAVELOADSLOTMAX 10

enum OUTDUNGEON
{
	OUTDUNGEON_eGOBSHOME =1,
	OUTDUNGEON_eMINOTASHOME,
	OUTDUNGEON_eCULSEDTEMPLE,
	OUTDUNGEON_eDRAGONNEST,
	OUTDUNGEON_eWEAPONTRADER,
	OUTDUNGEON_eCHARACTERINFORMATION,
	OUTDUNGEON_eGAMESAVE,
	OUTDUNGEON_eGAMELOAD,
	OUTDUNGEON_eENDGAME
};

enum INDUNGEON
{
	INDUNGEON_eCHARACTERINFORMATION = 1,
	INDUNGEON_eDUNGEONEXIT,
	INDUNGEON_eRETURNTODUNGEON
};

enum CHARACTERINFORMATION
{
	CHARACTERINFORMATION_eSTATUS = 1,
	CHARACTERINFORMATION_eUPGRADESTATUS,
	CHARACTERINFORMATION_eSKILL,
	CHARACTERINFORMATION_eCLASSCHANGE,
	CHARACTERINFORMATION_eWEAPON,
	CHARACTERINFORMATION_eRETURN,

};

enum BATTLEPHASESELECT
{
	BATTLEPHASESELECT_eNORMALATTACK =1,
	BATTLEPHASESELECT_eSKILLATTACK,
	BATTLEPHASESELECT_eRUNFROMBATTLE
};

enum BATTLERESULT
{
	BATTLERESULT_eNOTDEAD =1,
	BATTLERESULT_ePLAYERDEAD,
	BATTLERESULT_eMONSTERDEAD,
};

class GameManager
{
private:
	DrawManager Draw_Manager; //�׸�������
	PlayerManager Player_Manager; //�÷��̾��ĳ���� ������
	MonsterManager Monster_Manager; //���Ͱ�����
	WeaponManager Weapon_Manager; //���������
	bool m_bPlayerDeadFlag; //�⺻������ false �÷��̾ ������ Ʈ��κ�ȯ�� ���������γ����� �ٽ� false �� ��ȯ 
	bool m_bGameEndFlag; //����üũ�÷���
	bool m_bExitDungeonFlag; //����Ż��üũ�÷���
protected:

public:
	GameManager();
	void PlayGame(); //���ӽ���(������, ���������ͷε��ؼ� �����ϱ� ��) ������ ���ۺκ�
	
	//����������ε�
	void NewGame(); // ���ο���ӽ���(�ʱⵥ���ͷε�) 
	void SaveGame(int i); //��������
	void LoadGame(int i); //���ӷε��ϱ�
	void DataClear(); //�����߰��ε�� ���������� Ŭ����
	
	//���̺�� �ε� ����
	void SaveSlot(); //���̺꽽��â�ٿ�� ��� ���̺�(����������ʾ����ÿ� ��������� ���̺�)(�������ִٸ� �����)
	bool LoadSlot(); //�ε彽��â�ٿ�� ��� �ش����� �ε�(�ش������̾��ٸ� �ε�Ұ�)

	//������(��������)
	void GameManipulation(); //��ü���� ��������(�Ʒ� �׸���� ��)
	void OutDungeonManipulation(); //������ ����(����, ĳ���ͽ������ͽ�â ��ñ��)
	void InDungeonSelectManipulation(); //������ �޴�����
	//void WeaponTraderManipulation(); //��������� ����
	void CharacterMenuManipulation(); //ĳ��������â����

	//�δ���
	void InDungeonManipulation(int MonsterNumber); //������ ���ͻ����� ĳ�����̵��� �������� ����
	void BattlePhase(int MonsterNumber);
	void BattleDammageCalculate(Monster* JowMob, int WeaponAtk, int WeaponShield, WeaponSkill WeaponSkillData, Skill UseSkill); //���͹�Ʋ�� ���������ý���(ĳ���� ���� + ���� +��ų��)
	void BattlePhase_MonsterDammage(Monster* JowMob, int WeaponShield); //���Ͱ� �÷��̾������ִµ�����
	void BattlePhase_PlayerDammage(Monster* JowMob, int WeaponAtk, WeaponSkill WeaponSkillData, Skill UseSkill); //�÷��̾ ���Ϳ��� �ִµ�����
	void ReDrawMap(); //�δ������� �޴�â�ٳ������ �������·� �ǵ����±��
	bool PlayerDeadByMonster(int MemoPlayerOriginalSpeed); //�÷��̾� �ǰ� 0���ϰ� �ɽý���(�÷��̾ �ݵ��Ͽ� ���������ֱ⿡ �Ȱ����ڵ� 2�����°� ������)

	//�������̽�
	void ShowVictory(int GiveExp, int Gold, int SpecialItem); //����óġ�� �¸�ǥ��
	void YouDied(); //ĳ���ͻ���� ������ǥ��
	void ShowStartMenu(); //���ӽ��۸޴�
	void ShowOutDungeonMenu(); //�������ù� ���� �ε� â
	void ShowInDungeonMenu(); //�δ��� �޴�â
	void ShowCharacterMenu(); //ĳ������������ â
	//void ShowWeaponTraderMenu(); //��������޴� â
	//void ShowWeaponNameAndPride(int WeaponNumber, int Line); //��������� ���Ⱑ�ݰ� �����̸� ��
	void ShowSaveAndLoadComplete(); //���̺�ε�� �Ϸ� ǥ��â
	void ShowInDungeonKeyRule(); //�δ����� ����Ű����
	//void UpgradeSkill(); //��ų�ʿ��ִ°Ը´°Ű����� ������ ��ų����Ʈ������ �����;ߵǱ⿡ ��Ŭ������ ��ġ
	//void ChangeWeaponMenu(); //�����ʿ��ִ°Թٶ����ϳ� ������ �������� ���������� �����ؾ��ϱ⿡ �ش� Ŭ������ ��ġ��Ŵ
	void ChangeWeapon(int WeaponNumber); //�������⺯��
	void DontMoveByCoolTime(); //�ݵ������� �����ϼ����� ǥ���ϴ�â
	void ScreenSizeSetting(); //����ȭ�����
	~GameManager();
};

