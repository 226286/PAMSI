#ifndef STOPER_H
#define STOPER_H

#include <ctime>

class stoper
{
    double czas;
    clock_t start;
    clock_t stop;
    public:
        stoper();
        virtual ~stoper();
        void sstart();
        void sstop();
        void wznow();
        clock_t wynik();
    protected:
    private:
};

#endif // STOPER_H
