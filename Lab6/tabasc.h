#ifndef TABASC_H
#define TABASC_H

#include <string.h>

struct node
{
        node *next;
        char *klucz;
        int wartosc;
        node (const char *k):next (NULL)
        {
                klucz = new char[strlen (k) + 1];
                strcpy (klucz, k);
        };

        node (const node & s):next (NULL)
        {
                if (s.klucz == NULL)
                        klucz = NULL;
                else
                {
                        klucz = new char[strlen (s.klucz) + 1];
                        strcpy (klucz, s.klucz);
                }

                wartosc=s.wartosc;
        }
         ~node ()
        {
                delete[]klucz;
        }
};

class tabasc
{
    public:
        tabasc();
        virtual ~tabasc();
        node *find (const char *k) const;
        void insert (const char *k, int value);
        tabasc & operator= (const tabasc & l);
    protected:
};

#endif // TABASC_H
