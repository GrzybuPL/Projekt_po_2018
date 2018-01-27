#include <iostream>
#include "GUI/gui.h"
using namespace std;


int main(int argc, char** argv)
{

	if (argc > 1)
	{
		paraMain(argc, argv);
	}
	else
	{
		loopProgram();
	}


	return 0;
}

