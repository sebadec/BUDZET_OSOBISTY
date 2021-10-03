#ifndef PLIKZFINANSAMI_H
#define PLIKZFINANSAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Finanse.h"
#include "UzytkonikMenager.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZFinansami : public PlikTekstowy
{
    const string NAZWA_PLIKU_Z_PRZYCHODAMI;
    const string NAZWA_PLIKU_Z_WYDATKAMI;
    int idOstatniegoAdreata;

    bool czyPlikJestPusty(fstream &plikTekstwoy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Finanse finanse);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Finanse pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);


public:
    PlikZFinansami(string nazwaPliku, string nazwaPliku2) : PlikTekstowy(nazwaPliku)
    {
    idOstatniegoAdreata = 0;
    };
    //plikZFinansami(nazwaPlikuZPrzychodami, nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    /*
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void dopisz(string tekst);
    void edytujWybranaLinieWPliku(Adresat adresat);
    */
    vector <Finanse> wczytajFinanseZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif
