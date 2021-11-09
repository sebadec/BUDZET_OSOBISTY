#ifndef PRZYCHODY_H
#define PRZYCHODY_H

#include <iostream>
#include "Finanse.h"

using namespace std;

class Przychody: public Finanse
{
    double wartosc;

public:
    bool operator<(Przychody& przychody);

};
#endif
