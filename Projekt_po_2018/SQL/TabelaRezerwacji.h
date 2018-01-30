#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

class TabelaRezerwacji : public BazaDanych {

	int idRezerwacji;
	int idPromocji;
	int idOferty;		//id oferty danej promocji by ³atwo znaleœæ -1 dla braku po³aczenia
	int idKlienta;
	bool czyZaplacone;
	bool edycja;

public:
	TabelaRezerwacji();

	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db);
	virtual void edytuj(sqlite3 *db);
	virtual void zapisNew(sqlite3 *db);
	void wpiszDaneDoRezerwacji(int idk=-1, int ido=-1, bool czyz = false);
	void zerowanie();
};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);