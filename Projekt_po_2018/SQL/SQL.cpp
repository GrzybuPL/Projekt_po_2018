#include <iostream>
#include <string>
#include "sqlite3.h"
#include "TabelaKlient.h"
#include "TabelaOfert.h"
#include "TabelaPromocji.h"
#include "TabelaRezerwacji.h"
#include "SQL.h"

using namespace std;

//trzeba przetestowac czy sie wogle otwozy baza i bêdzie otwarta ale powinno jak si eieusuibie obiektu SQL;

SQL::SQL(const char* nazwaBazy_)
{

	if (sqlite3_open(nazwaBazy_, &db)) {
		cout << "Nie mozna otworzyc baz: " << sqlite3_errmsg(db);
	}
	else {
		cout << "Udane otwarcie bazy";
	}

	klient = new TabelaKlient;
	oferty = new TabelaOfert;
	promocje = new TabelaPromocji;
}


SQL::~SQL()
{
	delete klient;
	delete oferty;
	delete promocje;
	sqlite3_close(db);//zamkniecie bazy danych
}


















