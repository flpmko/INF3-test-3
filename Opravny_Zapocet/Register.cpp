#include "Register.h"
#include <string>

Register::Register()
{
}

Register::Register(char* paNazovSuboru)
{
	if (paNazovSuboru != nullptr)
	{
		ifstream input;
		input.open(paNazovSuboru);
		if (input.is_open())
		{
			//zistim pocet riadkov aby som vedel aky velky zoznam vytvorit
			int pocetRiadkov = 0;
			string riadok;
			while (getline(input, riadok)) pocetRiadkov++;

			//nastavim kurzor opat na zaciatok suboru
			input.clear();
			input.seekg(0); 

			//vytvorim si novy zoznam podla poctu studentov
			pocetStudentov = pocetRiadkov;
			zoznam = new Student * [pocetRiadkov];

			//pomocne premenne na nacitanie zo suboru
			string meno;
			string priezvisko;
			double priemer;
			int i = 0;

			//nacitanie zo suboru a naplnenie zoznamu studentami
			while (!input.eof())
			{
				input >> priezvisko >> meno >> priemer;
				zoznam[i] = new Student((char*)meno.c_str(), (char*)priezvisko.c_str(), priemer);
				i++;
			}
		}
		input.close();
	}
}

void Register::Vypis()
{
	if (this->zoznam != nullptr)
	{
		printf("STUDENTI PODLA PRIEMERU VZOSTUPNE:\n");
		for (int i = 0; i < this->pocetStudentov; i++)
		{
			zoznam[i]->Vypis();
		}
	}
}

void Register::Zorad()
{
	for (int i = 0; i < pocetStudentov - 1; i++)
	{
		for (int j = 0; j < pocetStudentov - i - 1; j++)
		{
			//zoradenie vzostupne
			if (this->zoznam[j]->getPriemer() > this->zoznam[j + 1]->getPriemer())
			{
				Vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void Register::Vymen(Student& a, Student& b)
{
	Student c = a;
	a = b;
	b = c;
}

Register::~Register()
{
	for (int i = 0; i < pocetStudentov; i++)
	{
		delete this->zoznam[i];
	}
	delete[] zoznam;
}
