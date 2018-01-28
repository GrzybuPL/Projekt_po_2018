#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaPromocji.h"
#include "BazaDanych.h"


TabelaPromocji::TabelaPromocji()
{
	idPromocji = -1;
	idOferty = -1;		
	nowaCena = "";
	opis = "";
	czasTrwania = "";
	edycja = false;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) //Funkcja wyswietla dane pobrane z bazy
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

bool TabelaPromocji::usunPromocje(int id_Promocji, sqlite3 *db)
{
	sqlite3_stmt *stmt;
	char * zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		exit(1);
	}

	string quest = "DELETE FROM promocja WHERE id_promocji = '" + to_string(id_Promocji) + "';";
	const char * sql = quest.c_str();

	const char **Ogon = nullptr;

	if (sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, Ogon) != SQLITE_OK) {
		//cerr << "Blad bazy: " << sqlite3_errmsg(db) << endl;
		return 0;
	}

	if (stmt) {
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
	}
	else {
		//cerr << "Blad stmt jest NULLem" << endl;
		return 0;
	}

	sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	return 1;
}

void TabelaPromocji::odczyt(sqlite3 *db)
{
	if (edycja)
	{
		char *zErrMsg = 0;

		int rc = sqlite3_open("BiuroPodrozy.db", &db);

		if (rc)
		{
			cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
			sqlite3_close(db);
			exit(1);
		}

		string quest = "SELECT * FORM promocja";
		const char * sql = quest.c_str();

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "Blad zapytania: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		}
	}

}

void TabelaPromocji::zapisNew(sqlite3 *db)
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

		string quest = "INSERT INTO promocja (id_promocji, CenaPromocji, ZasadyPromocji, CzasTrwaniaPromocji) VALUES(NULL, '" + nowaCena + "', '" + opis + "', '" + czasTrwania.c_str() + "');";
		const char * sql = quest.c_str();

		const char **Ogon = nullptr;

		if (sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, Ogon) != SQLITE_OK) {
			cerr << "Blad przy otwieraniu bazy : " << sqlite3_errmsg(db) << endl;
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

void TabelaPromocji::zapisAdd(sqlite3 *db)
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

		string quest = "UPDATE dane_promocji SET CenaPromocji = '" + nowaCena + "', ZasadyPromocji = '" + opis + "' CzasTrwaniaPromocji = '" + czasTrwania + "' WHERE id_promocji = '" + to_string(idPromocji) + "';";//Aktualizacja calosci danych, nie wybiorczo
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

void TabelaPromocji::edytuj(sqlite3 *db)
{
	system("cls");

	cout << "id Promocji: " << idPromocji << endl;
	cout << "id Oferty: " << idOferty << endl;
	cout << "nowa Cena: " << nowaCena << endl;
	cout << "opis:  " << opis << endl;
	cout << "czasTrwania: " << czasTrwania << endl;


	cout << "czy chcesz edytowac/dodac dane oferty (y/n): ";
	cout << endl;

	if (_getch() == 'y')
	{
		cout << "edycja id Promocji?(y/n): ";
		if (_getch() == 'y') { cin >> idPromocji; edycja = true; }
		cout << endl;
		cout << "edycja idOferty?(y/n): ";
		if (_getch() == 'y') { cin >> idOferty; edycja = true; }
		cout << endl;
		cout << "edycja nowaCena?(y/n): ";
		if (_getch() == 'y') { cin >> nowaCena; edycja = true; }
		cout << endl;
		cout << "edycja  opis?(y/n): ";
		if (_getch() == 'y') { cin >> opis; edycja = true; }
		cout << endl;
		cout << "edycja czasTrwania?(y/n): ";
		if (_getch() == 'y') { cin >> czasTrwania; edycja = true; }
		cout << endl;
		cout << "edycja zakonczona." << endl;
		system("pause");
	}

	if (edycja) this->zapisAdd(db);//zapis po edycji
}
