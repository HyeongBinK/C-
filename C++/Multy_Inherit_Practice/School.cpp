#include "School.h"

void School::SaveSchoolData()
{
	cout << "당신의 학년은?" << endl;
	cin >> m_iGrade;
	cout << "당신의 반은?" << endl;
	cin >> m_iClass;
	cout << "당신의 번호는?" << endl;
	cin >> m_iNumber;

}
void School::ShowSchoolData()
{
	cout << "학년 :" << m_iGrade << endl;
	cout << "반 :" << m_iClass << endl;
	cout << "번호 :" << m_iNumber << endl;
}