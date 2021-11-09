#include "PlikZPrzychodami.h"

vector <Przychody> PlikZPrzychodami::wczytajPrzychodyZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    vector <Przychody> przychody;
    Przychody przychod;

    string incomeId, userId, date, item, amount;

    CMarkup xml;

    if(xml.Load(pobierzNazwePliku()) == false)
    {
        cout << "Stworzono nowy plik " << pobierzNazwePliku() << endl;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    else if (xml.Load(pobierzNazwePliku()) == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("IncomeId");
            incomeId = xml.GetData();
            przychod.ustawFinanseId(MetodyPomocnicze::konwersjaStringNaInt(incomeId));
            idOstatniegoPrzychodu = MetodyPomocnicze::konwersjaStringNaInt(incomeId);

            xml.FindElem("UserId");
            userId = xml.GetData();
            if(idZalogowanegoUzytkownika == MetodyPomocnicze::konwersjaStringNaInt(userId))
            {
                przychod.ustawUzytkownikId(MetodyPomocnicze::konwersjaStringNaInt(userId));
            }
            else
            {
                xml.RestorePos();
                continue;
            }

            xml.FindElem("Date");
            date = xml.GetData();
            przychod.ustawDate(date);

            xml.FindElem("Item");
            item = xml.GetData();
            przychod.ustawTypFinansu(item);

            xml.FindElem("Amount");
            amount = xml.GetData();
            przychod.ustawWartosc(amount);

            przychody.push_back(przychod);
            xml.RestorePos();
        }
    }

    idOstatniegoPrzychodu++;
    return przychody;
}

Przychody PlikZPrzychodami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Przychody przychod;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                przychod.ustawFinanseId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                przychod.ustawUzytkownikId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                przychod.ustawDate(pojedynczaDanaAdresata.c_str());
                break;
            case 4:
                przychod.ustawWartosc(pojedynczaDanaAdresata);
                break;
            case 5:
                przychod.ustawTypFinansu(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return przychod;
}

bool PlikZPrzychodami::dopiszPrzychodyDoPliku(Przychody przychody)
{
    CMarkup xml;

    if(xml.Load(pobierzNazwePliku()) == false)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.Save(pobierzNazwePliku());
    }
    if(xml.Load(pobierzNazwePliku()) == true)
    {
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", MetodyPomocnicze::konwerjsaIntNaString(przychody.pobierzFinanseId()));
    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(przychody.pobierzUzytkownikId()));
    xml.AddElem("Date", przychody.pobierzDate());
    xml.AddElem("Item", przychody.pobierzTypFinansu());
    xml.AddElem("Amount", przychody.pobierzWartosc());

    xml.Save(pobierzNazwePliku());
    idOstatniegoPrzychodu++;
    }
    else
    {
        cout << "brak pliku" << endl;
    }
}

int PlikZPrzychodami::pobierzIdOstatniegoPrzychodu()
{
    return idOstatniegoPrzychodu;
}

string PlikZPrzychodami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
