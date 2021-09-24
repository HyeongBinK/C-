#include "Student.h"

void Student::SaveStudent()
{
	Person::SavePersonData();
	School::SaveSchoolData();
	
}

void Student::ShowStudent()
{
	Person::ShowPersonData();
	School::ShowSchoolData();
}