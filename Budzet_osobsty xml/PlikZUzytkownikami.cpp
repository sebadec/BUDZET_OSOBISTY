#include "PlikZUzytkownikami.h"

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    CMarkup xml;

    if (xml.Load(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) == false)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzUzytkownikId()));
    xml.AddElem("Name", uzytkownik.pobierzImie());
    xml.AddElem("Surname", uzytkownik.pobierzNazwisko());
    xml.AddElem("Login", uzytkownik.pobierzLogin());
    xml.AddElem("Password", uzytkownik.pobierzHaslo());

    xml.Save(NAZWA_PLIKU_Z_UZYTKOWNIKAMI);
}

bool PlikZUzytkownikami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzUzytkownikId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzImie() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzNazwisko() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;

    CMarkup xml;

    if (xml.Load(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) == true)
    {
        xml.FindElem();
        xml.IntoElem();

        string id, login, password, name, surname;

        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("UserId");
            id = xml.GetData();
            uzytkownik.ustawUzytkownikId(MetodyPomocnicze::konwersjaStringNaInt(id));

            xml.FindElem("Login");
            login = xml.GetData();
            uzytkownik.ustawLogin(login);

            xml.FindElem("Password");
            password = xml.GetData();
            uzytkownik.ustawHaslo(password);

            xml.FindElem("Name");
            name = xml.GetData();
            uzytkownik.ustawImie(name);

            xml.FindElem("Surname");
            surname = xml.GetData();
            uzytkownik.ustawNazwisko(surname);

            uzytkownicy.push_back(uzytkownik);
            xml.RestorePos();
        }
    }
    else
        cout << "brak pliku" << endl;

    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawUzytkownikId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void PlikZUzytkownikami::zmianaHaslaWPlikuZUzytkownikami(int idZalogowanegoUzytkownika, string noweHaslo)
{
    CMarkup xml;

    if (xml.Load(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) == true)
    {
        xml.FindElem();
        xml.IntoElem();

        for(int i=0; i<idZalogowanegoUzytkownika; i++)
        {
            xml.FindElem();
        }
        xml.IntoElem();
        xml.FindElem("Password");
        xml.RemoveElem();
        xml.AddElem("Password", noweHaslo);
        xml.Save(NAZWA_PLIKU_Z_UZYTKOWNIKAMI);
    }
}
