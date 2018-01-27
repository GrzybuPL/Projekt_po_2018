#include <iostream>
#include "gui.h"//Dominik Grzyboweski  interface uzytkownika
#include "../SQL/SQL.h"//Marcin Zuber oprracje na bazie danych 
#include <conio.h>

using namespace std;


//SQL* baza-nullptr;


//wczytaj(baza);


void help(int i=0)			//Wyswietlenie pomocy
{
	if (i==-1) cout << "ERROR!" << endl;
	cout << "Pomoc programu biura obslugi klienta" << endl;
	cout << "Podaj parametr -h w celu wyœwietlenia tej pomocy" << endl;
	cout << "Podaj parametr -b aby wprowadziæ nazwê bazy danych" << endl;
}


bool menu(SQL* &baze)
{
	bool open=true;
	cout << "menu" << endl;

	cout << "1. pp..." << endl;
//...
	cout << "0. exit" << endl;

	while (open)
	{

		switch (getch())
		{
		case '1':
			break;


			//...
		case '0':
			cout << "Czy napewno chwsz wyjsc z programu (y/n): ";
			if (getch() == 'y') { open = false; cout << "Trwa wylanczanie systemu" << endl; }
			break;			
		default:
			break;
		}

	}

	return true;
}


void welcome()
{
	system("cls");
	cout << endl << "==================System Podru¿y=================" << endl << endl;


}


void loopProgram(const char* nazwa_= "BiuroPodrozy.db")//glowna petla programu
{
	bool strat = true;

	SQL *baze=new SQL(nazwa_);  //obiekt bazy danych

	while (strat)
	{
		welcome();

		//funkcja powitanie

		//funkcja  strat= menu(*baze)

		if (menu(baze)) strat =false;
	}
}


void paraMain(int &argc, char** argv)//menu parametrów
{
	string buf;

	for (int i = 1; i < argc; i++)
	{
		buf = argv[i];
		if (buf[0] == '-')
		{
			if (buf.length() < 3)
			{
				switch (buf[1])
				{
				case 'h':		//Wyswietlenie pomocy
					help(0);
					break;
				case 'b':		//Podanie nazwy bazy danych
				default:
					i++;
					buf = argv[i];
					if (buf[0] != '-')
					{
						loopProgram(argv[i]);
					}
					else
					{
						help(-1);
					}
					i = argc;//konczenie dalszych dzia³an
					break;
				}
			}
			else help(-1);
		}
		else
		{
			help(-1);
		}
	}
}

