#pragma once
#include "sqlite3.h"
#include "BazaDanych.h"
#include "TabelaKlient.h"
#include "TabelaOfert.h"
#include "TabelaPromocji.h"
#include "TabelaRezerwacji.h"
#include "../Filtr.h"

//interface SQL

//proste mini menu, mozliwosc wprowadzania danych

class SQL
{
	sqlite3 *db;
	TabelaKlient *klient;
	TabelaOfert *oferty;
	TabelaPromocji *promocje;
	TabelaRezerwacji *rezerwacje;
	Filtr *filtr;
	BazaDanych* wsk;
public:
	//wszytkie g��wne metody jak zadaj puytanie->po czym mam  czukac->zwruc szukan� wartosc
	//zwracaj wszytko string
	//uogulnienie wszytystkich baz
	
	SQL(const char* nazwaBazy_ = "BiuroPodrozy.db");
	~SQL();



	bool znajdzi_klienta();//pyta cie po czym ma szukac

};

void menuKlient(SQL * &baze);
void menuOfert(SQL * &baze);
void menuPromo(SQL * &baze);
void menuRezer(SQL * &baze);


void wczydaj_bazy(SQL *&);//tworzy klasy otwiera pliki itd

