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

void BudzetOsobistyManager::wczytajFinanseZalogowanegoUzytkownikaZPliku()
{
    int idZalogowanegoAdresata = uzytkownikMenager.pobierzIdZalogowanegoUzytkownika();
    finanseMenager->wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(idZalogowanegoAdresata);
}

bool BudzetOsobistyManager::czyUzytkownikJestZalogowany()
{
    uzytkownikMenager.czyUzytkownikJestZalogowany();
}

void BudzetOsobistyManager::dodajPrzychod()
{
finanseMenager->dodajPrzychod();
}

void BudzetOsobistyManager::dodajWydatek()
{
finanseMenager->dodajWydatek();
}

void BudzetOsobistyManager::bilansZBiezacegoMiesiaca()
{
    finanseMenager->bilansZBiezacegoMiesiaca();
}

void BudzetOsobistyManager::wczytajBilansZPoprzedniegoMiesiaca()
{
    finanseMenager->wczytajBilansZPoprzedniegoMiesiaca();
}

void BudzetOsobistyManager::wczytajBilansZWybranegoOkresu()
{
    finanseMenager->wczytajBilansZWybranegoOkresu();
}
