#include "Student.h"

Student::Student()
{
}

void Student::SetStudent(int Number)
{
	int tmp;
	bool Pass = true;
	m_iNumber = Number+1;
	system("cls");
	cout << m_iNumber  << "�� �л� ���� "<< endl;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_iAge;
	Pass = true;
	while (Pass)
	{
		cout << "�г� : ";
		cin >> tmp;
		m_eClass = (CLASS)tmp;
		
		switch (m_eClass)
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			Pass = false;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.(1~3�г���� ����)" << endl;
			break;
		}
	
	}
	

	Pass = true;
	while(Pass)
	{
		cout << "���� : ";
		cin >> tmp;
		m_eGender = (GENDER)tmp;
		switch (m_eGender)
		{
		case GENDER_MAN :
		case GENDER_WOMAN :
			Pass = false;
			break;
		default :
			cout << "�߸� �Է��ϼ̽��ϴ�.(0�Ǵ� 1�� �Է�)" << endl;
			break;
		}
	}
	cout << m_eGender << endl;

	
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber  << "�� �л�====" << endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_iAge << endl;
	cout << "���� : ";
	switch(m_eGender)
	{
	case GENDER_MAN :
		cout << "����" << endl;
		break;
	case  GENDER_WOMAN:
		cout << "����" << endl;
		break;
	}
	cout << "�г� : " << m_eClass << endl;












}




Student::~Student()
{
}
