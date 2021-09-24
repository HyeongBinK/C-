#include "PhoneNumber.h"

#define NULLSPACE 1
#define BARSPACE 2
#define NULL 0


enum SpaceNumber
{
	eSpaceNumber_01 = 0,
	eSpaceNumber_02,

};

enum FirstBarSpace
{
	eFirstBarSpace_02 = 2,
	eFirstBarSpace_03,
};

enum SecondBarSpace
{
	eSecondBarSpace_06 = 6,
	eSecondBarSpace_07,
	eSecondBarSpace_08,

};

enum CheckLastNull
{
	eCheckLastNull_09 = 9,
	eCheckLastNull_10,
	eCheckLastNull_11,

};


PhoneNumber::PhoneNumber()
{
	string str;
	cout << "전화번호 입력 : ";
	cin >> str;
	m_chphonenumber = new char[str.length() + NULLSPACE + BARSPACE];
	strcpy(m_chphonenumber, str.c_str());
	m_isize = str.length() + NULLSPACE + BARSPACE;
	
}

bool PhoneNumber::CheckPhoneNumber()
{
	if (m_chphonenumber[eSpaceNumber_01] == '0')
	{
		if (m_chphonenumber[eSpaceNumber_02] == '1')
		{
			if (m_chphonenumber[eCheckLastNull_11] == NULL)
			return false;
			
		}
		else if (m_chphonenumber[eSpaceNumber_02] == '2')
		{
			if (m_chphonenumber[eCheckLastNull_09] == NULL)
				return false;
			
		}
		else if (m_chphonenumber[eSpaceNumber_02] >= '3' && m_chphonenumber[1] <= '6')
		{
			if (m_chphonenumber[eCheckLastNull_10] == NULL)
			return false;
			
		}
	
	}
	cout << "번호를 잘못 입력하셨습니다." << endl;
		return true;
}

void PhoneNumber::RemakePhoneNumber()
{
	m_chReMakePhoneNumber = new char[m_isize];

	for (int i = 0; i < m_isize-BARSPACE; i++)
	{
		if (m_chphonenumber[1] == '1')
			CheckBarInput(i, eFirstBarSpace_03, eSecondBarSpace_08);

		if (m_chphonenumber[1] == '2')
			CheckBarInput(i, eFirstBarSpace_02, eSecondBarSpace_06);
		
		if (m_chphonenumber[1] >= '3' && m_chphonenumber[1] <= '6')
			CheckBarInput(i, eFirstBarSpace_03, eSecondBarSpace_07);
	}

}

void PhoneNumber::CheckBarInput(int i, int FirstBar, int SecondBar)
{
	if (i >= 0 && i < FirstBar)
		m_chReMakePhoneNumber[i] = m_chphonenumber[i];
	if (i == FirstBar)
		m_chReMakePhoneNumber[i] = '-';
	if (i > FirstBar-1 && i < SecondBar-1)
		m_chReMakePhoneNumber[i + 1] = m_chphonenumber[i];
	if (i == SecondBar)
		m_chReMakePhoneNumber[i] = '-';
	if (i > SecondBar-2)
		m_chReMakePhoneNumber[i + 2] = m_chphonenumber[i];
}

void PhoneNumber::Display()
{
	cout << "완성된 번호 : " << m_chReMakePhoneNumber << endl;
}

void PhoneNumber::Deletem_chReMakePhoneNumber()
{
	if (m_chReMakePhoneNumber[m_isize] == NULL)
		delete[]m_chReMakePhoneNumber;
	else 
	delete[]m_chReMakePhoneNumber;
}

PhoneNumber::~PhoneNumber()
{
	if (m_chphonenumber[m_isize] == NULL)
		delete[] m_chphonenumber;
	else
		return;
}
