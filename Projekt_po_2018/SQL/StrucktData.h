#pragma once
#include <iostream>
#include <string>

using namespace std;


struct Data//struktura daty :d-m-y  |dla -1 -1 -1  wynik 0-0-0
{
	int day = 0;
	int mounth = 0;
	int year = 0;

	bool setData(int d, int m, int y)
	{
		if (d > 0 && d < 32 || d == -1)
		{
			if (m > 0 && m < 13 || m == -1)
			{
				if (y > 2000 || y == -1)
				{
					if (d == -1)
					{
						day = 0;
						mounth = 0;
						year = 0;
					}
					else
					{
						day = d;
						mounth = m;
						year = y;
					}
					return true;
				}
			}
		}
		return false;
	}

	string getDate()
	{
		return to_string(day) + " - " + to_string(mounth) + " - " + to_string(year);
	}

};