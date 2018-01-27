#pragma once
#include <iostream>
#include <string>

using namespace std;
class BazaDanych;

class TabelaKlient : public BazaDanych {

	int idKlienta;
	string imie;
	string nazwisko;
	string adresZamieszkania;
	string nr_Tel;
	string eMail;
	bool edycja;  // true -false

public:

	virtual void odczyt();
	virtual void zapis() ;
	virtual void edytuj() ;
	virtual void zapisNew();





};