#include "TablicaDyn.h"

TablicaDyn::TablicaDyn()
{
	tablica = new int[rozmiar]; //ctor
	rozmiar = 0;
}

TablicaDyn::~TablicaDyn()
{
	delete[] tablica;//dtor
}

int* TablicaDyn::przypisanie(int pozycja, int wartosc)
{
	std::cout << "Podaj wartosc ktora chcesz wpisac ";
	std::cin >> wartosc;
	std::cout << "Podaj pozycje w tablicy gdzie chcesz zapisac wartosc ";
	std::cin >> pozycja;
	tablica[pozycja] = wartosc;
	return tablica;
}

int TablicaDyn::odczyt(int pozycja)
{
	std::cout << "Podaj pozycje ktorej wartosc chcesz odczytac";
	std::cin >> pozycja;
	return tablica[pozycja];
}

int TablicaDyn::jakirozmiar()
{
	std::cout << "Rozmiar Tablicy to " << rozmiar;
	return rozmiar;
}

void TablicaDyn::tablicaplusjeden(int numer)
{
	rozmiar++;
	int *tymczasowa_tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar-1; i++)
	{
		tymczasowa_tablica[i] = tablica[i];
	}
	delete[] tablica;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar - 1; i++)
	{
		tablica[i] = tymczasowa_tablica[i];
	}
	tablica[rozmiar - 1] = numer;
	delete[] tymczasowa_tablica;
}
void TablicaDyn::tablicapluspolowa(int numer)
{
	rozmiar = rozmiar *2;
	int *tymczasowa_tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar/2; i++)
	{
		tymczasowa_tablica[i] = tablica[i];
	}
	delete[]tablica;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar ; i++)
	{
		tablica[i] = tymczasowa_tablica[i];
	}
	tablica[rozmiar] = numer;
	delete[] tymczasowa_tablica;
}
