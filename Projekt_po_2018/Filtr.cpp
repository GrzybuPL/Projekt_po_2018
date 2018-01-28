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
	czyAktywny = false;
}


void Filtr::edytuj()
{
	int d, m, y;

	system("cls");
	cout << "Obecny wyglad filtru:" << endl;
	if (idOferty > -1) { cout << "id oferty: " << idOferty << endl; }
	if (kosztOd > -1) { cout << "Koszt OD: " << kosztOd << endl; }
	if (kosztDo > -1) { cout << "koszt DO: " << kosztDo << endl; }
	if (dataPobytuOd.getDate() != "0-0-0") { cout << dataPobytuOd.getDate() << endl; }
	if (dataPobytuDo.getDate() != "0-0-0") { cout << dataPobytuDo.getDate() << endl; }

	cout << "Czy chcesz edytowaæ filtr?(y/n): ";
	cout << endl;


	if (getch() == 'y')
	{
		cout << "Edycja id oferty?(y/n): ";
		if (getch() == 'y') { cin >> idOferty; czyAktywny = true; }
		cout << endl;
		cout << "Edycja kosztow, od?(y/n): ";
		if (getch() == 'y') { cin >> kosztOd; czyAktywny = true; }
		cout << endl;
		cout << "Edycja kosztow, do?(y/n): ";
		if (getch() == 'y') { cin >> kosztDo; czyAktywny = true; }
		cout << endl;
		cout << "Edycja daty pobytu, od?(y/n): ";
		if (getch() == 'y')
		{
			cout << "dzien: ";
			cin >> d;
			cout << "miesiac: ";
			cin >> m;
			cout << "rok: ";
			cin >> y;
			dataPobytuOd.setData(d, m, y);
			czyAktywny = true;
		}
		cout << endl;
		cout << "Edycja daty pobytu, do?(y/n): ";
		if (getch() == 'y')
		{
			cout << "dzien: ";
			cin >> d;
			cout << "miesiac: ";
			cin >> m;
			cout << "rok: ";
			cin >> y;
			dataPobytuOd.setData(d, m, y);
			czyAktywny = true;
		}
		cout << endl;
		cout << "Edycja daty pobytu, od?(y/n): ";
		if (getch() == 'y') { cin >> dlugoscPobytuOd; czyAktywny = true; }
		cout << endl;
		cout << "Edycja dlugosci czasu pobytu, do?(y/n): ";
		if (getch() == 'y') { cin >> dlugoscPobytuDo; czyAktywny = true; }
		cout << endl;
		cout << "Edycja zakonczona" << endl;
		system("pause");
	}

}
