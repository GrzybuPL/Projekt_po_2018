#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaOfert.h"
#include "BazaDanych.h"


TabelaOfert::TabelaOfert()
{
	idOferty = -1;
	nazwa = "";
	koszt = "";
	miejsce = "";
	transport = "";
	odDnia = "";
	edycja = false;
	idPromocji = -1;
}
void TabelaOfert::zerowanie()
{
	idOferty = -1;
	nazwa = "";
	koszt = "";
	miejsce = "";
	transport = "";
	odDnia = "";
	edycja = false;
	idPromocji = -1;
}

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

bool TabelaOfert::odczytPoId(int id, sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM dane_oferty WHERE id_oferty = '" + to_string(id) + "';";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		this->zerowanie();
	}
}

void TabelaOfert::odczyt(sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM dane_oferty;";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
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

		string quest = "INSERT INTO dane_oferty (id_oferty, Nazwa, Koszt, Gdzie, DaatPobytuOd, DlugoscPobytuOd, RodzajTransportu, id_promocji) VALUES(NULL, ' ', '" + koszt + "', '" + miejsce + "', '" + odDnia + "', '" + dlugoscPobytu + "', '" + transport + "', ' ');";
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

		string quest = "UPDATE dane_oferty SET Koszt = '" + koszt + "', Gdzie = '" + miejsce + "', DataPobytuOd = '" + odDnia + "', DlugoscPobytu = '" + dlugoscPobytu + "', RodzajTransportu = '" + transport + "' WHERE id_oferty = '" + to_string(idOferty) + "' ";//Aktualizacja calosci danych, nie wybiorczo
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


void TabelaOfert::dodaj(sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	int d, m, y;

	cout << "Podaj id promocji: ";
	cin >> idPromocji;
	cout << "Podaj nazwe oferty: ";
	cin >> nazwa;
	cout << "Podaj koszt oferty: ";
	cin >> koszt;
	cout << "Podaj mejsce oferty: ";
	cin >> miejsce;
	cout << "Podaj date pobytu od [rrrr-mm-dd]: ";
	cin >> odDnia;
	cout << "Podaj rodzaj transportu: ";
	cin >> transport;

	string quest = "INSERT INTO dane_oferty (id_oferty, Nazwa, Koszt, Gdzie, DataPobytuOd, DlugoscPobytu, RodzajTransportu, id_promocji) VALUES (NULL, '" + nazwa + "', '" + koszt + "', '" + miejsce + "', '" + odDnia + "', '" + dlugoscPobytu + "', '" + transport + "', '" + to_string(idPromocji) + "');";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
	}
}

