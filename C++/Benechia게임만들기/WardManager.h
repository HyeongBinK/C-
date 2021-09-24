#pragma once
#include "BaseHeader.h"
#include "Ward.h"

#define FIRSTSTAGEENEMYMAKETERM 2000
#define FIRSTSTAGEENEMYSPEED 500
#define FIRSTSTAGEENEMYSCORE 100

class WardManager
{
private:
	vector<string> Wards;
	vector<Ward> Enemy;
	int m_iCurClock;
	int m_iEnemyMakeTerm;
	int m_iEnemyFallenSpeed;
	int m_iEnemyKillScore;
	bool m_iStopEnemyFallFlag; //���ÿ� false �̴ٰ� ������ ���� ��ž������ ���� �����ð� Ʈ��� ��ȯ�Ǿ� �������� ���ߴ¿뵵

protected:
public:
	WardManager();
	void LoadWards(); //�ܾ� ��������
	int MakeRandomXLocation(); //���������ҋ� ������ ��ġ�� ����
	void MakeRandomEnemy(); //���� ���������Լ�
	void FallEnemy(int* PlayerScroe, int* PlayerLife); //���� ���ϰ����Լ�
	void PlayerAttackEnenmy(string AttackWard); //�÷��̾ ������ �����ϰ� �÷��̾� �������
	void StageUp(); //��ǥ���������� �������� ��¿� ���� ���̵� ���
	void SetDefaultState(); //�ٽð��ӽ��۽� ����Ʈ���·� �ǵ����¿���
	void ClearData(); //���������ҋ� Ȥ�� ���Ͱ����� �����Ͱ����������� clear 

	//������
	void Item_SpeedUP(); //�����۱��1 : �������ǵ�����
	void Item_SpeedDown(); //�����۱��2 : �������ǵ��϶�
	void Item_StopEnemy(); //�����۱��3 : �����Ͻ�����
	void Item_ClearEnemy(); //�����۱��4 : ȭ��Ŭ����

	~WardManager();
};