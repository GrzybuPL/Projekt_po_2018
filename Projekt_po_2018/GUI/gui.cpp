#include <iostream>
#include "gui.h"//Dominik Grzyboweski  interface uzytkownika
#include "../SQL/SQL.h"//Marcin Zuber oprracje na bazie danych 


using namespace std;


//int argc, char** argv

//SQL* baza-nullptr;


//wcztraj(baza);



//======================obs³uga parametrów z cmd
//help

void paraMain(int &argc, char** argv)
{


	//wywo³ywanie programuz nazwa bazy danych -b <nazwa_bazy>

}

bool menu(SQL* &baze)
{



	return true;
}


void welkom()
{
	cout << endl;

}

void loopProgram(const char* nazwa_= "BiuroPodrozy.db")
{
	bool strat = true;

	SQL *baze=new SQL(nazwa_);  //obiekt bazy danych

	while (strat)
	{

		// funkcja powitanie

		//funkcja  strat= menu(*baze)

		if(menu(baze)) 



	}
}


