#ifndef STOS_H
#define STOS_H


class stos
{
    int *Tab;
    int MaxSize;
    int Size;

    public:
        stos();
        virtual ~stos();
        void push(int element);     //dodaje element na wierzch stosu
        void pop();                 //zdejmuje element ze stosu
        int rozmiar();              //zwraca aktualny rozmiar stosu
        bool Find(int element);     //znajduje element na stosie
        void wyswietl();            //wyswietla zawartosc stosu
        int top();                  //wraca wartosc elementu znajdujacego sie na wierzchu stosu
    protected:
    private:
};

#endif // STOS_H
