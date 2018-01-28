#pragma once
#include <iostream>
#include <string>
#include "StrucktData.h"
#include "BazaDanych.h"

using namespace std;

class TabelaOfert : public BazaDanych {
	int idOferty;
	string nazwa;
	string koszt;
	string miejsce;
	string dlugoscPobytu;
	string transport;
	Data odDnia;
	bool edycja;
	int idPromocji;		//-1 dla braku promocji
public:
	TabelaOfert();
	virtual void odczyt(sqlite3 *db);
	virtual void zapisAdd(sqlite3 *db) ;
	virtual void edytuj(sqlite3 *db);
	virtual void zapisNew(sqlite3 *db) ;
	void odczytPoId(int id, sqlite3 *db);


};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);