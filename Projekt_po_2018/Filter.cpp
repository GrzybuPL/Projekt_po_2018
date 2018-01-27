#include <iostream>
#include "Filter.h"
#include <conio.h>

using namespace std;

Filter::Filter()
{
	idOferty = -1;
	kosztDo = -1;
	kosztOd = -1;
	dataPobytuOd.setData(-1, -1, -1);
	dataPobytuDo.setData(-1, -1, -1);
	dlugoscPobytuOd = -1;
	dlugoscPobytuDo = -1;
	edycja = false;
}


void Filter::edytuj()
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

		cout << "no to yolo";

	}
}