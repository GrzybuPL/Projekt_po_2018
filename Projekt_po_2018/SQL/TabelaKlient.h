#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"
using namespace std;


/*
	DOPISANE
	static int callback(void *NotUsed, int argc, char **argv, char **azColName)
*/

class TabelaKlient : public BazaDanych {

	int idKlienta;
	string imie;
	string nazwisko;
	string adresZamieszkania;
	string nr_Tel;
	string eMail;
	bool edycja;  // true -false

public:
	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db) ;
	virtual void edytuj(sqlite3 *db) ;
	virtual void zapisNew(sqlite3 *db);

	bool WyszukajKlienta(string imie, string nazwisko, sqlite3 *db);

};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);