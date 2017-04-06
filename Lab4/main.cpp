#include <stdio.h>
#include <stdlib.h>

#include "TablicaDyn.h"

using namespace std;

void quicksort(TablicaDyn tab,int lewa, int prawa)
{
    int x;
    if(prawa <= lewa) return;
    int i = lewa - 1;
    int j = prawa + 1;
    tab.przypisanie((lewa+prawa)/2,x);
    while(true)
    {
        while(x>tab.odczyt(++i));
        while(x<tab.odczyt(--j));
        if( i <= j)
        {
        }
        else
        {
            return;
        }
    }
    if(j > lewa)
        quicksort(tab, lewa, j);
    if(i < prawa)
        quicksort(tab, i, prawa);
}

int main()
{
    int rozmiar=2;
    int ilosc;
    cout<<"Podaj rozmiar tablicy"<<endl;
    cin>>ilosc;

    TablicaDyn tab;

    for (int i =0; i < ilosc; i++)
	{
        tab.tablicapluspolowa(i);
    }

    for(int i=0;i < ilosc; i++)
    {
    int a;
    cout<<"Podaj wartosc "<<i<<" elementu tablicy"<<endl;
    cin>>a;
    tab.przypisanie(i,a);
    }

    quicksort(tab,0, ilosc-1);
    return 0;
}
