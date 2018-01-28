#include <iostream>
#include "gui.h"//Dominik Grzyboweski  interface uzytkownika
#include "../SQL/SQL.h"//Marcin Zuber oprracje na bazie danych 
#include <conio.h>
#include <string>

using namespace std;


void help(int i)			//Wyswietlenie pomocy
{
	if (i==-1) cout << "ERROR!" << endl;
	cout << "Pomoc programu biura obslugi klienta" << endl;
	cout << "Podaj parametr -h w celu wyœwietlenia tej pomocy" << endl;
	cout << "Podaj parametr -b aby wprowadziæ nazwê bazy danych" << endl;
}

bool menu(SQL* &baze)
{
	bool open=true;
	cout << "Menu" << endl;
	cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
	cout << "1. Zarzadzaj klientami" << endl;
	cout << "2. Zarzadzaj ofertami" << endl;
	cout << "3. Zarzadzaj promocjami" << endl;
	cout << "4. Przejdz do rezerwacji" << endl;
	cout << "0. exit" << endl;

	while (open)
	{
		switch (_getch())
		{
		case '1':		
			menuKlient(baze);//Przejscie do menu klienta
			break;
		case '2':		
			menuOfert(baze);//Przejscie do menu ofert
			break;
		case '3':		
			menuPromo(baze);//Przejscie do menu promocji
			break;
		case '4':		
			menuRezer(baze);//Przejscie do menu rezerwacji
			break;
			//...
		case '0':
			cout << "Czy napewno chcesz wyjsc z programu (y/n): ";
			if (_getch() == 'y') { open = false; cout << "Trwa wylaczanie systemu" << endl; return false; }
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
	cout << endl << "================== System biura podrozy ==================" << endl;
	cout << endl << "======================== Witamy ==========================" << endl << endl;
}


void loopProgram(const char* nazwa_)		//glowna petla programu
{
	bool strat = true;

	SQL *baze=new SQL();  //obiekt bazy danych

	while (strat)
	{
		welcome();		//funkcja powitanie

		//funkcja  strat= menu(*baze)

		if (menu(baze)) strat =false;
	}
	delete baze;
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

