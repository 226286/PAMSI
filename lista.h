#ifndef LISTA_H
#define LISTA_H


class lista
{
    int element;
    element *wskaznik;
    public:
        lista();
        virtual ~lista();
        void add(int element);      //dodaje element
        void get();                 //zwraca pierwszy element
        int size();                 //zwraca ilosc elementow
        int* find(int element);     //znajduje element
        int next(int *element);     //zwraca nastepny element
    protected:
    private:
};

#endif // LISTA_H
