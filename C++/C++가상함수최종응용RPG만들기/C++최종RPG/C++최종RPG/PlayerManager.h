#pragma once
#include"BaseHeader.h"
#include"Character.h"
#include"DrawManager.h"
#include"SkillManager.h"

enum STATUS
{
	STATUS_eSTR = 1,
	STATUS_eDEX,
	STATUS_eRETURN
};

class PlayerManager :virtual public Character
{
private:
	//int m_iWidth; //������ ������ ȭ�� ����ũ��
	//int m_iHeight; //������ ������ ȭ�� ����ũ��
	int m_iMaxMP; //�ִ븶��
	int m_iMP; //���縶��
	int m_iNeedExp; //������ϴµ� �ʿ��� ����ġ��
	int m_iGetExp; //�������ġ��
	int m_iStatPoint; //��������Ʈ
	int m_iSkillPoint; //��ų����Ʈ
	int m_iStr; //�������ݷ� ���
	int m_iDex; //�������ݷ¼ҷ� ���, ���ӻ��
	int m_iOwnedGold; //ĳ���Ͱ� �������ִ� ��差 �����۰�ȭ ���Ե �Ҹ�
	int m_iEquipWeaponNumber; //�����ϰ��ִ¾�����
	Point Location;
	DrawManager Draw_Manager;
	SkillManager Skill_Manager;
protected:
public:
	PlayerManager();
	void MakePlayerName(string Name); //���ο������۽� ĳ���� �̸��Է�

	void LevelUp(); // �����
	void Use_Gold(int Gold); //���Ҹ�
	bool Use_Mp(int SkillMP); //��ų���� �����Ҹ�
	void NeedExp_Change(); //����������� ����ġ�䱸������
	void Get_EXP(int GiveExp); // ����ġ ȹ��
	void StatStatusChange(); //�� ���� �����߰��� ���� �⺻�ɷ�ġ ����
	void GetDeadPenalty(); //ĳ���ͻ���� ��Ȱ�� �޴� �г�Ƽ
	void ClassChange(int Num); //����
	void ItemEquip(int WeaponNumber); //������ ����
	void GetGold(int Gold); //���ȹ��
	void UpgradeSkill_PlusPlayerData(); //��ų�����
	// void ChangeMapSize(int Width, int Height); //�ʻ������
	
	void SavePlayerCharacter(string SaveFileName, int i); //�÷��̾��������
	void LoadPlayerCharacter(string LoadFileName, int i); //�÷��̾���ͺҷ�����
	
	//�������̽�
	void ShowTotalStatus(); //���ս������ͽ�����â
	string ClassNumbertoClassName(int ClassNumber); //�������ͽ�����â���� Ŭ������ȣ�� �̸����� ��ȯ
	void UpGradeStatusPoint(); //��������Ʈ�й�� ǥ����â
	void ShowClassChange(); //��������â
	void ShowMakeNameMenu(); //�̸������޴�
	void ShowSkillLearnError(); //����Ұ����� ��ų�� ���������� ǥ�õǴ� â
	void StatPointError(); //��������Ʈ ������ ǥ�õǴ� â
	void GoldError(); //�������� ǥ�õǴ� â
	void MPError(); //���������� ǥ�õǴ� â 
	void LocationChange(int LocationX, int LocationY); //��������� �÷��̾� ��ǥ �����߾����� �̵�
	void DrawCharacter(); //ĳ���ͱ׷��ִ� �Լ�
	void ClearSkillData();
	//void PlayerMoveinDunGeon(char* ch); //�����ȿ����� ĳ���Ϳ�����
	
	inline SkillManager GetSkillData()
	{
		return Skill_Manager;
	}

	inline int GetOwnedGold()
	{
		return m_iOwnedGold;
	}
	inline int GetCharacterMP() //ĳ�������縶������������
	{
		return m_iMP;
	}
	inline int GetCharacterMaxMP()
	{
		return m_iMaxMP;
	}
	inline int GetSkillPoint() //�������ν�ų����Ʈ��������
	{
		return m_iSkillPoint;
	}
	inline int GetEquipWeaponNumber() //�������ι����ȣ��������
	{
		return m_iEquipWeaponNumber;
	}
	inline Point GetPlayerLocation() //ĳ������ġ��ǥ��������
	{
		return Location;
	}
	~PlayerManager();
};


