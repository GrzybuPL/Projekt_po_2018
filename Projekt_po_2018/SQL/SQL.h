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
	TabelaKlient klient;
	TabelaOfert *oferty;
	TabelaPromocji *promocje;
	TabelaRezerwacji* rezerwacje;
	Filtr *filtr;
	BazaDanych * wsk;
public:
	
	//wszytkie g³ówne metody jak zadaj pytanie->po czym mam  szukac->zwroc szukana wartosc
	//zwracaj wszytko string
	//uogolnienie wszytkich baz
	
	SQL(const char* nazwaBazy_ = "BiuroPodrozy.db");
	~SQL();

	//=============================tabela klientuw
	bool znajdz_klienta(string im, string naz);	//pyta po czym ma szukac
	void addklient();
	void editklient();
	void showallklient();



};

void menuKlient(SQL * &baze);
void menuOfert(SQL * &baze);
void menuPromo(SQL * &baze);
void menuRezer(SQL * &baze);


void wczydaj_bazy(SQL *&);		//tworzy klasy, otwiera pliki, itd.

