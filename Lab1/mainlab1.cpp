#include <iostream>
#include <cstdio>
#include <ctime>
#include "TablicaDyn.h"

using namespace std;

int main()
{
	clock_t s, f;
	double czas = 0;

    int rozmiar = 2;
	TablicaDyn tab;
	s = clock();
	for (int i =0; i < 100000; i++)
	{
        tab.tablicapluspolowa(i);



    }


	/*for (int i = 0; i < 10; i++)
	{

		tab.tablicaplusjeden(i);


		for (int i = 0; i < rozmiar; i++)
		{
			std::cout << tab.tablica[i] << " ";
		}
		std::cout << "\n";

	}*/
	f = clock();
	czas = (double)(f - s) / (double)(CLOCKS_PER_SEC);
	cout <<"czas "<< czas << endl;
	return 0;
}



