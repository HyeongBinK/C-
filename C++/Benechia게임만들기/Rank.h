#pragma once
#include "BaseHeader.h"

struct Data
{
	string PlayerName;
	int Score;
	int Stage;
};


class Rank
{
private:
	vector<Data> Records;
protected:
public:
	void SaveRank(string name, int score, int stage); //����
	int LoadRank(); //�ε�ε� ������ 1 ���н� 0
	//void SortRecords(); //��� ������������(�������� ���ھ�)
	void ShowRank(); //��Ϻ����ֱ�
	void ClearRankData(); //���ӿ��������ҋ� ���ǹ��� �ɾ Ȥ�� �ܿ������� �����ִٸ� Ŭ����
};

