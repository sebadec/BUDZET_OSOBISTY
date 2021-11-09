#include "FinanseMenager.h"

void FinanseMenager::wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(int idZalogowanegoUzytkownika)
{
    plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    plikZWydatkami.wczytajWydatkiZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void FinanseMenager::dodajPrzychod()
{
    Przychody przychod;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    przychod = ustawPrzychod();

    przychody.push_back(przychod);
    plikZPrzychodami.dopiszPrzychodyDoPliku(przychod);
    cout << "Nowy przychod zostal dodany." << endl;

    system("pause");
}

void FinanseMenager::dodajWydatek()
{
    Wydatki wydatek;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    wydatek = ustawWydatek();

    wydatki.push_back(wydatek);
    plikZWydatkami.dopiszPrzychodyDoPliku(wydatek);
    cout << "Nowy wydatek zostal dodany." << endl;

    system("pause");
}

Przychody FinanseMenager::ustawPrzychod()
{
    string wartoscPrzychodu, wartoscPrzychoduKropka, typPrzychodu;

    Przychody przychod;

    przychod.ustawUzytkownikId(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    przychod.ustawFinanseId((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()));

    przychod.ustawDate(MetodyPomocnicze::ustawienieDaty());

    cin.sync();
    cout << "Podaj wartosc przychodu: " << endl;
    cin.sync();
    cin >> wartoscPrzychodu;
    wartoscPrzychoduKropka = MetodyPomocnicze::konwersjaPrzecinekNaKropki(wartoscPrzychodu);
    przychod.ustawWartosc(wartoscPrzychoduKropka);

    cout << "Podaj typ przychodu: " << endl;
    cin.sync();
    cin >> typPrzychodu;
    przychod.ustawTypFinansu(typPrzychodu);

    system("pause");

    return przychod;
}

Wydatki FinanseMenager::ustawWydatek()
{
    string wartoscWydatku, wartoscWydatkuKropka, typWydatku;

    Wydatki wydatek;

    wydatek.ustawUzytkownikId(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    wydatek.ustawFinanseId((plikZWydatkami.pobierzIdOstatniegoWydatku()));

    wydatek.ustawDate(MetodyPomocnicze::ustawienieDaty());

    cin.sync();
    cout << "Podaj wartosc wydatku: " << endl;
    cin.sync();
    cin >> wartoscWydatku;
    wartoscWydatkuKropka = MetodyPomocnicze::konwersjaPrzecinekNaKropki(wartoscWydatku);
    wydatek.ustawWartosc(wartoscWydatkuKropka);

    cout << "Podaj typ wydatku: " << endl;
    cin.sync();
    cin >> typWydatku;
    wydatek.ustawTypFinansu(typWydatku);

    system("pause");

    return wydatek;
}

void FinanseMenager::bilansZBiezacegoMiesiaca()
{
    string dataZBiezacegoMiesiacaString;
    int dataZBiezacegoMiesiacaInt;
    double bilansPrzychody = 0, bilansWydatki = 0;

    dataZBiezacegoMiesiacaString = MetodyPomocnicze::dzisiejszaData();
    dataZBiezacegoMiesiacaInt = MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(dataZBiezacegoMiesiacaString);

    sort(przychody.begin(), przychody.end());
    sort(wydatki.begin(), wydatki.end());
    system("cls");
    for (int ppp = przychody.size()-1; ppp >= 0; ppp--)
    {
        if (dataZBiezacegoMiesiacaInt == MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(przychody[ppp].pobierzDate()))
        {
            cout << endl    << "PrzychodyId:        " << przychody[ppp].pobierzFinanseId() << endl;
            cout            << "Data:               " << przychody[ppp].pobierzDate() << endl;
            cout            << "Typ przychodu:      " << przychody[ppp].pobierzTypFinansu() << endl;
            cout            << "Wartosc przychodu:  " << przychody[ppp].pobierzWartosc() << endl;
            bilansPrzychody = bilansPrzychody + MetodyPomocnicze::konwersjaStringNaDouble(przychody[ppp].pobierzWartosc());
        }
    }

    for (int www = wydatki.size()-1; www >= 0; www--)
    {
        if (dataZBiezacegoMiesiacaInt == MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(wydatki[www].pobierzDate()))
        {
            cout << endl    << "WydatkiId:          " << wydatki[www].pobierzFinanseId() << endl;
            cout            << "Data:               " << wydatki[www].pobierzDate() << endl;
            cout            << "Typ wydatku:        " << wydatki[www].pobierzTypFinansu() << endl;
            cout            << "Wartosc wydatku:    " << wydatki[www].pobierzWartosc() << endl;
            bilansWydatki = bilansWydatki + MetodyPomocnicze::konwersjaStringNaDouble(wydatki[www].pobierzWartosc());
        }
    }

    cout << endl    << "Przychody wynosza:  " << bilansPrzychody << endl;
    cout            << "Wydatki wynosza:    " << bilansWydatki << endl;
    cout            << "Twoj bilans to:     " << bilansPrzychody - bilansWydatki << endl;

    system("pause");
}

void FinanseMenager::wczytajBilansZPoprzedniegoMiesiaca()
{
    string dataZBiezacegoMiesiacaString;
    int dataZBiezacegoMiesiacaInt;
    double bilansPrzychody = 0, bilansWydatki = 0;

    dataZBiezacegoMiesiacaString = MetodyPomocnicze::dzisiejszaData();
    dataZBiezacegoMiesiacaInt = MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(dataZBiezacegoMiesiacaString);

    if (((dataZBiezacegoMiesiacaInt)%100) >= 2)
    {
        dataZBiezacegoMiesiacaInt =  dataZBiezacegoMiesiacaInt-1;
    }
    else
    {
        dataZBiezacegoMiesiacaInt = (((dataZBiezacegoMiesiacaInt/100)-1)*100)+12;
    }

    sort(przychody.begin(), przychody.end());
    sort(wydatki.begin(), wydatki.end());
    system("cls");
    for (int ppp = przychody.size()-1; ppp >= 0; ppp--)
    {
        if (dataZBiezacegoMiesiacaInt == MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(przychody[ppp].pobierzDate()))
        {
            cout << endl    << "PrzychodyId:        " << przychody[ppp].pobierzFinanseId() << endl;
            cout            << "Data:               " << przychody[ppp].pobierzDate() << endl;
            cout            << "Typ przychodu:      " << przychody[ppp].pobierzTypFinansu() << endl;
            cout            << "Wartosc przychodu:  " << przychody[ppp].pobierzWartosc() << endl;
            bilansPrzychody = bilansPrzychody + MetodyPomocnicze::konwersjaStringNaDouble(przychody[ppp].pobierzWartosc());
        }
    }

    for (int www = wydatki.size()-1; www >= 0; www--)
    {
        if (dataZBiezacegoMiesiacaInt == MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(wydatki[www].pobierzDate()))
        {
            cout << endl    << "WydatkiId:          " << wydatki[www].pobierzFinanseId() << endl;
            cout            << "Data:               " << wydatki[www].pobierzDate() << endl;
            cout            << "Typ wydatku:        " << wydatki[www].pobierzTypFinansu() << endl;
            cout            << "Wartosc wydatku:    " << wydatki[www].pobierzWartosc() << endl;
            bilansWydatki = bilansWydatki + MetodyPomocnicze::konwersjaStringNaDouble(wydatki[www].pobierzWartosc());
        }
    }

    cout << endl    << "Przychody wynosza:  " << bilansPrzychody << endl;
    cout            << "Wydatki wynosza:    " << bilansWydatki << endl;
    cout            << "Twoj bilans to:     " << bilansPrzychody - bilansWydatki << endl;

    system("pause");
}

void FinanseMenager::wczytajBilansZWybranegoOkresu()
{
    string dataA, dataB, dataZBiezacegoMiesiacaString;
    int dataAInt, dataBInt;
    double bilansPrzychody = 0, bilansWydatki = 0;
    bool czyDataJestWieksza = true;
    system("cls");
    while (czyDataJestWieksza == true)
    {
        cout << "Od kiedy wyszukac: ";
        dataA = MetodyPomocnicze::podanaData();
        cout << "Do kiedy wyszukac: ";
        dataB = MetodyPomocnicze::podanaData();

        dataAInt = MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(dataA);
        dataBInt = MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(dataB);

        if (dataBInt>=dataAInt)
        {
            czyDataJestWieksza = false;
        }
        else
        {
            cout << "Data pierwsza musi byc rowna lub mniejsza od daty drugiej, sprobuj jeszcze raz." << endl;
            system("pause");
            system("cls");
        }
    }

    sort(przychody.begin(), przychody.end());
    sort(wydatki.begin(), wydatki.end());
    system("cls");
    for (int ppp = przychody.size()-1; ppp >= 0; ppp--)
    {
        if ((dataAInt <= MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(przychody[ppp].pobierzDate()))
                &&(dataBInt >= MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(przychody[ppp].pobierzDate())))
        {
            cout << endl    << "PrzychodyId:        " << przychody[ppp].pobierzFinanseId() << endl;
            cout            << "Data:               " << przychody[ppp].pobierzDate() << endl;
            cout            << "Typ przychodu:      " << przychody[ppp].pobierzTypFinansu() << endl;
            cout            << "Wartosc przychodu:  " << przychody[ppp].pobierzWartosc() << endl;
            bilansPrzychody = bilansPrzychody + MetodyPomocnicze::konwersjaStringNaDouble(przychody[ppp].pobierzWartosc());
        }
    }
    for (int www = wydatki.size()-1; www >= 0; www--)
    {
        if ((dataAInt <= MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(wydatki[www].pobierzDate()))
                &&(dataBInt >= MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(wydatki[www].pobierzDate())))
        {
            cout << endl    << "WydatkiId:          " << wydatki[www].pobierzFinanseId() << endl;
            cout            << "Data:               " << wydatki[www].pobierzDate() << endl;
            cout            << "Typ wydatku:        " << wydatki[www].pobierzTypFinansu() << endl;
            cout            << "Wartosc wydatku:    " << wydatki[www].pobierzWartosc() << endl;
            bilansWydatki = bilansWydatki + MetodyPomocnicze::konwersjaStringNaDouble(wydatki[www].pobierzWartosc());
        }
    }

    cout << endl    << "Przychody wynosza:  " << bilansPrzychody << endl;
    cout            << "Wydatki wynosza:    " << bilansWydatki << endl;
    cout            << "Twoj bilans to:     " << bilansPrzychody - bilansWydatki << endl;

    system("pause");
}
