#pragma once
#include"BaseHeader.h"
#include"Monster.h"
#include"DrawManager.h"

#define FIELDMAXMONSTER 10 //�ʵ峻 �������Ѽ���
#define MAXBOSSGAGE 5 //������ȯ������
#define NORMAL_MONSTER_MAKE_COOLTIME 1000 //���ͻ�����Ÿ��

class MonsterManager 
{
private:
	int m_iMonsterMakeClock; //���ͻ���Ŭ��
	int m_iFieldMonsterNum; //�ʵ��Ǹ��ͼ��� 
	int m_iBossSummonCount; //�������� �ش������ �Ϲݸ��� 5���� ó���� �ִ��Ѹ��� ����
	int m_iMonsterMakeCoolTime; //���ͻ�����Ÿ��
	DrawManager Draw_Manager;  
	vector<Monster> MonstersData; //���͵��� ������
	vector<Monster> InDungeonMonster; //�������� ������ ���͵��� ��ġ��ǥ�� ������ ������ ������
	Monster JowMobData; //������� ������ ������ ������ ��ԵǴ� Ŭ����
public:
	MonsterManager();
	void LoadMonsterData(string LoadFileName); //���͵����� �ҷ�����(���Ͱ� �������������Ƿ� �׻�Ȱ��� ���ϸ�)
	void MakeMonsterInDungeon(int MonsterNumber, Point PlayerLocation); //(�����ȿ� ���� ����)
	void DrawMonster(); //�����������ȸ��� ��ü �ٽñ׷��ֱ�(���ӳ� �޴�â, ��Ʋ������ �ٳ�ý� Ȱ��)

	void EraseMonsterData(); //���͵���������(���������)
	void ResetMonsterInDungeon(); //��������������(����������)
	void FieldMonsterDie(Point PlayerLocation); //���ͻ���� �ʵ��Ǹ��� ���ڰ���
	int MonsterSpecialItemDrop(int MonsterNumber); //����óġ�� ������ �������

	void ChangeMonsterMakeClock(int NewClock); //���ͼ�ȯ�ð�������������
	void ResetBossSummonCount(); //�������ͼ�ȯ������ ����
	void SetJowMobData(int MonsterNumber); //������� ������ ���� ��������� ������
	void BossSummonCountUp(); //����óġ�� ������ȯ���������
	int MonsterJowCheck(Point PlayerLocation); //��������� �ش���͹�ȣ����
	
	int GetInDungeonMonsterVectorFileSize()
	{
		return InDungeonMonster.size();
	}

	inline int GetFieldMonsterNumber()
	{
		return m_iFieldMonsterNum;
	}
	inline int GetBossSummonCount()
	{
		return m_iBossSummonCount;
	}

	inline int GetMonsterClock()
	{
		return m_iMonsterMakeClock;
	}
	inline Monster GetJowMobData()
	{
		return JowMobData;
	}

	~MonsterManager();
};

