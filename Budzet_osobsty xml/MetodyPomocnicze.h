#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <string>

#include <windows.h>
#include <winbase.h>
#include <ctime>
#include <cstdio>

#include "PlikTekstowy.h"

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static char wybierzOpcjeZMenuFinansu();
    static bool czyPlikJestPusty(fstream &plikTekstwoy);
    static string ustawienieDaty();
    static string dzisiejszaData();
    static string podanaData();
    static int konwersjaRokMiesiacDzienStringNaRokMiesiacInt(string RokMiesiacDzienString);
    static int konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(string RokMiesiacDzienString);
    static double konwersjaStringNaDouble(string liczba);
    static string konwersjaPrzecinekNaKropki(string tekstZPrzecinkiem);

private:
    static bool sprawdzanieCzyDataJestPrawidlowa(int dzien, int miesiac, int rok);
};

#endif
