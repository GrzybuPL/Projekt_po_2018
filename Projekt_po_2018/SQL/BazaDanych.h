#pragma once

using namespace std;

class BazaDanych {

public:

	virtual void odczyt(sqlite3 *db) = 0;			//wyswietla wszystkie znaczace dane w odpowiedni sposob + trzeba pamietac o filtrze
	virtual void zapisAdd(sqlite3 *db) = 0;		//jezeli bool edycja jest true zapisuje edtyowane dane do bazy
	virtual void edytuj(sqlite3 *db) = 0;			//edycja danych z natychmiastowym zapisem do bazy
	virtual void zapisNew(sqlite3 *db) = 0;		//zapisuje do tablicy jako nowe dane
};
