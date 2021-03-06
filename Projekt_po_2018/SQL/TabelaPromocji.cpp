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

void TabelaPromocji::zerowanie()
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
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM promocja";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}


}

void TabelaPromocji::zapisNew(sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "INSERT INTO promocja (id_promocji, id_oferty, Cena, Opis, CzasTrwania) VALUES(NULL, '" + to_string(idOferty) + "', '" + nowaCena + "', '" + opis + "', '" + czasTrwania.c_str() + "');";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		zerowanie();
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

		string quest = "UPDATE promocja SET Cena = '" + nowaCena + "', Opis = '" + opis + "' CzasTrwania = '" + czasTrwania + "' WHERE id_promocji = '" + to_string(idPromocji) + "';";//Aktualizacja calosci danych, nie wybiorczo
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

void TabelaPromocji::odczytPoId(int id, sqlite3 *db)
{
	char *zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}

	string quest = "SELECT * FROM promocja WHERE id_promocji = '" + to_string(id) + "';";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		this->zerowanie();
	}
}

void TabelaPromocji::dodaj(sqlite3 *db)
{
	system("cls");

	cout << "czy chcesz dodac oferty (y/n): ";
	cout << endl;

	if (_getch() == 'y')
	{
		//cout << " id Promocji: ";
		 //cin >> idPromocji;
		cout << endl;
		cout << "id Oferty: ";
		 cin >> idOferty;
		cout << endl;
		cout << "Nowa cena: ";
		cin >> nowaCena; 
		cout << endl;
		cout << "Opis: ";
		cin >> opis;
		cout << endl;
		cout << "Czas trwania: ";
		cin >> czasTrwania; 
		cout << endl;
		cout << "Dodawanie zakonczone" << endl;
		system("pause");
		this->zapisNew(db);
	}
}
