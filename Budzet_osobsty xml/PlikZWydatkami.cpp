#include "PlikZWydatkami.h"

vector <Wydatki> PlikZWydatkami::wczytajWydatkiZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    vector <Wydatki> wydatki;
    Wydatki wydatek;

    string incomeId, userId, date, item, amount;

    CMarkup xml;

    if(xml.Load(pobierzNazwePliku()) == false)
    {
        cout << "Stworzono nowy plik " << pobierzNazwePliku() << endl;
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    else if (xml.Load(pobierzNazwePliku()) == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            incomeId = xml.GetData();
            wydatek.ustawFinanseId(MetodyPomocnicze::konwersjaStringNaInt(incomeId));
            idOstatniegoWydatku = MetodyPomocnicze::konwersjaStringNaInt(incomeId);

            xml.FindElem("UserId");
            userId = xml.GetData();
            if(idZalogowanegoUzytkownika == MetodyPomocnicze::konwersjaStringNaInt(userId))
            {
                wydatek.ustawUzytkownikId(MetodyPomocnicze::konwersjaStringNaInt(userId));
            }
            else
            {
                xml.RestorePos();
                continue;
            }

            xml.FindElem("Date");
            date = xml.GetData();
            wydatek.ustawDate(date);

            xml.FindElem("Item");
            item = xml.GetData();
            wydatek.ustawTypFinansu(item);

            xml.FindElem("Amount");
            amount = xml.GetData();
            wydatek.ustawWartosc(amount);

            wydatki.push_back(wydatek);
            xml.RestorePos();
        }
    }

    idOstatniegoWydatku++;
    return wydatki;
}

Wydatki PlikZWydatkami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Wydatki wydatek;
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
                wydatek.ustawFinanseId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                wydatek.ustawUzytkownikId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                wydatek.ustawDate(pojedynczaDanaAdresata.c_str());
                break;
            case 4:
                wydatek.ustawWartosc(pojedynczaDanaAdresata);
                break;
            case 5:
                wydatek.ustawTypFinansu(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return wydatek;
}

bool PlikZWydatkami::dopiszPrzychodyDoPliku(Wydatki wydatki)
{
    CMarkup xml;

    if(xml.Load(pobierzNazwePliku()) == false)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.Save(pobierzNazwePliku());
    }

    if(xml.Load(pobierzNazwePliku()) == true)
    {
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", MetodyPomocnicze::konwerjsaIntNaString(wydatki.pobierzFinanseId()));
    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(wydatki.pobierzUzytkownikId()));
    xml.AddElem("Date", wydatki.pobierzDate());
    xml.AddElem("Item", wydatki.pobierzTypFinansu());
    xml.AddElem("Amount", wydatki.pobierzWartosc());

    xml.Save(pobierzNazwePliku());
    idOstatniegoWydatku++;
    }
    else
    {
        cout << "brak pliku" << endl;
    }
}

int PlikZWydatkami::pobierzIdOstatniegoWydatku()
{
    return idOstatniegoWydatku;
}

string PlikZWydatkami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
