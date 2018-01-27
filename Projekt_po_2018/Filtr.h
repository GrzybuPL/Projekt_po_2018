#include <iostream>
#include "SQL/StrucktData.h"
using namespace std;


class Filtr
{
	int idOferty;
	float kosztDo;
	float kosztOd;
	Data dataPobytuOd;
	Data dataPobytuDo;
	int dlugoscPobytuOd;
	int dlugoscPobytuDo;
	bool czAktywny;
public:
	Filtr();//wartosci domyslne to -1

	void edytuj();


};