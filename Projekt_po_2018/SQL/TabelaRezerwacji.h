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
	//int idOferty;		//id oferty danej promocji by ³atwo znaleœæ -1 dla braku po³aczenia
	//int idKlienta;
	bool CzyZaplacone;
	bool edycja;

public:
	int idOferty;
	int idKlienta;
	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db);
	virtual void edytuj(sqlite3 *db);
	virtual void zapisNew(sqlite3 *db);
	virtual void pobierzDane(int id_Klienta, int id_Oferty, bool Czy_Zaplacone, sqlite3 *db);
};

int odczytIdKlient();
int odczytIdOferty();