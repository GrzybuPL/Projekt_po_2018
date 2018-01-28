#include <iostream>
#include <string>
#include <conio.h>
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

	//klient = new TabelaKlient;
	//oferty = new TabelaOfert;
	//promocje = new TabelaPromocji;
	//rezerwacje = new TabelaRezerwacji;
	wsk = nullptr;
}


SQL::~SQL()
{
	//delete klient;
	//delete oferty;
	//delete promocje;
	//delate rezerwacje
	sqlite3_close(db);		//zamkniecie bazy danych
}

void menuPromo(SQL * &baze)
{
	bool open = true;

	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Znajdz promocje" << endl;
		cout << "2. Stworz promocje" << endl;
		cout << "3. Zmien promocje" << endl;
		cout << "4. Usun promocje" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			;
			break;
		case '2':
			//zapisNew(baze);
			break;
		case '3':
			//edytuj(baze);
			break;
		case '4':
			//usunPromocje(baze);
			break;
			//...
		case '0':
			open = false;
			break;
		default:
			break;
		}

	}

}


void menuRezer(SQL * &baze)
{
	bool open = true;
	
	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Dokonaj rezerwacji" << endl;
		cout << "2. Edytuj rezerwacjami" << endl;
		cout << "3. Anuluj rezerwacje" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			//TabelaRezerwacji::zapisNew(baze);
			break;
		case '2':
			//TabelaRezerwacji::edytuj(baze);
			break;
		case '3':
			;
			break;
			//...
		case '0':
			open = false;
			break;
		default:
			break;
		}
	}
}















