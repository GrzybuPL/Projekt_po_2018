#include <iostream>
#include <string>
#include "sqlite3.h"
#include "BazaDanych.h"

//#include "SQL.h"//docelowo tylko ta

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		cout << azColName[i] << argv[i] ? argv[i] : "NULL";
	}
	cout << endl;
	return 0;
}

int main(int argc, char** argv) {
	sqlite3 *db;
	int rc;
	/*const char *sql;
	const char *sql1;
	const char *sql2;
	const char *sql3;
	const char *sql4;*/
	char * zErrMsg = 0;
	
	rc = sqlite3_open("BiuroPodrozy.db", &db);

	if (rc) {
		cout << "Nie mozna otworzyc baz: " << sqlite3_errmsg(db);
		return 0;
	}
	else {
		cout << "Udane otwarcie bazy";
	}

	BazaDanych bz1;
	bz1.zapisDoKlienci("Marcin", "Zuber", "Toszek GM 2/1", 666444213, "m.zuber@wp.pl");
/*
	//sql = "CREATE TABLE klienci (id INTEGER PRIMARY KEY, Imie varchar(30), Nazwisko varchar(30), AdresZamieszkania text, NrTel int, EMail varchar(30));";
	sql1 = "CREATE TABLE dane_oferty(id_oferty integer PRIMARY KEY, Koszt float NOT NULL, Gdzie varchar(30) NOT NULL, DataPobytuOd date NOT NULL, DlugoscPobytu integer NOT NULL, RodzajTransportu varchar(20) NOT NULL);";
	sql2 = "CREATE TABLE dane_rezerwacji(id_rezerwacji integer PRIMARY KEY, id_Klienta integer NOT NULL, id_Oferty integer NOT NULL, CzyZaplacone tinyint(1) NOT NULL );";
	sql3 = "CREATE TABLE klienci(id_klienta integer PRIMARY KEY, Imie varchar(30) NOT NULL, Nazwisko varchar(30) NOT NULL, AdresZamieszkania text NOT NULL, NrTel integer NOT NULL, EMail varchar(30) NOT NULL );";
	sql4 = "CREATE TABLE promocja(id_promocji integer PRIMARY KEY, CenaPromocyjna float NOT NULL, ZasadyPromocji text NOT NULL, CzasTrwaniaPromocji integer NOT NULL);";
	//sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	sqlite3_exec(db, sql1, NULL, 0, &zErrMsg);
	sqlite3_exec(db, sql2, NULL, 0, &zErrMsg);
	sqlite3_exec(db, sql3, NULL, 0, &zErrMsg);
	sqlite3_exec(db, sql4, NULL, 0, &zErrMsg);

	sql1 = "INSERT INTO klienci VALUES(NULL, 'Arek', 'Furtka', 'Gliwice Domañskiego 2/1', '666999777', 'a.furtka@wp.pl');";
	sqlite3_exec(db, sql1, NULL, 0, &zErrMsg);

	sql2 = "SELECT * FROM klienci;";
	sqlite3_exec(db, sql2, NULL, 0, &zErrMsg);

	cout << "?" << sqlite3_errmsg(db) << endl;

	char **result = NULL;
	int rows, columns;
	sqlite3_get_table(db, sql2, &rows, &columns, &zErrMsg);

	for (int rowCtr = 0; rowCtr <= rows; ++rowCtr)
	{
		for (int colCtr = 0; colCtr < columns; ++colCtr)
		{
			// Determine Cell Position
			int cellPosition = (rowCtr * columns) + colCtr;

			// Display Cell Value
			cout.width(12);
			cout.setf(ios::left);
			cout << results[cellPosition] << " ";
		}

		// End Line
		cout << endl;

		// Display Separator For Header
		if (0 == rowCtr)
		{
			for (int colCtr = 0; colCtr < columns; ++colCtr)
			{
				cout.width(12);
				cout.setf(ios::left);
				cout << "~~~~~~~~~~~~ ";
			}
			cout << endl;
		}
	}

https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/


*/











	/*rc = sqlite3_exec(db, sql, NULL, 0, NULL);

	if (rc != SQLITE_OK) {
		cout << stderr << "SQL error: " << zErrMsg;
		sqlite3_free(zErrMsg);
	}
	else {
		cout << stdout << "Opracja przebiegla pomyslnie" << endl;
	}
	*/
	sqlite3_close(db);

	return 0;
}