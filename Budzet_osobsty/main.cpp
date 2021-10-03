#include <iostream>

#include "BudzetOsobistyManager.h"

using namespace std;

int main()
{
    char wybor;

    BudzetOsobistyManager budzetOsobistyMenager("Uzytkownicy.txt", "Przychody.txt", "Wydatki.txt");

    budzetOsobistyMenager.wypiszWszystkichUzytkownikow();

    while (true)
    {
        if (budzetOsobistyMenager.czyUzytkownikJestZalogowany() == false)
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                cin.sync();
                budzetOsobistyMenager.rejestracjaUzytkownika();
                cin.sync();
                break;
            case '2':
                cin.sync();
                budzetOsobistyMenager.logowanieUzytkownika();
                cin.sync();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                budzetOsobistyMenager.dodajPrzychod();
                break;
            case '2':
                budzetOsobistyMenager.dodajWydatek();
                break;
            case '3':
                budzetOsobistyMenager.bilansZBiezacegoMiesiaca();
                break;
            case '4':
                budzetOsobistyMenager.wczytajBilansZPoprzedniegoMiesiaca();
                break;
            case '5':
                budzetOsobistyMenager.wczytajBilansZWybranegoOkresu();
                break;
            case '6':
                budzetOsobistyMenager.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                budzetOsobistyMenager.wylogowanieUzytkownika();
                break;
            }
        }
    }

    return 0;
}
