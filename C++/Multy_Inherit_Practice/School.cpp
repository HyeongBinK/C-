#include "School.h"

void School::SaveSchoolData()
{
	cout << "����� �г���?" << endl;
	cin >> m_iGrade;
	cout << "����� ����?" << endl;
	cin >> m_iClass;
	cout << "����� ��ȣ��?" << endl;
	cin >> m_iNumber;

}
void School::ShowSchoolData()
{
	cout << "�г� :" << m_iGrade << endl;
	cout << "�� :" << m_iClass << endl;
	cout << "��ȣ :" << m_iNumber << endl;
}