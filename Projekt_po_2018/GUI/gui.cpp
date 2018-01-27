#include <iostream>
#include "gui.h"//Dominik Grzyboweski  interface uzytkownika
#include "../SQL/SQL.h"//Marcin Zuber oprracje na bazie danych 


using namespace std;


//int argc, char** argv

//SQL* baza-nullptr;


//wczytaj(baza);


void help()			//Wyswietlenie pomocy
{
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

		if(menu(baze)) 



	}
}


void paraMain(int &argc, char** argv)
{
	string buf;
	for (int i = 1; i < argc; i++)
	{
		buf = argv[i];
		switch (buf[0])
		{
		case '-':
			if (buf.length() < 3)
			{
				switch (buf[i])
				{
				case 'h':		//Wyswietlenie pomocy
					help();
					break;
				case 'b':		//Podanie nazwy bazy danych
				default:
					loopProgram(buf[i + 1]); i++;
					break;
				}
			}
			else
				break;
		default:
			help();
			break;
		}
	}
}

