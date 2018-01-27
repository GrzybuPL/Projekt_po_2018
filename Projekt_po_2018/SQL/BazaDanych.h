#pragma once
#include <iostream>
#include <string>
//#include <time.h> po co to bo nei wiem????

using namespace std;


//strudktura backgrand
//mechanizmy wczytwyania, wyciagania, edycji danych

class BazaDanych {

public:
	//BazaDanych();
//	~BazaDanych();

	virtual void odczyt() = 0;//wyswietla wszystkie znaczace dane w odpowiedni sposob   + trrzeba pamietac o filtrez
	virtual void zapis() = 0;// jezeli bool edycja jest true zapisuje edtyowane dane do bazy
	virtual void edytuj() = 0;//edycja danych z natychmiastowym zapisem do bazy
	virtual void zapisNew() = 0;//zapisuje do tablicy jako nowe dane
	/*
	virtual void sortowanie();// po co sortowanie?	
	void zapisDoKlienci(string, string, string, string, string);
	void zapisDoPromocja(string, string, string);
	void zapisDoDaneRezerwacji(); //Przemyœleæ te id-iki
	void zapisDoDaneOferty(string, string, string, int, string);
	*/

};

//string kontanentacja = "to co potrzebujesz"+...imie_+;

/*

class BazaDanych {
protected:
//zmienne
public:
BazaDanych();
~BazaDanych();
//nie maj¹ inicializacji 
virtual void odczyt(string)=0;
virtual void zapisDo(string)=0;
virtual void sortowanie(string)=0;

void zapisDoKlienci(string, string, string, short int, string);
void zapisDoPromocja(float, string, string);
void zapisDoDaneRezerwacji(); //Przemyœleæ te id-iki
void zapisDoDaneOferty(float, string, string, int, string);
};

class BazaKlient: publick BazaDanych  {
private:

int IdKlienta;
short int Nr_tel;
string Imie;
string Nazwisko;
string AdresZamieszkania;
string EMail;

public:
BazaDanych();
//maj¹ iniclalizacje
virtual void odczyt(string);
virtual void zapisDo(string);
virtual void sortowanie(string);

};

void BazaKlient::odczyt(string){

...

}




class BazaKlient2: publick BazaDanych  {
private:


public:

virtual void odczyt(string);
virtual void zapisDo(string);
virtual void sortowanie(string);

};
void BazaKlient2::odczyt(string){

...

}

class BazaPromocje: publick BazaDanych  {
private:
sdhh
public:

virtual void odczyt(string);
virtual void zapisDo(string);
virtual void sortowanie(string);

};

void BazaPromocje::odczyt(string){

...

}

class BazaOferty: publick BazaDanych  {
private:
fsdfsdf
public:

virtual void odczyt(string);
virtual void zapisDo(string);
virtual void sortowanie(string);

};




BazaDanych *SQL;

BazaOferty *A=new BazaOferty(<przyk³adowe parametry>);
BazaPromocje *B=new...;
BazaKlient* C...;
BazaKlient2* D...;



switch(i)
{case
SQL=A;
case
SQL=B;
case
SQL=C;
case
SQL=D;
}

SQL->odczyt();


*/
