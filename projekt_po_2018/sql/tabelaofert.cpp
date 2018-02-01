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
	odDnia.setData(-1, -1, -1);
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
	odDnia.setData(-1, -1, -1);
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

		string quest = "INSERT INTO dane_oferty (id_oferty, NazwaOferty, Koszt, Gdzie, DaatPobytuOd, DlugoscPobytu, RodzajTransportu, id_promocji) VALUES(NULL, ' ', '" + koszt + "', '" + miejsce + "', '" + odDnia.getDate() + "', '" + dlugoscPobytu + "', '" + transport + "', ' ');";
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

		string quest = "UPDATE dane_dferty SET Koszt = '" + koszt + "', Gdzie = '" + miejsce + "', DataPobytuOd = '" + odDnia.getDate() + "', DlugoscPobytu = '" + dlugoscPobytu + "', RodzajTransportu = '" + transport + "' WHERE id_oferty = '" + to_string(idOferty) + "' ";//Aktualizacja calosci danych, nie wybiorczo
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
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string q, w, e, r, t, z;

	cout << "Podaj id promocji: ";
	cin >> z;
	cout << "Podaj nazwe oferty: ";
	cin >> q;
	cout << "Podaj koszt oferty: ";
	cin >> w;
	cout << "Podaj mejsce oferty: ";
	cin >> e;
	cout << "Podaj date pobytu : ";
	cin >> r;
	cout << "Podaj rodzaj transportu: ";
	cin >> t;

	string quest = "INSERT INTO dane_oferty (id_promocji, Nazwa, Koszt, Gdzie, DataPobytuOd, RodzajTransportu) VALUES ('" + z + "','" + q + "','" + w + "','" + e + "','" + r + "','" + t + "');";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
	}
}

