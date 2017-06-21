#include "tabasc.h"

#include <iostream>
#include <string.h>
#include <ctype.h>



using namespace std;

void assocTabNKS::insert (const char *k, int value)
{
	char *key = new char[strlen (k) + 1];
	char zn;
	int i = 0;

	while(*(k+i))
	{
		zn = *(k+i);
		zn = (char)tolower(zn);
		*(key+i) = zn;
		i++;
	}
	*(key+i) = '\0';

	assocTabKS::insert(key, value);

	delete [] key;
}

node * assocTabNKS::find (const char *k) const
{
	char *key = new char[strlen (k) + 1];
	char zn;
	int i = 0;

	while(*(k+i))
	{
		zn = *(k+i);
		zn = (char)tolower(zn);
		*(key+i) = zn;
		i++;
	}
	*(key+i) = '\0';

	return assocTabKS::find(key);
}

int & assocTabNKS::operator[] (const char *k)
{
	char *key = new char[strlen (k) + 1];
	char zn;
	int i = 0;

	while(*(k+i))
	{
		zn = *(k+i);
		zn = (char)tolower(zn);
		*(key+i) = zn;
		i++;
	}
	*(key+i) = '\0';

	return assocTabNKS::operator[](key);

	delete [] key;

}
