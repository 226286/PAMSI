#ifndef STOS_H
#define STOS_H


class stos
{
    int element;
    element *wskaznik;
    public:
        stos();
        virtual ~stos();
        void push(int element)      //dodaje element na wierzch stosu
        void pop();                 //zdejmuje element ze stosu
        int size();                 //zwraca aktualny rozmiar stosu
        int* find(int element);     //znajduje element na stosie
        int top();                  //wraca wartosc elementu znajdujacego sie na wierzchu stosu
    protected:
    private:
};

#endif // STOS_H
