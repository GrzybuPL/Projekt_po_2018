#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

/*	DODANE
pobierzDane(int id_Klienta, int id_Oferty, bool Czy_Zaplacone);
*/
class TabelaRezerwacji : public BazaDanych {

	int idPromocji;
	int idOferty;		//id oferty danej promocji by �atwo znale�� -1 dla braku po�aczenia
	int idKlienta;
	bool czyZaplacone;
	bool edycja;

public:
	TabelaRezerwacji();

	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db);
	virtual void edytuj(sqlite3 *db);
	virtual void zapisNew(int id_Klienta, int id_Oferty, bool Czy_Zaplacone, sqlite3 *db);
};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);