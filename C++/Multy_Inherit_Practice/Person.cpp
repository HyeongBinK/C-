#include "Person.h"

void Person::SavePersonData()
{
	cout << "����� ������?" << endl;
	cin >> m_strGender;
	cout << "����� ���̴�?" << endl;
	cin >> m_iAge;
	cout << "����� �̸���?" << endl;
	cin >> m_strName;
}

void Person::ShowPersonData()
{
	cout << "���� :" << m_strGender << endl;
	cout << "���� :" << m_iAge << endl;
	cout << "�̸� :" << m_strName << endl;
}

