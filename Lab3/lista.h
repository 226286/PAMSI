#ifndef LISTA_H
#define LISTA_H

struct Node
{
    int element;
    Node *Next;
    Node()
    {
        element = 0;
        Next = nullptr;
    }
};

class lista
{
    Node *First;
    int Size;
    public:
        lista();
        void add(int index,int element);      //dodaje element w miejscu wskazanym przez indeks
        int GetFirst();                       //zwraca pierwszy element
        int GetLast();                        //zwraca ostatni element
        int rozmiar();                        //zwraca ilosc elementow
        bool Find(int element);               //znajduje element
        void Remove(int index);                //usuwa element o podanym indeksie
        void wyswietl();
    protected:
    private:
};

#endif // LISTA_H
