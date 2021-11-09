#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Finanse.h"
#include "UzytkonikMenager.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
#include "Przychody.h"

using namespace std;

class PlikZPrzychodami : public PlikTekstowy
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoPrzychodu;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Przychody przychody);
    Przychody pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

public:
    PlikZPrzychodami(string nazwaPliku)
        :PlikTekstowy(nazwaPliku)
    {
        idZalogowanegoUzytkownika = 0;
        idOstatniegoPrzychodu = 0;
    }

    vector <Przychody> wczytajPrzychodyZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    bool dopiszPrzychodyDoPliku(Przychody przychody);
    int pobierzIdOstatniegoPrzychodu();
};

#endif
