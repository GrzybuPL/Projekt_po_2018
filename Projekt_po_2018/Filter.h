#include <iostream>
#include "SQL/StrucktData.h"
using namespace std;


class Filter
{
	int idOferty;
	float kosztDo;
	float kosztOd;
	Data dataPobytuOd;
	Data dataPobytuDo;
	int dlugoscPobytuOd;
	int dlugoscPobytuDo;
	bool edycja;
public:
	Filter();//wartosci domyslne to -1

	void edytuj();


};