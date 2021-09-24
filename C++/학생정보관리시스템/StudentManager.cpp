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
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
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
		cout << "������������������" << i << "�г⦡����������������" << endl;

		for (int j = 0; j < m_iStudentCount; j++)
		{
			if (i == m_StudentList[j]->GetClass())
				m_StudentList[j]->ShowStudent();
		}

		cout << "������������������������������������������" << endl;

	}

}

void StudentManager::ShowMenu()
{
	system("cls");
	cout << "======�л����� ���α׷�======" << endl;
	cout << "1. �л����" << endl;
	cout << "2. �л����<��ȣ��>" << endl;
	cout << "3. �л����<�г��>" << endl;
	cout << "4. �л��̸� �˻�" << endl;
	cout << "5. �г� �˻�" << endl;
	cout << "6. ���������� �Է��� �л�����" << endl;
	cout << "7. �л� ��ü ����" << endl;
	cout << "8. ����" << endl;
	cout << "���� �Էµ� �л��� : ";
	cout << m_iStudentCount << endl;
	cout << "�Է� : " << endl;

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
	int iMemo; // �л���ü �����Ҵ� ������ ���� �л����� ���� 
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
	cout << "������������������" << Class << "�г⦡����������������" << endl;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		if (m_StudentList[i]->GetClass() == Class)
		{
			m_StudentList[i]->ShowStudent();
			Flag = true;
		}
	}
	cout << "����������������������������������������" << endl;
	return Flag;
}

StudentManager::~StudentManager()
{
}
