#include "lista.h"
#include <iostream>

lista::lista()
{
    First = nullptr;    //ctor
    Size = 0;
}

void lista:: add(int index, int element)
    {
        if(index==0)
        {
            Node *NewNode = new Node;
            NewNode->element = element;
            NewNode->Next = First;
            First = NewNode;
            ++Size;
        }
        else if(index==Size)
        {
            Node *Temp = First;
            while(Temp->Next)
            {
                Temp = Temp->Next;
            }
            Node *NewNode = new Node;
            NewNode->element = element;
            Temp->Next = NewNode;
            ++Size;
        }
        else if(index>0 && index<Size)
        {
            Node *Temp = First;
            Node *TempBefore = nullptr;
            while(index)
            {
                --index;
                TempBefore = Temp;
                Temp = Temp->Next;
            }
            Node *NewNode = new Node;
            NewNode->element = element;
            TempBefore->Next = NewNode;
            NewNode->Next = Temp;
            ++Size;
        }
    }

void lista:: Remove(int index)
    {
        if(index==0 && Size==1)
        {
            delete First;
            First = nullptr;
            Size = 0;
        }
        else if(index==0)
        {
            Node *ToRemove = First;
            First = First->Next;
            delete ToRemove;
            --Size;
        }
        else if(index>0 && index<=Size)
        {
            --index;
            Node *Temp = First;
            while(index)
            {
                --index;
                Temp = Temp->Next;
            }
            Node *ToRemove = Temp->Next;
            Temp->Next = Temp->Next->Next;
            delete ToRemove;
            --Size;
        }
    }


int lista::GetFirst()
    {
        if(First) return First->element;
        return 0;
    }

int lista::GetLast()
    {
        if(!First) return 0;

        Node *Temp = First;
        while(Temp->Next)
        {
            Temp = Temp->Next;
        }
        return Temp->element;
    }
int lista::rozmiar()
    {
        return Size;
    }

bool lista::Find(int element)
    {
        if(!First) return false;

        Node *Temp = First;
        while(Temp->Next)
        {
            if(Temp->element == element) return true;
            Temp = Temp->Next;
        }
        return false;
    }

 void lista::wyswietl()
    {
        std::cout<<"Lista: ";
        if(Size)
        {
            Node *Temp = First;
            while(Temp)
            {
                std::cout<<Temp->element<<' ';
                Temp = Temp->Next;
            }
            std::cout<<'\n';
        } else std::cout<<"lista jest pusta\n";
    }
