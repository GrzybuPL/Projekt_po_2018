#include <iostream>
#include <string>
#include "SQL.h"

using namespace std;


/*SQL::SQL(const char* nazwaBazy_)
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
}*/
void menuPromo(SQL * &baze)
{
	cout << "Menu" << endl;
	cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
	cout << "1. Znajdz promocje" << endl;
	cout << "2. Stworz promocje" << endl;
	cout << "3. Zmien promocje" << endl;
	cout << "4. Usun promocje" << endl;
	cout << "0. exit" << endl;

	while (open)
	{
		switch (_getch())
		{
		case '1':
			;
			break;
		case '2':
			TabelaPromocji::zapisNew(baze);
			break;
		case '3':
			TabelaPromocji::edytuj(baze);
			break;
		case '4':
			TabelaPromocji::usunPromocje(baze);
			break;
			//...
		case '0':
			return false;
			break;
		default:
			break;
		}
	}
	return true;
}
void menuRezer(SQL * &baze)
{
	bool open = true;
	cout << "Menu" << endl;
	cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
	cout << "1. Dokonaj rezerwacji" << endl;
	cout << "2. Edytuj rezerwacjami" << endl;
	cout << "3. Anuluj rezerwacje" << endl;
	cout << "0. exit" << endl;

	while (open)
	{
		switch (_getch())		
		{
		case '1':
			TabelaRezerwacji::zapisNew(baze);
			break;
		case '2':
			TabelaRezerwacji::edytuj(baze);
			break;
		case '3':
			;
			break;
			//...
		case '0':
			return false;
			break;
		default:
			break;
		}
	}
	return true;
}

















