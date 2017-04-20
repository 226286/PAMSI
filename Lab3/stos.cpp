#include "stos.h"
#include <iostream>

stos::stos()
{
    Tab = nullptr;              //ctor
    Size=0;
    MaxSize=16;
    Tab = new int[MaxSize];
}

stos::~stos()
{
    delete[] Tab;               //dtor
}

void stos::push(int element)
    {
        if(Size>=MaxSize)
        {
            int *NewTab = new int[MaxSize*2];
            for(int i=0; i<Size; ++i) NewTab[i]=Tab[i];
            MaxSize*=2;
            delete[] Tab;
            Tab = NewTab;
        }

        Tab[Size]=element;
        ++Size;
    }

void stos::pop()
    {
        if(!Size) return;
        --Size;
    }
int stos::top()
    {
        if(Size) return Tab[Size-1];
        return 0;
    }

bool stos::Find(int element)
    {
        for(int i=0; i<Size; ++i) if(Tab[i]==element) return true;
        return false;
    }

void stos::wyswietl()
    {
        std::cout<<"Stos: ";
        if(Size)
        {
            for(int i=0; i<Size; ++i) std::cout<<Tab[i]<<' \n';
        }
        else std::cout<<"Stos jest pusty\n";
    }

int stos:: rozmiar()
    {
        return Size;
    }
