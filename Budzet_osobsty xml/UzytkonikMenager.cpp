#include "UzytkonikMenager.h"

void UzytkonikMenager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkonikMenager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawUzytkownikId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    string imie;
    cout << "Podaj imie: ";
    cin >> imie;
    uzytkownik.ustawImie(imie);

    string nazwistko;
    cout << "Podaj nazwisko: ";
    cin >> nazwistko;
    uzytkownik.ustawNazwisko(nazwistko);

    return uzytkownik;
}

int UzytkonikMenager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzUzytkownikId() + 1;
}

bool UzytkonikMenager::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkonikMenager::wypiszWszytskichUzytkownikow()
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzUzytkownikId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkonikMenager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> Uzytkownik::pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> Uzytkownik::pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = itr -> Uzytkownik::pobierzUzytkownikId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    //system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkonikMenager::zmianaHaslaZalogowanegoUzytkownikaUM()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> Uzytkownik::pobierzUzytkownikId() == idZalogowanegoUzytkownika)
        {
            itr -> Uzytkownik::ustawHaslo(noweHaslo);
            plikZUzytkownikami.zmianaHaslaWPlikuZUzytkownikami(idZalogowanegoUzytkownika, noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

void UzytkonikMenager::wylogowanieUzytkownikaUM()
{
    idZalogowanegoUzytkownika = 0;
}

bool UzytkonikMenager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkonikMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
