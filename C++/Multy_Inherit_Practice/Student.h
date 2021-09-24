#pragma once
#include"BaseHeader.h"
#include"Person.h"
#include"School.h"


class Student :public Person, public School
{
private:
protected:
public:
	void SaveStudent();
	void ShowStudent();
};

