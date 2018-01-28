#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaOfert.h"
#include "BazaDanych.h"
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

		rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
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

		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
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

		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}

}






/*	int idOferty;
string nazwa;
string koszt;
string miejsce;
string dlugoscPobytu;
string transport;
Data odDnia;
bool edycja;
int idPromocji;*/

void Filtr::edytuj()
{
	int d, m, y;

	system("cls");
	cout << "Obecny wyglad oferty:" << endl;
	if (idOferty > -1) { cout << "id oferty: " << idOferty << endl; }
	if (kosztOd > -1) { cout << "Koszt OD: " << kosztOd << endl; }
	if (kosztDo > -1) { cout << "koszt DO: " << kosztDo << endl; }
	if (dataPobytuOd.getDate() != "0-0-0") { cout << dataPobytuOd.getDate() << endl; }

	cout << "Czy chcesz edytowa� filtr?(y/n): ";
	cout << endl;


	if (getch() == 'y')
	{
		cout << "Edycja id oferty?(y/n): ";
		if (getch() == 'y') { cin >> idOferty; czyAktywny = true; }
		cout << endl;
		cout << "Edycja kosztow, od?(y/n): ";
		if (getch() == 'y') { cin >> kosztOd; czyAktywny = true; }
		cout << endl;
		cout << "Edycja kosztow, do?(y/n): ";
		if (getch() == 'y') { cin >> kosztDo; czyAktywny = true; }
		cout << endl;
		cout << "Edycja daty pobytu, od?(y/n): ";
		if (getch() == 'y')
		{
			cout << "dzien: ";
			cin >> d;
			cout << "miesiac: ";
			cin >> m;
			cout << "rok: ";
			cin >> y;
			dataPobytuOd.setData(d, m, y);
			czyAktywny = true;
		}
		cout << endl;
		cout << "Edycja daty pobytu, od?(y/n): ";
		if (getch() == 'y') { cin >> dlugoscPobytuOd; czyAktywny = true; }
		cout << endl;
		cout << "Edycja dlugosci czasu pobytu, do?(y/n): ";
		if (getch() == 'y') { cin >> dlugoscPobytuDo; czyAktywny = true; }
		cout << endl;
		cout << "Edycja zakonczona" << endl;
		system("pause");
	}
}



void TabelaOfert::edytuj(sqlite3 *db)
{
	system("cls");
	cout << "czy chcesz edytowac/dodac dane oferty " << imie << " " << nazwisko << "(y/n): ";
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

	if (edycja) this->zapisAdd(db);//zapis po edycji
}