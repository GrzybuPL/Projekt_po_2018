#include <iostream>
#include <string>
#include <conio.h>
#include "sqlite3.h"
#include "StrucktData.h"
#include "TabelaRezerwacji.h"
#include "BazaDanych.h"


TabelaRezerwacji::TabelaRezerwacji()
{
	idPromocji = -1;
	idOferty = -1; 
	idKlienta = -1;
	czyZaplacone = false;
	edycja = false;
}

void TabelaRezerwacji::zerowanie()
{
	idPromocji = -1;
	idOferty = -1;
	idKlienta = -1;
	czyZaplacone = false;
	edycja = false;
}


void TabelaRezerwacji::wpiszDaneDoRezerwacji(int idk, int ido,bool czyz)
{
	if (idKlienta == -1 || idOferty == -1 || idk == -1 || ido == -1)
	{
		cout << "Podaj id Klienta: ";
		cin >> idk;
		cout << "Podaj id Oferty: ";
		cin >> ido;
		cout << "czy zaplacono(y/n): ";
		if (_getch() == 'y')czyz = true;
		else czyz = false;
		idKlienta = idk;
		idOferty = ido;
		czyZaplacone = czyz;
	}


}

void TabelaRezerwacji::zapisNew(sqlite3 *db)
{
	wpiszDaneDoRezerwacji();

	sqlite3_stmt *stmt;
	char * zErrMsg = 0;

	int rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc)
	{
		cerr << "Blad przy otwieraniu bazy: " << sqlite3_errmsg(db) << endl;
		exit(1);
	}

	string quest = "INSERT INTO dane_rezerwacji (id_rezerwacji, id_Klienta, id_Oferty, CzyZaplacone) VALUES(NULL, '" + to_string(idKlienta) + "','" + to_string(idOferty) + "', '" + to_string(czyZaplacone) + "');";
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
/*
static int callbackReturnedValues(void *NotUsed, int argc, char **argv, char **azColName) //Funkcja pobiera idKlienta i idOferty
{
	int i;
	cout << "Number of args= " << argc << endl;

	TabelaRezerwacji::idKlienta = argv[3];
	TabelaRezerwacji::idOferty = argv[4];
	
	cout << endl;
	return 0;
}*/

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

		string quest = "SELECT * FROM dane_rezerwacji";
		const char * sql = quest.c_str();

		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "Blad zapytania: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		}
	}

}
/*
void TabelaRezerwacji::zapisNew(sqlite3 *db)
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
		//Trzeba wywolac funkcje pobierajaca id klienta. Oraz funkcje pobierajaca id_oferty+++++++++++++++++==================+++++++++++++++++================
		int idklienta_=
		int idoferty_=


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
}*/

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

		string quest = "UPDATE dane_rezerwacji SET CzyZaplacone = '" + to_string(czyZaplacone) + "' WHERE id_rezerwacji = 'stareImie' AND Nazwisko = 'stareNazwisko' ;";//Aktualizacja calosci danych, nie wybiorczo
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

/* int idPromocji;
int idOferty;		//id oferty danej promocji by ³atwo znaleœæ -1 dla braku po³aczenia
int idKlienta;
bool czyZaplacone; **/

void TabelaRezerwacji::edytuj(sqlite3 *db)
{
	system("cls");

	cout << "id Oferty: " << idOferty << endl;
	cout << "id Klienta: " << idKlienta << endl;
	cout << "czy zaplacono:" << czyZaplacone << endl;
	cout << "czy chcesz edytowac dane(y/n): ";
	cout << endl;
	
	if (_getch() == 'y')
	{
		cout << "edycja Op³aty?(y/n): ";
		if (_getch() == 'y') {
			
			cout << "Zaplacono(y/n): " << endl;
				if (_getch() == 'y') czyZaplacone = true;
				else czyZaplacone = false;	
				edycja = true;
		}
		cout << endl;
		cout << "edycja id Oferty?(y/n): ";
		if (_getch() == 'y') { 
		
				do
				{
					cout << "podaj numer id: ";

					cin >> idOferty;

				} while (idOferty<0);		
			edycja = true;
		}
		cout << endl;
		cout << "edycja id Klienta?(y/n): ";
		if (_getch() == 'y') {

			do
			{
				cout << "podaj numer id: ";

				cin >> idKlienta;

			} while (idKlienta<0);
			edycja = true;
		}
		cout << "edycja zakonczona." << endl;
		system("pause");
	}

	if (edycja) this->zapisAdd(db);//zapis po edycji
}
