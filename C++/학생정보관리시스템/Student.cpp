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
	cout << m_iNumber  << "번 학생 정보 "<< endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;
	Pass = true;
	while (Pass)
	{
		cout << "학년 : ";
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
			cout << "잘못 입력하셨습니다.(1~3학년까지 존재)" << endl;
			break;
		}
	
	}
	

	Pass = true;
	while(Pass)
	{
		cout << "성별 : ";
		cin >> tmp;
		m_eGender = (GENDER)tmp;
		switch (m_eGender)
		{
		case GENDER_MAN :
		case GENDER_WOMAN :
			Pass = false;
			break;
		default :
			cout << "잘못 입력하셨습니다.(0또는 1만 입력)" << endl;
			break;
		}
	}
	cout << m_eGender << endl;

	
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber  << "번 학생====" << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "나이 : " << m_iAge << endl;
	cout << "성별 : ";
	switch(m_eGender)
	{
	case GENDER_MAN :
		cout << "남자" << endl;
		break;
	case  GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
	cout << "학년 : " << m_eClass << endl;












}




Student::~Student()
{
}
