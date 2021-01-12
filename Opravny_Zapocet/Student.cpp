#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student()
{
}

Student::Student(char* paMeno, char* paPriezvisko, double paPriemer)
{
	if (paMeno && *paMeno && paPriezvisko && *paPriezvisko)
	{
		aMeno = new char[strlen(paMeno) + 1];
		strcpy(aMeno, paMeno);

		aPriezvisko = new char[strlen(paPriezvisko) + 1];
		strcpy(aPriezvisko, paPriezvisko);

		this->aPriemer = paPriemer;
	}
}

Student::Student(const Student& zdroj)
{
	if (this != &zdroj)
	{
		aMeno = new char[strlen(zdroj.aMeno) + 1];
		strcpy(aMeno, zdroj.aMeno);

		aPriezvisko = new char[strlen(zdroj.aPriezvisko) + 1];
		strcpy(aPriezvisko, zdroj.aPriezvisko);

		this->aPriemer = zdroj.aPriemer;
	}
}

Student& Student::operator=(const Student& zdroj)
{
	if (this != &zdroj)
	{
		Student::~Student();

		aMeno = new char[strlen(zdroj.aMeno) + 1];
		strcpy(aMeno, zdroj.aMeno);

		aPriezvisko = new char[strlen(zdroj.aPriezvisko) + 1];
		strcpy(aPriezvisko, zdroj.aPriezvisko);

		this->aPriemer = zdroj.aPriemer;
	}
	return *this;
}

void Student::Vypis()
{
	cout << this->aPriemer << " " << this->aPriezvisko << " " << this->aMeno << endl;
}

Student::~Student()
{
	delete[] aMeno;
	aMeno = nullptr;
	delete[] aPriezvisko;
	aPriezvisko = nullptr;
	aPriemer = 0.00;
}