#include "Person.h"

void Person::SavePersonData()
{
	cout << "당신의 성별은?" << endl;
	cin >> m_strGender;
	cout << "당신의 나이는?" << endl;
	cin >> m_iAge;
	cout << "당신의 이름은?" << endl;
	cin >> m_strName;
}

void Person::ShowPersonData()
{
	cout << "성별 :" << m_strGender << endl;
	cout << "나이 :" << m_iAge << endl;
	cout << "이름 :" << m_strName << endl;
}

