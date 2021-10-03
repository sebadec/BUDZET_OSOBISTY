#ifndef FINANSEMENAGER_H
#define FINANSEMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Finanse.h"
#include "PlikZFinansami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class FinanseMenager {

const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
vector <Finanse> finanse;
PlikZFinansami plikZFinansami;

public:
    FinanseMenager(string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika)
    : plikZFinansami(nazwaPlikuZPrzychodami, nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        finanse = plikZFinansami.wczytajFinanseZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        cout << " " << endl;
    };

    void czyUzytkownikJestZalogowany();
    void dodajAdresataAM();
    void wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(int idZalogowanegoUzytkownikaAM);
    void wyswietlWszytskichAdresatow();


};


#endif
