#include "FinanseMenager.h"

void FinanseMenager::wyswietlWszytskichAdresatow()
{
    cout << " " << endl;
}

void FinanseMenager::wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(int idZalogowanegoUzytkownika)
{
    plikZFinansami.wczytajFinanseZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
