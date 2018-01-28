#include <iostream>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "BazaDanych.h"
#include "TabelaKlient.h"
#include "SQL.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	cout << "Number of args= " << argc << endl;

	for (i = 0; i<argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}
	cout << endl;
	return 0;
}

void TabelaKlient::odczyt()
{
	if (edycja)
	{
		sqlite3 *db;
		char *zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
			sqlite3_close(db);
			exit(1);
		}

		string quest = "SELECT * FORM klienci WHERE Imie = '" + imie + "' AND Nazwisko = '" + nazwisko + "'";
		const char * sql = quest.c_str();
		
		rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
		if(rc != SQLITE_OK)
		{
			cerr << "Blad zapytania: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		}
	}

}

void TabelaKlient::zapisNew()
{
	if (edycja)
	{
		sqlite3 *db;
		sqlite3_stmt *stmt;
		char * zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
			exit(1);
		}

		string quest = "INSERT INTO klienci VALUES(NULL, " + imie + ", " + nazwisko + ", " + adresZamieszkania + ", " + nr_Tel + ", " + eMail + ");";
		const char * sql = quest.c_str();

		const char **Ogon = nullptr;

		if (sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, Ogon) != SQLITE_OK) {
			cerr << "Blad bazy: " << sqlite3_errmsg(db) << endl;
		}

		if (stmt) {
			sqlite3_step(stmt);
			sqlite3_finalize(stmt);
			sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
		}
		else {
			cerr << "Blad stmt jest NULLem" << endl;
		}

		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}
}

void TabelaKlient::zapisAdd()
{
	if (edycja)
	{
		sqlite3 *db;
		sqlite3_stmt *stmt;
		char * zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
			exit(1);
		}

		string quest = "UPDATE klienci SET Imie = 'noewImie', Nazwisko = 'noweNazwisko', AdresZamieszkania = 'nowyAdresZamieszkania', NrTel = 'nowyNrTel', EMail = 'nowyEMail' WHERE Imie = 'stareImie' ";
		const char * sql = quest.c_str();
		
		const char **Ogon = nullptr;

		if (sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, Ogon) != SQLITE_OK) {
			cerr << "Blad bazy: " << sqlite3_errmsg(db) << endl;
		}

		if (stmt) {
			sqlite3_step(stmt);
			sqlite3_finalize(stmt);
			sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
		}
		else {
			cerr << "Blad stmt jest NULLem" << endl;
		}

		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}

}

void TabelaKlient::edytuj()
{
	system("cls");
	cout << "czy chcesz edytowac/dodac dane klienta " << imie << " " << nazwisko << "(y/n): ";
	cout << endl;

	if (_getch() == 'y')
	{
		cout << "edycja imienia?(y/n): ";
		if (_getch() == 'y') { cin >> imie; edycja = true; }
		cout << endl;
		cout << "edycja nazwiska?(y/n): ";
		if (_getch() == 'y') { cin >> nazwisko; edycja = true; }
		cout << endl;
		cout << "edycja adres zamieszkania?(y/n): ";
		if (_getch() == 'y') { cin >> adresZamieszkania; edycja = true; }
		cout << endl;
		cout << "edycja numeru telefonu?(y/n): ";
		if (_getch() == 'y') { cin >> nr_Tel; edycja = true; }
		cout << endl;
		cout << "edycja eMail?(y/n): ";
		if (_getch() == 'y') { cin >> eMail; edycja = true; }
		cout << endl;
		cout << "edycja zakonczona." << endl;
		system("pause");
	}

	if (edycja) this->zapisAdd();//zapis po edycji
}