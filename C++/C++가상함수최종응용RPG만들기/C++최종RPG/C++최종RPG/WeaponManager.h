#pragma once
#include "BaseHeader.h"
#include "DrawManager.h"
#include "Weapon.h"
#include "Sword.h"
#include "TwoHandSword.h"

enum WEAPONTRADER_KEY
{
	WEAPONTRADER_KEY_eBEFOREPAGE =7,
	WEAPONTRADER_KEY_eNEXTPAGE,
	WEAPONTRADER_KEY_eRETURN
};

class WeaponManager 
{
private:
	int m_iMemoWeaponAtk;
	int m_iMemoWeaponShield;
	WeaponSkill MemoWeaponSkill;

	DrawManager Draw_Manager;
	//Weapon *tmp;
	//vector<tmp> WeaPons;
	//vector<Weapon> *WeaPons;
	vector<Weapon*> WeaPons;
	//Weapon EquipWeaponData;
protected:

public:
	WeaponManager();
	//�����Ͱ���
	void LoadWeaponsData(string LoadFileName); //�����ۻ��ºҷ�����
	void SaveWeaponsData(string SaveFileName); //�����ۻ�������
	void ClearWeaponData(); //��������ó� �ε�� �����ͻ���

	void WeaponGet(int WeaponNumber); //����ȹ��� ����ȹ����úҺ��� true�� ��ȯ�ϸ� ���������ϰԲ�
	void ShowGetorNot(int WeaponNumber); //���⺸������ �˼��ְԲ�ǥ�� �ϱ����Ѻ���
	//void SetEquipWeaponData(int WeaponNumber); //������ ������ ��������� ������
	void SetWeaponAtkShieldSkillByNumber(int WeaponNumber); //�����ѹ����� ������ �����ȣ�� ��ȸ�Ͽ� ���ݷ� ���� ��ġ���� ����Ŵ 
	bool FindWeaponGotFlag(int WeaponNumber); //���⺸�����θ� �����ȣ�� Ȯ���Ͽ� ������ Ʈ�� ������ false ��ȯ
	int FindWeaponEquipLimitLevel(int WeaponNumber); //������ ���������� �����ȣ�� �����ͼ� ���ⷹ�����Ѱ��� ��ȯ
	
	int WeaponTrader(int PlayerGold); //��������ý���
	bool BuyWeapon(int PlayerGold, int WeaponPride); //�������Ҷ� ��尡����ϸ� ���⸦ ȹ���ϰ� ��尡 �����ϸ� ������â ǥ���ϰԲ�
	//void ShowWeaponNameAndPride(Weapon WeaponData, int Line); //��������� ���Ⱑ�ݰ� �����̸� ��
	void GoldError(); //�������ҽ� ǥ�õǴ� ����â
	int WeaponChange(int EquipWeaponNumber, int PlayerLevel); //���⺯��â

	void ShowWeaponEquipError(); //���¹��⸦ �����Ϸ������� ǥ�õǴ� â
	
	string WeaponNumberToWeaponName(int WeaponNumber); //�����ȣ�� �����̸����� ��ȯ
	int WeaponNumberToWeaponPride(int WeaponNumber); //�����ȣ�� ���Ⱑ������ ��ȯ

	/*inline Weapon GetEquipWeaponData()
	{
		return EquipWeaponData;
	}*/
	inline int GetEquipWeaponAtk()
	{
		return m_iMemoWeaponAtk;
	}
	inline int GetEquipWeaponShield()
	{
		return m_iMemoWeaponShield;
	}
	inline WeaponSkill GetEquipWeaponSKillData()
	{
		return MemoWeaponSkill;
	}
	~WeaponManager();
	
};

