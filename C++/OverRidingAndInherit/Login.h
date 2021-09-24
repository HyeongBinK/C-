#pragma once
#include"BaseHeader.h"

//#define MEMBERMAX 10
#define PASS 100
#define NOPASS 0
#define LOGIN 0 
#define LOGOUT 99
#define CONTINUE 0 
#define RETURN 98
#define PASSWORD_LENGTH_MIN 8

struct MemberData
{
	string m_strID;
	string m_strSecretNumber;
	string m_strNickName;
	int m_iAge;
	string m_strPhoneNumber;
	int m_iMilage;
	int m_iMemberNum;
};

class Login
{
private:
	int m_iMemberNum;// ���� ����� ����� ǥ��
protected:
	int m_iMemo_ID_Num; //�α��ν� �α��ε� ȸ�� ��ȣ ���
	list<MemberData> MD_L;
public:
	Login();
	void FirstMenu();
	void MakeData();
	void CheckID();
	void ShowInformation();
	void ReMakeNickName(string* NickName);
	void ReAgeInput(int *Age);
	void ReInputPhoneNumber(string* PhoneNumber);
	void DataChangeMenu();
	void DataChange();

	int inline GetMemberNum()
	{
		return m_iMemberNum;
	}
	~Login();
};
