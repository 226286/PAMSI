#include "kolejka.h"
#include <iostream>

kolejka::kolejka()
{
    Tab = nullptr;              //ctor
    Size=0;
    MaxSize=16;
    Tab = new int[MaxSize];
}


kolejka::~kolejka()
{
    delete[] Tab;               //dtor
}

 void kolejka::push(int element)
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

 void kolejka::pop()
    {
        if(!Size) return;
        --Size;
        for(int i=0; i<Size; ++i) Tab[i]=Tab[i+1];
    }
 int kolejka::Back()
    {
        if(Size) return Tab[Size-1];
        return 0;
    }
int kolejka::Front()
    {
        if(Size) return Tab[0];
        return 0;
    }



void kolejka::wyswietl()
    {
        std::cout<<"kolejka: ";
        if(Size)
        {
            for(int i=0; i<Size; ++i) std::cout<<Tab[i]<<' /n';
        } else std::cout<<"jest pusta\n";
    }

int kolejka:: rozmiar()
    {
        return Size;
    }


bool kolejka:: Find(int element)
    {
        for(int i=0; i<Size; ++i) if(Tab[i]==element) return true;
        return false;
    }
