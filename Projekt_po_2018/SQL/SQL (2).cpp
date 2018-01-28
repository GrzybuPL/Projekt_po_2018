#include <iostream>
#include <string>
#include "SQL.h"

using namespace std;


SQL::SQL(const char* nazwaBazy_)
{

	if (sqlite3_open(nazwaBazy_, &db)) {
		cout << "Nie mozna otworzyc bazy danych: " << sqlite3_errmsg(db);
	}
	else {
		cout << "Udalo sie otworzyc baze danych";
	}

	klient = new TabelaKlient;
	oferty = new TabelaOfert;
	promocje = new TabelaPromocji;
	rezerwacje = new TabelaRezerwacji;
	wsk = nullptr;
}


SQL::~SQL()
{
	delete klient;
	delete oferty;
	delete promocje;
	sqlite3_close(db);		//zamkniecie bazy danych
}


















