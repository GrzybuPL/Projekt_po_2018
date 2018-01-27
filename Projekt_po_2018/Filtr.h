#include <iostream>
#include "SQL/StrucktData.h"
using namespace std;


class Filtr
{
	int idOferty;
	float kosztOd;
	float kosztDo;
	Data dataPobytuOd;
	Data dataPobytuDo;
	int dlugoscPobytuOd;
	int dlugoscPobytuDo;
	bool czyAktywny;		//Czy filtr zostal uzyty
public:
	Filtr();		//wartosci domyslne to -1

	void edytuj();


};