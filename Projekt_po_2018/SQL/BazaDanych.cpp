


//ogulnie toio niepotrzeba tego pliku .cpp bo klasa bazaDanych sta³a sie virtualn¹  ale nie wiem po co jet biblioteka time .h













//#include <iostream>

//#include <string>
//#include "sqlite3.h"
//#include "BazaDanych.h"


//=====================TabelaKlient=====================










//====================stare=======================

/*
BazaDanych::BazaDanych(int IdKlienta_, string Imie_, string Nazwisko_, string Adres, short int NrTel_, string EMali_) {
	IdKlienta = idKlienta_;
	Imie = Imie_;
	Nazwisko = Nazwisko_;
	AdresZamieszkania = Adres;
	Nr_tel = NrTel_;
	EMail = EMali_;
}
*/
///BazaDanych::~BazaDanych() {

///}
/*
void BazaDanych::zapisDoBazy(string Baza) { //Po co to???

}
*/
//no spoko tylko ze ta metoda jest nei optymalna bo po co przesy³ac jej zmienne skoro posiadam je w danych klasy do ktorych metody maj¹ zawsze 100% dostêpu chyba ze to twozy nowego 
/*

void BazaDanych::zapisDoKlienci(string Imie_, string Nazwisko_, string AdresZamieszkania_, string  NrTel_, string EMail_) {
	string quest = "INSERT INTO klienci VALUES(NULL, " + Imie_ + ", " + Nazwisko_ + ", " + AdresZamieszkania_ + ", " + NrTel_ + ", " + EMail_ + ");";
	const char * sql = quest.c_str();
	sqlite3 *db;
	char * zErrMsg = 0;
	string number;


	sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
}

void BazaDanych::zapisDoPromocja(string CenaPromocji_, string ZasadyPromocji_, string CzasTrwaniaPromocji_) {//float nma stroing

	string quest = "INSERT INTO klienci VALUES(NULL, " + CenaPromocji_ + ", " + ZasadyPromocji_ + ", " + CzasTrwaniaPromocji_ + ");";
	const char * sql = quest.c_str();
	sqlite3 *db;
	char * zErrMsg = 0;

	

	
	sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
}

void BazaDanych::zapisDoDaneRezerwacji() { //Co z idikami???

}

void BazaDanych::zapisDoDaneOferty(string Koszt_, string Gdzie_, string DataPobytuOd_, int DlugoscPobytu_, string RodzajTransportu_) {//float na striong
	string quest = "INSERT INTO klienci VALUES(NULL, " + Koszt_ + ", " + Gdzie_ + ", " + DataPobytuOd_ + ", " + to_string(DlugoscPobytu_) + ", " + RodzajTransportu_ + ");";
	const char * sql = quest.c_str();
	sqlite3 *db;
	char * zErrMsg = 0;

	sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
}*/