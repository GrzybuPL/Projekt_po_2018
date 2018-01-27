#pragma once

//interface SQL
//proste mini menu, mozliwosc wprowadzania danych


class SQL
{
	//sqlite3 *db;
	int rc;

	//TabelaKlient *klient;
	//TabelaOfert *oferty;
	//TabelaPromocji *promocje;

public:
	//wszytkie g³ówne metody jak zadaj puytanie->po czym mam  czukac->zwruc szukan¹ wartosc
	//zwracaj wszytko string
	//uogulnienie wszytystkich baz

    SQL(const char* nazwaBazy_);
	~SQL();



	//bool znajdzi_klienta();//pyta cie po czym ma szukac

};



//void wczydaj_bazy(SQL *&);//tworzy klasy otwiera pliki itd