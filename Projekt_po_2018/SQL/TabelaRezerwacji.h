#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

/*	DODANE
int odczytIdKlient();

*/
class TabelaRezerwacji : public BazaDanych {

	int idPromocji;
	//int idOferty;		//id oferty danej promocji by �atwo znale�� -1 dla braku po�aczenia
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

};

int odczytIdKlient();
int odczytIdOferty();