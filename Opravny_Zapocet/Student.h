#pragma once
class Student
{
private:
	char* aMeno = nullptr;
	char* aPriezvisko = nullptr;
	double aPriemer = 0.00;
public:
	Student();
	Student(char* paMeno, char* paPriezvisko, double paPriemer);
	Student(const Student& zdroj);
	Student& operator = (const Student& zdroj);
	void Vypis();
	inline double getPriemer() { return this->aPriemer; };
	~Student();
};

