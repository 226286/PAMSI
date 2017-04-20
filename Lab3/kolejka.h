#ifndef KOLEJKA_H
#define KOLEJKA_H


class kolejka
{
    int *Tab;
    int MaxSize;
    int Size;
    public:
        kolejka();
        virtual ~kolejka();
        void push(int element);      //dodaje element na koniec kolejki
        void pop();                 //pobiera pierwszy element kolejki
        void wyswietl();
        int rozmiar();                 //zwraca rozmiar kolejki
        bool Find(int element);      //sprawdza czy element o danej wartosci istnieje w kolejce
        int Back();                 //zwraca wartosc ostatniego elementu kolejki
        int Front();                //zwraca wartosc pierwszego elementu kolejki
    protected:
    private:
};

#endif // KOLEJKA_H
