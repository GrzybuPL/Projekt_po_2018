#include <iostream>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "BazaDanych.h"
#include "TabelaKlient.h"


void TabelaKlient::odczyt()
{




}


void TabelaKlient::zapisNew()
{
	if (edycja)
	{
		string quest = "INSERT INTO klienci VALUES(NULL, " + imie + ", " + nazwisko + ", " + adresZamieszkania + ", " + nr_Tel + ", " + eMail + ");";
		const char * sql = quest.c_str();
		sqlite3 *db;
		char * zErrMsg = 0;


		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}

}

void TabelaKlient::zapis()
{
	if (edycja)
	{
		string quest = "INSERT INTO klienci VALUES(NULL, " + imie + ", " + nazwisko + ", " + adresZamieszkania + ", " + nr_Tel + ", " + eMail + ");";
		const char * sql = quest.c_str();
		sqlite3 *db;
		char * zErrMsg = 0;


		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}

}

void TabelaKlient::edytuj()
{
	system("cls");
	cout << "czy chcesz edytowac/dodac dane klienta " << imie << " " << nazwisko << "(y/n): ";
	cout << endl;

	if (getch() == 'y')
	{
		cout << "edycja imienia?(y/n): ";
		if (getch() == 'y') { cin >> imie; edycja = true; }
		cout << endl;
		cout << "edycja nazwiska?(y/n): ";
		if (getch() == 'y') { cin >> nazwisko; edycja = true; }
		cout << endl;
		cout << "edycja adres zamieszkania?(y/n): ";
		if (getch() == 'y') { cin >> adresZamieszkania; edycja = true; }
		cout << endl;
		cout << "edycja numeru telefonu?(y/n): ";
		if (getch() == 'y') { cin >> nr_Tel; edycja = true; }
		cout << endl;
		cout << "edycja eMail?(y/n): ";
		if (getch() == 'y') { cin >> eMail; edycja = true; }
		cout << endl;
		cout << "edycja zakonczona." << endl;
		system("pause");
	}

	if (edycja) this->zapis();//zapis po edycji
}