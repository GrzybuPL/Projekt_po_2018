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
	int idOferty;		//id oferty danej promocji by ³atwo znaleœæ -1 dla braku po³aczenia
	int idKlienta;
	bool CzyZaplacone;
	bool edycja;

public:

	virtual void odczyt();
	virtual void zapisAdd();
	virtual void edytuj();
	virtual void zapisNew();


};

int odczytIdKlient();