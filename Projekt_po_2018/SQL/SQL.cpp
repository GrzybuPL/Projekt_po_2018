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
	klient->dodaj(db);
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


void SQL::addOfert()
{
	oferty->zerowanie();
	oferty->dodaj(db);
}
//==============promocje

void SQL::showAllPromocje()
{
	promocje->odczyt(db);
}


void SQL::znajdz_Promocje()
{
	int id;

	cout << "podaj id: "; cin >> id;

	promocje->odczytPoId(id, db);

	//if (id>0)promocje->odczytPoId(id, db);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}

void SQL::addPromo()
{
	promocje->zerowanie();
	promocje->dodaj(db);
}

//===============rezerwacje

void SQL::addRezer()
{
	rezerwacje->zerowanie();
	rezerwacje->dodaj(db);
}

void SQL::showAllRezer()
{
	rezerwacje->odczyt(db);
}

void SQL::znajdz_Rezerwacje()
{
	int id;

	cout << "podaj id: "; cin >> id;

	rezerwacje->odczytPoId(id, db);

	//if (id>0)rezerwacje->odczytPoId(id, db);!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

//----klienci
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
		cout << "3. Wyswietl wszystkich klientow" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			cout << "Podaj imie: "; cin >> buf1;
			cout << "Podaj nazwisko: "; cin >> buf2;
			baze->znajdz_Klienta(buf1, buf2);
			system("pause");
			break;
		case '2':
			baze->addKlient();
			system("pause");
			break;
		case '3':
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
//-------------oferty
void menuOfert(SQL * &baze)
{
	bool open = true;

	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Wybierz oferte" << endl;
		cout << "2. Pokaz wszystkie oferty" << endl;
		cout << "3. dodaj oferte" << endl;
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
			baze->addOfert();
			system("pause");
			break;
		case '0':
			open = false;
			system("pause");
			break;
		default:
			break;
		}
	}
}
//-----promocje
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
		cout << "3. pokaz wszystkie promocje" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			baze->znajdz_Promocje();
			system("pause");
			break;
		case '2':
			baze->addPromo();
			system("pause");
			break;
		case '3':
			baze->showAllPromocje();
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
//---------------rezerwacje
void menuRezer(SQL * &baze)
{
	bool open = true;
	
	while (open)
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "Wybierz jedna z opcji co chcesz zrobic:" << endl;
		cout << "1. Dokonaj rezerwacji" << endl;
		cout << "2. Znajdz rezerwacje" << endl;
		cout << "3. Pokaz wszystkie rezerwacje" << endl;
		cout << "0. exit" << endl;

		switch (_getch())
		{
		case '1':
			baze->addRezer();
			system("pause");
			break;
		case '2':
			baze->znajdz_Rezerwacje();
			system("pause");
			break;
		case '3':
			baze->showAllRezer();
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















