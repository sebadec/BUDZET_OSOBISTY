#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
    if (uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownikaUM();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenager.wylogowanieUzytkownikaUM();
    delete adresatMenager;
    adresatMenager = NULL;
    cout << "Wylogowanie udane" << endl;
    system("pause");
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager->dodajAdresataAM();
    }
    else
    {
    cout << "Pierw sie zaloguj" << endl;
    system("pause");
    }
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA()
{
    int idZalogowanegoAdresata = uzytkownikMenager.pobierzIdZalogowanegoUzytkownika();
    adresatMenager->wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(idZalogowanegoAdresata);
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenager->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenager->edytujAdresata();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenager->wyszukajAdresatowPoNazwisku();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    uzytkownikMenager.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wyswietlWszytskichAdresatow()
{
    adresatMenager->wyswietlWszytskichAdresatow();
}
