#pragma once
#include "BaseHeader.h"
#include "WardManager.h"
#include "Ward.h"
#include "Rank.h"

#define FINALSTAGE 10
#define NAMELENGTHLIMIT 10
#define ATTACKWARDLENGTHLIMIT 20

enum ITEM
{
	ITEM_eENEMYSPEEDUP = 1,
	ITEM_eENEMYSPEEDDOWN,
	ITEM_eENEMYSTOP,
	ITEM_eENEMYCLEAR
};

//PlayClass����
class GameManager
{
private :
	string m_strPlayerName; //�÷��̾��̸�
	int m_iPlayerLife; //�÷��̾������(10���� ���� �����ڿ��� �ָ� ���ӿ����� �ٽ� 10���� �ʱ�ȭ) 0�̵Ǹ� ���ӿ���
	int m_iScore; //����
	int m_iStage; //���޽�������
	bool m_bGameClearFlag; //���Ӹ�������������Ŭ����� Ʈ��� �ٲ�
	int m_iEnemySpeedUpItem; //���ӵ���¾����۰���
	int m_iEnemySpeedDownItem; //���ӵ��ٿ� �����۰���
	int m_iEnemyStopItem; //����������۰���
	int m_iEnemyClearItem; //��������(������ ����������) �����۰���
	int m_iScreenWidth; //ȭ�� ����ũ��(ȭ��ũ�⺯������ �����Ƿ� �����ڿ��� ��ο�Ŵ����� ����� �⺻��(define WIDTH) �ٿ���)
	int m_iScreenHeight; //ȭ�� ����ũ��(ȭ��ũ�⺯������ �����Ƿ� �����ڿ��� ��ο�Ŵ����� ����� �⺻��(define HEIGHT) �ٿ���)
	WardManager Ward_Manager;
	Rank Rank_Manager;
protected :
public:
	GameManager();
	void GameSelect(); //�������α׷� ����� �������� ���ӽ��� ��ũ ���� ������ ���(�Լ�)
	void GameStart(); //���ӽ���(����ġ�ư���) //�ϴÿ��� ���ܾ�������°Ÿ� Ÿ�����ؼ� �μ��°���
	void MakeName(); //�̸������ �̺�Ʈ
	void StageChange(); //�������� ������ ������������
	void ShowRank(); //��ŷ�����ֱ� (�̸� �������� ������)
	void ShowStage(); // �� �������� ���۽� ȭ�� ������ Stage1 ������ ǥ��
	bool GameOverCheck(); //�������� 0�̵Ǹ� ���ӿ���ǥ�ÿ��Բ� sleep�̳� pause�� �ɾ ����select â���� �̵�
	void ShowStory(); //���ӽ��۽� ���丮���� sŰ�� ���� ��ŵ����
	void ShowStatus(); //����ȭ���ϴ��� ���������� ���� �̸��� �����ִ� ���(�Լ�)
	void SetToDefault(); //���ӽ������� �̸� ��Ÿ��� ����Ʈ���·�
	~GameManager();

};

