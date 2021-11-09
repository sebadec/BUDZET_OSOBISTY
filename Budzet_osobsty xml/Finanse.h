#ifndef FINANSE_H
#define FINANSE_H

#include <iostream>

using namespace std;

class Finanse
{
    int finanseId;
    int uzytkownikId;
    string wartosc;
    string typFinansu;

public:

    string data;
    void ustawFinanseId(int newFinanseId);
    void ustawUzytkownikId(int newUzytkownikId);
    void ustawDate(string newDate);
    void ustawWartosc(string newWartosc);
    void ustawTypFinansu(string newTypFinansu);

    int pobierzFinanseId();
    int pobierzUzytkownikId();
    string pobierzDate();
    string pobierzWartosc();
    string pobierzTypFinansu();
};

#endif
