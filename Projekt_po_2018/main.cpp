#include <iostream>
#include "GUI/gui.h"
using namespace std;


int main(int argc, char** argv)		//Rozpoczecie dzialania programu i wywolanie reszty elemantow 
{

	if (argc > 1)
	{
		paraMain(argc, argv);		//Obsluga parametrow wprowadzanych w konsoli
	}
	else
	{
		loopProgram();				//Glowna petla programu
	}

	return 0;
}

