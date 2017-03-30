#ifndef KOLEJKA_H
#define KOLEJKA_H


class kolejka
{
    int element;
    element *wskaznik;
    public:
        kolejka();
        virtual ~kolejka();
        void push(int element)      //dodaje element na koniec kolejki
        void pop();                 //pobiera pierwszy element kolejki
        int size();                 //zwraca rozmiar kolejki
        int* find(int element);     //znajduje element
        int end();                  //zwraca wartosc pierwszego elementu kolejki
    protected:
    private:
};

#endif // KOLEJKA_H
