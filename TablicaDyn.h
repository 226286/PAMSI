#ifndef TABLICADYN_H
#define TABLICADYN_H
#include <iostream>

class TablicaDyn
{
public:
	TablicaDyn();
	virtual ~TablicaDyn();
	int pozycja, wartosc;
	int* przypisanie(int pozycja, int wartosc);
	void odczyt(int pozycja);
	int *tablica;
	void jakirozmiar();
	void tablicaplusjeden(int rozmiar);
	void tablicapluspolowa(int rozmiar);
protected:
private:
	int rozmiar;
	int wypelenienie;



};


#endif // TABLICADYN_H
