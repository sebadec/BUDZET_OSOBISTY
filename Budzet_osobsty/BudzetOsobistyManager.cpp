#include "BudzetOsobistyManager.h"

void BudzetOsobistyManager::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void BudzetOsobistyManager::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszytskichUzytkownikow();
}

void BudzetOsobistyManager::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();

    if (uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        finanseMenager = new FinanseMenager(NAZWA_PLIKU_Z_PRZYCHODAMI, NAZWA_PLIKU_Z_WYDATKAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }

}

void BudzetOsobistyManager::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownikaUM();
}

void BudzetOsobistyManager::wylogowanieUzytkownika()
{
    uzytkownikMenager.wylogowanieUzytkownikaUM();
    delete finanseMenager;
    finanseMenager = NULL;
    cout << "Wylogowanie udane" << endl;
    system("pause");
}

void BudzetOsobistyManager::dodajAdresata()
{
    /*
    if (finanseMenager.czyUzytkownikJestZalogowany())
    {
        finanseMenager->dodajAdresataAM();
    }
    else
        */
    {
        cout << "Pierw sie zaloguj" << endl;
        system("pause");
    }
}

void BudzetOsobistyManager::wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA()
{
    int idZalogowanegoAdresata = uzytkownikMenager.pobierzIdZalogowanegoUzytkownika();
    finanseMenager->wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(idZalogowanegoAdresata);
}

bool BudzetOsobistyManager::czyUzytkownikJestZalogowany()
{
    uzytkownikMenager.czyUzytkownikJestZalogowany();
}

void BudzetOsobistyManager::wyswietlWszytskichAdresatow()
{
    finanseMenager->wyswietlWszytskichAdresatow();
}

void BudzetOsobistyManager::dodajPrzychod()
{

}

void BudzetOsobistyManager::dodajWydatek()
{

}

void BudzetOsobistyManager::bilansZBiezacegoMiesiaca()
{

}

void BudzetOsobistyManager::wczytajBilansZPoprzedniegoMiesiaca()
{

}

void BudzetOsobistyManager::wczytajBilansZWybranegoOkresu()
{

}
