#include <iostream>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "BazaDanych.h"
#include "TabelaKlient.h"


TabelaKlient::TabelaKlient()
{
	idKlienta = -1;
	imie = "";
	nazwisko = "";
	adresZamieszkania = "";
	nr_Tel = "";
	eMail = "";
	edycja = false;
}

void TabelaKlient::zerowanie()
{
	idKlienta = -1;
	imie = "";
	nazwisko = "";
	adresZamieszkania = "";
	nr_Tel = "";
	eMail = "";
	edycja = false;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	cout << "Number of args= " << argc << endl;

	for (i = 0; i<argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}

	//idKlienta = atoi(argv[1]);
	//imie = argv[2];
	//nazwisko = argv[3];
	//adresZamieszkania = argv[4];
	//nr_Tel = argv[5];
	//eMail = argv[6];

	cout << endl;
	return 0;
}

bool TabelaKlient::WyszukajKlienta(string imie, string nazwisko, sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM klienci WHERE Imie = '" + imie + "' AND Nazwisko = '" + nazwisko + "'";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
		return 0;
	}

	return 1;
}

void TabelaKlient::odczytPoId(int id, sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM klienci WHERE id_klienta = '" + to_string(id) + "';";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		this->zerowanie();
	}
}

void TabelaKlient::odczyt(sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM klienci";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
	}
}

/*
void TabelaKlient::zapisNew(sqlite3 *db)
{
	if (edycja)
	{
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

		sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	}
}*/

void TabelaKlient::zapisAdd(sqlite3 *db)
{
	if (edycja)
	{
		sqlite3_stmt *stmt;
		char * zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
			exit(1);
		}

		string quest = "UPDATE klienci SET Imie = '" + imie + "', Nazwisko = '" + nazwisko + "', AdresZamieszkania = '" + adresZamieszkania + "', NrTel = '" + nr_Tel + "', EMail = '" + eMail + "' WHERE id_klienta  = '" + to_string(idKlienta) + "' ";
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

void TabelaKlient::zapisNew(sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}
	/*
	cout << "Podaj imie klienta: ";
	cin >> imie;
	cout << "Podaj nazwisko klienta: ";
	cin >> nazwisko;
	cout << "Podaj adres zamieszkania klienta: ";
	getline(cin, adresZamieszkania);
	cout << "Podaj numer telefonu klienta: ";
	cin >> nr_Tel;
	cout << "Podaj email klienta: ";
	cin >> eMail;*/

	string quest = "INSERT INTO klienci (imie, nazwisko, adresZamieszkania, NrTel, eMail) VALUES ('" + imie + "','" + nazwisko + "','" + adresZamieszkania + "','" + nr_Tel + "','" + eMail + "');";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
	}
}

void TabelaKlient::edytuj(sqlite3 *db)
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
		if (_getch() == 'y') { getline(cin, adresZamieszkania); edycja = true; }
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

	if (idKlienta != -1 &&edycja) this->zapisAdd(db);//zapis po edycji
	else this->zapisNew(db);
}

