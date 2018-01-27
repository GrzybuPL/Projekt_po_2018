#pragma once

using namespace std;

class BazaDanych {

public:

	virtual void odczyt() = 0;//wyswietla wszystkie znaczace dane w odpowiedni sposob   + trrzeba pamietac o filtrez
	virtual void zapis() = 0;// jezeli bool edycja jest true zapisuje edtyowane dane do bazy
	virtual void edytuj() = 0;//edycja danych z natychmiastowym zapisem do bazy
	virtual void zapisNew() = 0;//zapisuje do tablicy jako nowe dane
};
