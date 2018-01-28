#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaRezerwacji.h"
#include "BazaDanych.h"
#include "SQL.h"

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

static int callbackReturnedValues(void *NotUsed, int argc, char **argv, char **azColName) //Funkcja pobiera idKlienta i idOferty
{
	int i;
	cout << "Number of args= " << argc << endl;

	TabelaRezerwacji::idKlienta = argv[3];
	TabelaRezerwacji::idOferty = argv[4];
	
	cout << endl;
	return 0;
}

void TabelaRezerwacji::odczyt(sqlite3 *db)
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

		string quest = "SELECT * FORM dane_rezerwacji, klienci,  WHERE dane_oferty.id_Klienta = klienci.id_klienta";
		const char * sql = quest.c_str();

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "Blad zapytania: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		}
	}

}

void TabelaRezerwacji::zapisNew(sqlite3 *db)
{
	idK = odczytIdKlient();
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
		//Trzeba wywolac funkcje pobierajaca id klienta. Oraz funkcje pobierajaca id_oferty+++++++++++++++++==================+++++++++++++++++================
		callbackReturnedValues();
		string quest = "INSERT INTO dane_rezerwacji (id_rezerwacji, id_Klienta, id_Oferty, CzyZaplacone) VALUES(NULL, '" + to_string(idKlienta) + "', '" + to_string(idOferty) + "', '" + CzyZaplacone + "');";
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

		sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	}
}

void TabelaRezerwacji::zapisAdd(sqlite3 *db)
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

		string quest = "UPDATE dane_rezerwacji SET CzyZaplacone = '" + CzyZaplacone + "' WHERE id_rezerwacji = 'stareImie' AND Nazwisko = 'stareNazwisko' ;";//Aktualizacja calosci danych, nie wybiorczo
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

bool TabelaRezerwacji::edytuj(sqlite3 *db)
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


int odczytIdKlient()
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

	string quest = "SELECT id_klienta FORM klienci WHERE Imie = '" + imie + "' AND Nazwisko = '" + nazwisko + "'";
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);

		return 0;
	}

	return rc;
}

int odczytIdOferty() //Moze void???
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

	string quest = "SELECT id_oferty FORM dane_rezerwacji WHERE Koszt = '" + koszt + "' AND Gdzie = '" + TabelaOfert::miejscje + "' AND DataPobytuOd = '" + TabelaOfert::dlugoscPobytu + "' AND RodzajTransportu = '" + TabelaKlient::transport + "';";//Tymczasowe nazewnictwo
	const char * sql = quest.c_str();

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		cerr << "Blad zapytania: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);

		return 0;
	}

	return rc;
}