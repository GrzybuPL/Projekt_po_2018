#include <iostream>
#include <conio.h>
#include "Filtr.h"

using namespace std;

Filtr::Filtr()
{
	idOferty = -1;
	kosztDo = -1;
	kosztOd = -1;
	dataPobytuOd.setData(-1, -1, -1);
	dataPobytuDo.setData(-1, -1, -1);
	dlugoscPobytuOd = -1;
	dlugoscPobytuDo = -1;
	czAktywny = false;
}


void Filtr::edytuj()
{
	int d, m, y;

	system("cls");
	cout << "obecny wygl¹d filtru:" << endl;
	if (idOferty > -1) { cout << "id oferty: " << idOferty << endl; }
	if (kosztDo > -1) { cout << "koszt DO: " << kosztDo << endl; }
	if (kosztOd > -1) { cout << "Kost OD: " << kosztOd << endl; }
	if (dataPobytuOd.getDate() != "0-0-0") { cout << dataPobytuOd.getDate() << endl; }
	if (dataPobytuDo.getDate() != "0-0-0") { cout << dataPobytuDo.getDate() << endl; }

	cout << "czy chcesz edytowaæ filtr ?(y/n): ";
	cout << endl;

	if (getch() == 'y')
	{
		system("cls");
		cout << "Czy chcesz edytowac/dodac dane klienta " << imie << " " << nazwisko << "(y/n): ";
		cout << endl;

		if (getch() == 'y')
		{
			cout << "edycja id oferty?(y/n): ";
			if (getch() == 'y') { cin >> imie; edycja = true; }
			cout << endl;
			cout << "edycja kosztow, od?(y/n): ";
			if (getch() == 'y') { cin >> nazwisko; edycja = true; }
			cout << endl;
			cout << "edycja kosztow, do?(y/n): ";
			if (getch() == 'y') { cin >> adresZamieszkania; edycja = true; }
			cout << endl;
			cout << "edycja daty pobytu, od?(y/n): ";
			if (getch() == 'y') { cin >> nr_Tel; edycja = true; }
			cout << endl;
			cout << "edycja daty pobytu, do?(y/n): ";
			if (getch() == 'y') { cin >> eMail; edycja = true; }
			cout << endl;
			cout << "edycja daty pobytu, od?(y/n): ";
			if (getch() == 'y') { cin >> nr_Tel; edycja = true; }
			cout << endl;
			cout << "edycja dlugosci czasu pobytu, od?(y/n): ";
			if (getch() == 'y') { cin >> nr_Tel; edycja = true; }
			cout << endl;
			cout << "edycja dlugosci czasu pobytu, od?(y/n): ";
			if (getch() == 'y') { cin >> nr_Tel; edycja = true; }
			cout << endl;
			cout << "edycja zakonczona." << endl;
			system("pause");
		}

		if (czyAktywny) this->zapis();		//zapis po edycji
	}
}