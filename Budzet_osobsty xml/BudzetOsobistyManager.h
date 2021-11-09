#ifndef BUDZETOSOBISTYMANAGER_H
#define BUDZETOSOBISTYMANAGER_H

#include <iostream>

#include "UzytkonikMenager.h"
#include "FinanseMenager.h"

using namespace std;

class BudzetOsobistyManager
{
    UzytkonikMenager uzytkownikMenager;
    FinanseMenager *finanseMenager;

    const string NAZWA_PLIKU_Z_PRZYCHODAMI;
    const string NAZWA_PLIKU_Z_WYDATKAMI;

public:
    BudzetOsobistyManager(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami)
        : uzytkownikMenager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami), NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami)
    {
        finanseMenager = NULL;
    };
    ~BudzetOsobistyManager()
    {
        delete finanseMenager;
        finanseMenager = NULL;
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogujUzytkownika();

    void wypiszWszystkichUzytkownikow();
    void wylogowanieUzytkownika();
    void wczytajFinanseZalogowanegoUzytkownikaZPliku();

    bool czyUzytkownikJestZalogowany();

    void dodajPrzychod();
    void dodajWydatek();
    void bilansZBiezacegoMiesiaca();
    void wczytajBilansZPoprzedniegoMiesiaca();
    void wczytajBilansZWybranegoOkresu();
    void zmianaHaslaZalogowanegoUzytkownika();

};

#endif
