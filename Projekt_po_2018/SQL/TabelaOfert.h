#pragma once
#include <iostream>
#include <string>

using namespace std;
class BazaDanych;

class TabelaOfert : public BazaDanych {
	int idOferty;
	string nazwa;
	string koszt;
	string miejsce;
	string dlugoscPobytu;
	string transport;
	Data odDnia;
	Data doDnia;
	bool edycja;
	int idPromocji;//-1 dla braku promocji
public:

	virtual void odczyt();
	virtual void zapis() ;
	virtual void edytuj() ;
	virtual void zapisNew() ;



};