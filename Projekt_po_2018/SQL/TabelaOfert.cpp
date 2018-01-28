#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaOfert.h"
#include "BazaDanych.h"

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

void TabelaOfert::odczyt(sqlite3 *db)
{
	if (edycja)
	{
		char *zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
			sqlite3_close(db);
			exit(1);
		}

		string quest = "SELECT * FORM dane_oferty WHERE Koszt = '" + koszt + "' Gdzie = '" + miejsce + "' DataPobytuOd = '" + odDnia.getDate() + "' DlugoscPobytu = '" + dlugoscPobytu + "' RodzajTranspotru = '" + transport + "' ";
		const char * sql = quest.c_str();

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "Blad zapytania: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		}
	}

}

void TabelaOfert::zapisNew(sqlite3 *db)
{
	if (edycja)
	{
		sqlite3_stmt *stmt;
		char * zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
			exit(1);
		}

		string quest = "INSERT INTO dane_oferty (id_oferty, Koszt, Gdzie, DaatPobytuOd, DlugoscPobytu, RodzajTransportu) VALUES(NULL, '" + koszt + "', '" + miejsce + "', '" + odDnia.getDate() + "', '" + dlugoscPobytu + "', '" + transport + "');";
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

		sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}
}

void TabelaOfert::zapisAdd(sqlite3 *db)
{
	if (edycja)
	{
		sqlite3_stmt *stmt;
		char * zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
			exit(1);
		}

		string quest = "UPDATE dane_dferty SET Koszt = '" + koszt + "', Gdzie = '" + miejsce + "', DataPobytuOd = '" + odDnia.getDate() + "', DlugoscPobytu = '" + dlugoscPobytu + "', RodzajTransportu = '" + transport + "' WHERE Imie = 'stareImie' AND Nazwisko = 'stareNazwisko' ";//Aktualizacja calosci danych, nie wybiorczo
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

		sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}

}


void TabelaOfert::edytuj(sqlite3 *db)
{
	int d, m, y;

	system("cls");
	cout << "Obecny wyglad oferty:" << endl;
	if (idOferty > -1) { cout << "id oferty: " << idOferty << endl; }
	if (nazwa != "") { cout << "nazwa: " << nazwa << endl; }
	if (koszt != "") { cout << "koszt: " << koszt << endl; }
	if (miejsce != "") { cout << "miejsce: " << miejsce << endl; }
	if (dlugoscPobytu != "") { cout << "dlugosc pobytu: " << dlugoscPobytu << endl; }
	if (transport != "") { cout << "transport: " << transport << endl; }
	if (odDnia.getDate() != "0-0-0") { cout << odDnia.getDate() << endl; }
	cout << "promocja: ";
	if (idPromocji > -1)cout << "TAK" << endl;
	else cout << "NIE" << endl;

	cout << "Czy chcesz edytowaæ Oferte?(y/n): ";
	cout << endl;


	if (_getch() == 'y')
	{
		cout << "Edycja nazwa?(y/n): ";
		if (_getch() == 'y') { cin >> nazwa; edycja = true; }
		cout << endl;
		cout << "Edycja ceny(y/n): ";
		if (_getch() == 'y') { cin >> koszt; edycja = true; }
		cout << endl;
		cout << "Edycja miejsca?(y/n): ";
		if (_getch() == 'y') { cin >> miejsce; edycja = true; }
		cout << endl;
		cout << "Edycja dlugosci pobytu?(y/n): ";
		if (_getch() == 'y') { cin >> dlugoscPobytu; edycja = true; }
		cout << endl;
		cout << "Edycja transport?(y/n): ";
		if (_getch() == 'y') { cin >> transport; edycja = true; }
		cout << endl;
		cout << "Edycja daty pobytu, od?(y/n): ";
		if (_getch() == 'y')
		{
			cout << "dzien: ";
			cin >> d;
			cout << "miesiac: ";
			cin >> m;
			cout << "rok: ";
			cin >> y;
			odDnia.setData(d, m, y);
			edycja = true;
		}
		cout << endl;
		cout << "Edycja zakonczona" << endl;
		system("pause");
	}
	if (edycja)this->zapisAdd(db);
}

