#pragma once
#include<string>
#include<iostream>
using namespace std;

#define Arr_MAX 5

class OverLoadingTest
{
public:
private:
public:
	void OverLoading1(int iNum1, int iNum2);
	void OverLoading1(char chA, int iNum);
	void OverLoading2(string);
	void OverLoading2(string, string);
	void OverLoading3(int iarr[Arr_MAX]);
	void OverLoading3(char charr[Arr_MAX]);

	OverLoadingTest();
	~OverLoadingTest();
};

