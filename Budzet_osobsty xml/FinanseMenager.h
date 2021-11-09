#ifndef FINANSEMENAGER_H
#define FINANSEMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Finanse.h"
#include "MetodyPomocnicze.h"
#include "Przychody.h"
#include "Wydatki.h"
#include "PlikZPrzychodami.h"
#include "PlikZWydatkami.h"

using namespace std;

class FinanseMenager
{

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Przychody> przychody;
    vector <Wydatki> wydatki;
    PlikZPrzychodami plikZPrzychodami;
    PlikZWydatkami plikZWydatkami;

    Przychody ustawPrzychod();
    Wydatki ustawWydatek();

public:
    FinanseMenager(string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika)
        :
        plikZPrzychodami(nazwaPlikuZPrzychodami),
        plikZWydatkami(nazwaPlikuZWydatkami),
        ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        przychody = plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        wydatki = plikZWydatkami.wczytajWydatkiZalogowanegoUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        cout << " " << endl;
    };

    void wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(int idZalogowanegoUzytkownikaAM);
    void bilansZBiezacegoMiesiaca();
    void wczytajBilansZPoprzedniegoMiesiaca();
    void wczytajBilansZWybranegoOkresu();
    void dodajPrzychod();
    void dodajWydatek();
};

#endif
