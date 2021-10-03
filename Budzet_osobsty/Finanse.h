#ifndef FINANSE_H
#define FINANSE_H

#include <iostream>

using namespace std;

class Finanse
{
    int finanseId;
    int uzytkownikId;
    int data;
    string wartosc;

public:

    void ustawFinanseId(int id);
    void ustawUzytkownikId(int id);
    void ustawDate(int newDate);
    void ustawWartosc(string newItem);

    int pobierzFinanseId();
    int pobierzUzytkownikId();
    int pobierzDate();
    string pobierzWartosc();
};

#endif
