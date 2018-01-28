#include <iostream>
#include "SQL/StrucktData.h"
using namespace std;

class Filtr
{
	int idOferty;
	float kosztOd;
	float kosztDo;
	Data dataPobytuOd;
	int dlugoscPobytuOd;
	int dlugoscPobytuDo;
	bool czyAktywny;		//Informacja czy filtr zostal uzyty
public:
	Filtr();		//wartosci domyslne to -1
	void edytuj();


};