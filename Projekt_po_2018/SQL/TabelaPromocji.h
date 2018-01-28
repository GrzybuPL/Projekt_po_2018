#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

class TabelaPromocji : public BazaDanych {

	int idPromocji;
	int idOferty;		//id oferty danej promocji by ³atwo znaleœæ -1 dla braku po³aczenia
	string nowaCena;
	string opis;
	string czasTrwania;
	bool edycja;

public:

	TabelaPromocji();

	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db);
	virtual void edytuj(sqlite3 *db);
	virtual void zapisNew(sqlite3 *db);

	bool usunPromocje(int id_Promocji, sqlite3 *db);


};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);