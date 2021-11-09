#ifndef UZYTKONIKMENAGER_H
#define UZYTKONIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkonikMenager{

int idZalogowanegoUzytkownika = 0;
vector <Uzytkownik> uzytkownicy;
PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkonikMenager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    }
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownikaUM();
    void wylogowanieUzytkownikaUM();
    int pobierzIdZalogowanegoUzytkownika();

    void wypiszWszytskichUzytkownikow();
    bool czyUzytkownikJestZalogowany();

};

#endif
