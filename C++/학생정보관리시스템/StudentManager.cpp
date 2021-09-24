#include "StudentManager.h"

StudentManager::StudentManager()
{
}

void StudentManager::AddStudent()
{
	if (m_iStudentCount < STUDENT_MAX)
	{
		m_StudentList[m_iStudentCount] = new Student;
		m_StudentList[m_iStudentCount]->SetStudent(m_iStudentCount);
		m_iStudentCount++;
	}
	else
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
}

void StudentManager::ShowStudentList()
{
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i]->ShowStudent();
}

void StudentManager::ShowStudentClass()
{
	for (int i = 1; i <= 3; i++)
	{
		cout << "┌────────" << i << "학년────────┐" << endl;

		for (int j = 0; j < m_iStudentCount; j++)
		{
			if (i == m_StudentList[j]->GetClass())
				m_StudentList[j]->ShowStudent();
		}

		cout << "└───────────────────┘" << endl;

	}

}

void StudentManager::ShowMenu()
{
	system("cls");
	cout << "======학생관리 프로그램======" << endl;
	cout << "1. 학생등록" << endl;
	cout << "2. 학생목록<번호순>" << endl;
	cout << "3. 학생목록<학년순>" << endl;
	cout << "4. 학생이름 검색" << endl;
	cout << "5. 학년 검색" << endl;
	cout << "6. 마지막으로 입력한 학생삭제" << endl;
	cout << "7. 학생 전체 삭제" << endl;
	cout << "8. 종료" << endl;
	cout << "현재 입력된 학생수 : ";
	cout << m_iStudentCount << endl;
	cout << "입력 : " << endl;

}

void StudentManager::FreeStudent()
{
	if (m_iStudentCount > 0)
	{
		delete m_StudentList[m_iStudentCount - 1];
		m_iStudentCount--;
	}
}
void StudentManager::FreeStudentAll()
{
	int iMemo; // 학생전체 동적할당 해제시 기존 학생숫자 저장 
	iMemo = m_iStudentCount;
	for (int i = 0; i < iMemo; i++)
	{
		delete m_StudentList[i];
		m_iStudentCount--;
	}
}

bool StudentManager::FindStudentName(string Name)
{
	bool Flag = false;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetStudentName() == Name)
		{
			m_StudentList[i]->ShowStudent();
			Flag = true;
		}
	}
	return Flag;
}

bool StudentManager::FindStudentClass(int Class)
{
	bool Flag = false;
	cout << "┌────────" << Class << "학년────────┐" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetClass() == Class)
		{
			m_StudentList[i]->ShowStudent();
			Flag = true;
		}
	}
	cout << "└──────────────────┘" << endl;
	return Flag;
}

StudentManager::~StudentManager()
{
}
