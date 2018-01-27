#pragma once
#include <iostream>
#include <string>
#include "BazaDanych.h"

using namespace std;
class BazaDanych;

class TabelaPromocji : public BazaDanych {

	int idPromocji;
	int idOferty;//id oferty danej promocji by �atwo znale�� -1 dla braku po�aczenia
	string nowaCena;
	string opis;
	bool edycja;

public:

	virtual void odczyt();
	virtual void zapis();
	virtual void edytuj();
	virtual void zapisNew();



};

