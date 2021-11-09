#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Finanse.h"
#include "UzytkonikMenager.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
#include "Wydatki.h"

using namespace std;

class PlikZWydatkami : public PlikTekstowy
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoWydatku;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Wydatki wydatki);
    Wydatki pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

public:
    PlikZWydatkami(string nazwaPliku)
        :PlikTekstowy(nazwaPliku)
    {
        idZalogowanegoUzytkownika = 0;
        idOstatniegoWydatku = 0;
    }

    vector <Wydatki> wczytajWydatkiZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    bool dopiszPrzychodyDoPliku(Wydatki wydatki);
    int pobierzIdOstatniegoWydatku();
};

#endif
