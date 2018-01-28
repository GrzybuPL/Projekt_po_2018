#include <iostream>
#include <string>
#include <conio.h>
#include "SQL.h"

using namespace std;


//=======================klienci


bool SQL::znajdz_Klienta(string im, string naz)
{
	if (klient->WyszukajKlienta(im, naz, db)) return true;
	return false;
}

void SQL::addKlient()
{
	klient->zerowanie();
	klient->edytuj(db);
}

void SQL::editKlient()
{
	string buf1, buf2;
	cout << "podaj imie: "; cin >> buf1;
	cout << "podaj nazwisko: "; cin >> buf2;
	
	if(this->znajdz_Klienta(buf1, buf2)) 	klient->edytuj(db);
	else cout << "nie ma takiego klienta" << endl;
	system("pause");
}

void SQL::showAllKlient()
{
	klient->odczyt(db);
}
//=========================oferty

void SQL::znajdz_Oferte()
{
	int id;

	cout << "podaj id: "; cin >> id;

	if(id>0)oferty-> odczytPoId(id, db);
}

void SQL::showAllOferty()
{

	oferty->odczyt(db);
}


//===============================================SQL
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
	delete rezerwacje;
	sqlite3_close(db);		//zamkniecie bazy danych
}

void menuKlient(SQL * &baze)
{
	bool open = true;
	string buf1 ,buf2;

	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Znajdz klienta" << endl;
		cout << "2. Stworz klienta" << endl;
		cout << "3. edytuj danego klienta klienta" << endl;
		cout << "4. wyswietl wszytskich" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			cout << "podja imie: "; cin >> buf1;
			cout << "podja nazwisko: "; cin >> buf2;
			baze->znajdz_Klienta(buf1, buf2);
			system("pause");
			break;
		case '2':
			baze->addKlient();
			system("pause");
			break;
		case '3':
			baze->editKlient();
			system("pause");
			break;
		case '4':
			baze->showAllKlient();
			system("pause");
			break;
		case '0':
			open = false;
			break;
		default:
			break;
		}

	}
}

void menuOfert(SQL * &baze)
{
	bool open = true;

	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Znajdz oferte" << endl;
		cout << "2. pokaz wszystkie oferty" << endl;
		cout << "3. Zmien oferte" << endl;
		cout << "4. Usun oferte" << endl;
		cout << "0. exit" << endl;
		cout << "----------------------------------------------------------" << endl;

		switch (_getch())
		{
		case '1':
			baze->znajdz_Oferte();
			system("pause");
			break;
		case '2':
			baze->showAllOferty();
			system("pause");
			break;
		case '3':
			//edytuj(baze);
			system("pause");
			break;
		case '4':
			//usunPromocje(baze);
			system("pause");
			break;
			//...
		case '0':
			open = false;
			system("pause");
			break;
		default:
			break;
		}
	}
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
		cout << "2. Edytuj rezerwacje" << endl;
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















