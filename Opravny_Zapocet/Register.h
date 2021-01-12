#pragma once
#include "Student.h"
#include <fstream>

using namespace std;

class Register
{
private:
	Student** zoznam = nullptr;
	int pocetStudentov = 0;
public:
	Register();
	Register(char* paNazovSuboru);
	void Vypis();
	void Zorad();
	void Vymen(Student& a, Student& b);
	~Register();
};

