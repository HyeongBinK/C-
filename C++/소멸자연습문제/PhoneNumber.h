#pragma once
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

class PhoneNumber
{
public:
private:
	char * m_chphonenumber;
	char * m_chReMakePhoneNumber;
	int m_isize;
public:
	PhoneNumber();
	~PhoneNumber();
	void Display();
	void CheckBarInput(int i, int FirstBar, int SecondBar);
	void RemakePhoneNumber();
	void Deletem_chReMakePhoneNumber();
	bool CheckPhoneNumber();

};

