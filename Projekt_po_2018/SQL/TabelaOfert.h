#pragma once
#include <iostream>
#include <string>
#include "StrucktData.h"
#include "BazaDanych.h"

using namespace std;

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
	int idPromocji;		//-1 dla braku promocji
public:

	virtual void odczyt();
	virtual void zapisAdd() ;
	virtual void edytuj() ;
	virtual void zapisNew() ;



};