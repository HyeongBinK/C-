#pragma once
#include"BaseHeader.h"
#include "WeaponSkill.h"

enum WEAPONGRADE
{
	WEAPONGRADE_eCOMMON = 0,
	WEAPONGRADE_eUNCOMMON,
	WEAPONGRADE_eRARE,
	WEAPONGRADE_eUNIQUE,
	WEAPONGRADE_eEPIC,
	WEAPONGRADE_eETERNAL
};

class Weapon
{
private:
protected:
	string m_strWeaponType; //����Ÿ��
	string m_strWeaponName; //�������̸�
	string m_strIntroduce; //�����ۼ���
	int m_iWeaponGrade; //����޿� ���� ���� �̸��� ���� �����Ϸ� ������ �̱���
	int m_iWeaponNumber; //�����ȣ
	int m_iEquipLevel; //�������ѷ���
	int m_iWeaponAtk; //������ݷ�
	int m_iWeaponSheild; // �������
	//int m_iBonusEffect; //Ư��ȿ��
	//int m_iReinForce; //��ȭ��ġ
	int m_iWeaponPride; //�����ҋ� �ʿ��� ��差, �ߺ�ȹ��� �����ҋ��ݾ��� 50���� ȹ��
	bool m_bGotFlag; //���� ����
	// int m_iOwndedNumber; //�������� //�̺����� ���Եɰ�� �ҷμ���� �������� �� ���� ����
	WeaponSkill m_ClassUniqueSkill; //������ų
public:
	Weapon();
	void InputWeaponData(string WeaponType, string Name, string Introduce, int Grade, int WeaponNumber ,
		int EquipLevel,int Atk, int Sheild, int Gold, bool GetFlag, WeaponSkill UniqueSkill);
	//�����������ֱ�
	void SaveWeaponData(ofstream &save);
	void WeaponGet(); //�����ۺ��� ���� ����
	//void ReinForce(); //�����۰�ȭ
	//��ĳ�������� �����ϴ°��� �����ֱ� ���Ͽ��߰���
	virtual string WeaponNamePlusWeaponType() = 0; //�����̸��տ� ����Ÿ�� �ؽ�Ʈ �߰��ǰԲ�(��ĳ���ú����ֱ����ѿ뵵)
	//virtual void PrintWeaponType();
/*
	�߻� Ŭ����(abstract class)
		C++������ �ϳ� �̻��� ���� ���� �Լ��� �����ϴ� Ŭ������ �߻� Ŭ����(abstract class)��� �մϴ�.

		�̷��� �߻� Ŭ������ ��ü ���� ���α׷��ֿ��� �߿��� Ư¡�� �������� ���� �Լ��� ������ ������ �� �ְ� ���ݴϴ�.

		��, �ݵ�� ���Ǿ�� �ϴ� ��� �Լ��� �߻� Ŭ������ ���� ���� �Լ��� ������ ������, �� Ŭ�����κ��� �Ļ��� ��� Ŭ���������� �� ���� �Լ��� �ݵ�� �������ؾ� �մϴ�.



		�߻� Ŭ������ ������ ���ǵ��� ���� ���� ���� �Լ��� �����ϰ� �����Ƿ�, �ν��Ͻ��� ������ �� �����ϴ�.

		���� �߻� Ŭ������ ���� ����� ���� �Ļ� Ŭ������ �����, ���� �Ļ� Ŭ�������� ���� ���� �Լ��� ��� �������̵��ϰ� ������ ��μ� �Ļ� Ŭ������ �ν��Ͻ��� ������ �� �ְ� �˴ϴ�.

		������ �߻� Ŭ���� Ÿ���� �����Ϳ� ������ �ٷ� ����� �� �ֽ��ϴ�.
*/

	inline WeaponSkill GetWeaponSKillData() //���������ų��������
	{
		return m_ClassUniqueSkill;
	}
	inline string GetWeaponName() //�����̸���������
	{
		return m_strWeaponName;
	}
	inline int GetWeaponPride() //���Ⱑ�� ��������
	{
		return m_iWeaponPride;
	}
	inline int GetWeaponNumber() //�����ȣ ��������
	{
		return m_iWeaponNumber;
	}
	inline int GetWeaponatk() //������ݷ� ��������
	{
		return m_iWeaponAtk;
	}
	inline int GetWeaponShield() //������� ��������
	{
		return m_iWeaponSheild;
	}
	inline int GetEquipLimintLevel() //�����������ѷ��� ��������
	{
		return m_iEquipLevel;
	}
	inline bool GetGotFlag() //���⺸�� ���� ��������
	{
		return m_bGotFlag;
	}
	virtual ~Weapon();
};

