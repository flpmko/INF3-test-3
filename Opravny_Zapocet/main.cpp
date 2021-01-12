#include <iostream>
#include "DoublePole.h"
#include "Register.h"

#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //na kontrolu memory leakov

	//kontrola triedy DoublePole
	DoublePole pole1(5);
	DoublePole pole2(pole1);
	DoublePole pole3 = pole2;
	pole1 = pole3;

	//main
	Register trieda((char*)"Data5.txt");
	trieda.Zorad();
	trieda.Vypis();

	return 0;
}