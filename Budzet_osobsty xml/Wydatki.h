#ifndef WYDATKI_H
#define WYDATKI_H

#include <iostream>
#include "Finanse.h"

using namespace std;

class Wydatki: public Finanse
{
    double wartosc;

public:
    bool operator<(Wydatki& wydatki);

};
#endif
