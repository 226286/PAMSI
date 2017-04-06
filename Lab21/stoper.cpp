#include "stoper.h"

stoper::stoper()
{
   start = 0;//ctor
   stop = 0;
}

stoper::~stoper()
{
    //dtor
}


void stoper::sstart()
{
    start = clock();
}

void stoper::wznow()
{
    start =clock() - stop;
}

void stoper::sstop()
{
    stop = clock();
}

clock_t stoper::wynik()
{
    return (stop-start);
}
