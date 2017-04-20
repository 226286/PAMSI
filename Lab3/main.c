#include "stoper.h"
#include "stos.h"
#include "lista.h"
#include "kolejka.h"

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    lista list;
    for(int i=0; i<10; ++i)
    {
        list.add(0,i);
    }
    stoper time;
    time.sstart;
    list.Find(10);
    time.sstop;
    time.wynik();

    kolejka queque;
    for(int i=0; i<10; ++i)
    {
        queque.push(i);
    }
    time.sstart;
    queque.Find(10);
    time.sstop;
    time.wynik();

    stos stack;
    for(int i=0; i<10; ++i)
    {
        stack.push(i);
    }
    time.sstart;
    stack.Find(10);
    time.sstop;
    time.wynik();
}
