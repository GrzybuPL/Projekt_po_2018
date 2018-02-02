#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

class TabelaRezerwacji : public BazaDanych {

	int idRezerwacji;
	int idPromocji;
	int idOferty;		//id oferty danej promocji by �atwo znale�� -1 dla braku po�aczenia
	int idKlienta;
	bool czyZaplacone;
	bool edycja;

public:
	TabelaRezerwacji();

	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db);
	virtual void dodaj(sqlite3 *db);
	virtual void zapisNew(sqlite3 *db);
	void wpiszDaneDoRezerwacji(int idk=-1, int ido=-1, bool czyz = false);
	void zerowanie();
	void odczytPoId(int id, sqlite3 *db);
};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);