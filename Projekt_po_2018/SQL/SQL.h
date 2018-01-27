#pragma once

//interface SQL
//proste mini menu, mozliwosc wprowadzania danych


class SQL
{
	sqlite3 *db;
	TabelaKlient *klient;
	TabelaOfert *oferty;
	TabelaPromocji *promocje;
	TabelaRezerwacji *rezerwacje;
public:
	//wszytkie g³ówne metody jak zadaj puytanie->po czym mam  czukac->zwruc szukan¹ wartosc
	//zwracaj wszytko string
	//uogulnienie wszytystkich baz
	
	SQL(const char* nazwaBazy_);
	~SQL();



	bool znajdzi_klienta();//pyta cie po czym ma szukac

};

void menuKlient(SQL * &baze);
void menuPromo(SQL * &baze);
void menuRezer(SQL * &baze);


void wczydaj_bazy(SQL *&);//tworzy klasy otwiera pliki itd

