#include <iostream>
#include "gui.h"//Dominik Grzyboweski  interface uzytkownika
#include "../SQL/SQL.h"//Marcin Zuber oprracje na bazie danych 


using namespace std;


//int argc, char** argv

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



	return true;
}


void welcome()
{
	cout << endl;

}


void loopProgram(const char* nazwa_= "BiuroPodrozy.db")
{
	bool strat = true;

	SQL *baze=new SQL(nazwa_);  //obiekt bazy danych

	while (strat)
	{

		//funkcja powitanie

		//funkcja  strat= menu(*baze)

		if (menu(baze));



	}
}


void paraMain(int &argc, char** argv)
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

