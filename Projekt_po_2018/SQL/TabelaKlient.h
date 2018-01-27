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
	virtual void odczyt();
	virtual void zapis() ;
	virtual void edytuj() ;
	virtual void zapisNew();





};

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
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