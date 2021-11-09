#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}


int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

double MetodyPomocnicze::konwersjaStringNaDouble(string liczba)
{
	double liczbaDouble;
	istringstream iss(liczba);
	iss >> liczbaDouble;

	return liczbaDouble;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

char MetodyPomocnicze::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char MetodyPomocnicze::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmiana hasla uzytkowniaka" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char MetodyPomocnicze::wybierzOpcjeZMenuFinansu()
{
    char wybor;

    system("cls");
    cout << " >>> PODAJ DATE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dziesiejsza data" << endl;
    cout << "2. Okresl date" << endl;
    cout << "3. Zmieniam zdanie - wylogowanie z programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string MetodyPomocnicze::ustawienieDaty()
{
    string data;
    bool czyWpisanaDataJestPoprawna = false;
    char wybor;
    while (czyWpisanaDataJestPoprawna == false)
    {
        wybor = wybierzOpcjeZMenuFinansu();

        switch (wybor)
        {
        case '1':
            data = dzisiejszaData();
            czyWpisanaDataJestPoprawna = true;
            break;

        case '2':
            data = podanaData();
            czyWpisanaDataJestPoprawna = true;
            break;
        case '3':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }

    return data;
}

string MetodyPomocnicze::dzisiejszaData()
{
    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%Y-%m-%d", localtime(&t));
    string dzisiejszaData;
    dzisiejszaData = s;
    return dzisiejszaData;
}

string MetodyPomocnicze::podanaData()
{
    while (true)
    {
    string data;
    cin.sync();
    cout << endl << "Wpisz date w systemie rrrr-mm-dd:" << endl << endl;
    cin >> data;
    string rok, miesiac, dzien, myslnik_1, myslnik_2;
    int rokInt, miesiacInt, dzienInt;
    rok.insert(0,data,0,4);
    myslnik_1.insert(0,data,4,1);
    miesiac.insert(0,data,5,2);
    myslnik_2.insert(0,data,7,1);
    dzien.insert(0,data,8,2);
    cin.sync();

    rokInt = konwersjaStringNaInt(rok);
    miesiacInt = konwersjaStringNaInt(miesiac);
    dzienInt = konwersjaStringNaInt(dzien);

    if ((myslnik_2 == "-")&&(myslnik_1 == "-")&&(sprawdzanieCzyDataJestPrawidlowa(dzienInt, miesiacInt, rokInt) == true)&&(data.size() == 10))
    {
        cout << "Wartosc prawidlowa." << endl;
        system("pause");
        return data;
    }
    else
    {
        cout << "Podana data jest bledna!!!" << endl;
    }
    }
}

bool MetodyPomocnicze::sprawdzanieCzyDataJestPrawidlowa(int dzien, int miesiac, int rok)
{
    if(2000 <= rok <= 9999)
    {
        if((miesiac==1 || miesiac==3 || miesiac==5|| miesiac==7|| miesiac==8||miesiac==10||miesiac==12) && dzien>0 && dzien<=31)
            return true;
        else if(miesiac==4 || miesiac==6 || miesiac==9|| miesiac==11 && dzien>0 && dzien<=30)
            return true;
        else if(miesiac==2)
        {
            if((rok%400==0 || (rok%100!=0 && rok%4==0)) && dzien>0 && dzien<=29)
                return true;
            else if(dzien>0 && dzien<=28)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacInt(string RokMiesiacDzienString)
{
    string Rok, Miesiac, RokMiesiac;
    int RokMiesiacInt;

    Rok = RokMiesiacDzienString.substr(0,4);
    Miesiac = RokMiesiacDzienString.substr(5,2);
    RokMiesiac = Rok + Miesiac;

    RokMiesiacInt = konwersjaStringNaInt(RokMiesiac);

    return RokMiesiacInt;
}

int MetodyPomocnicze::konwersjaRokMiesiacDzienStringNaRokMiesiacDzienInt(string RokMiesiacDzienString)
{
    string Rok, Miesiac, Dzien, RokMiesiacDzien;
    int RokMiesiacDzienInt;

    Rok = RokMiesiacDzienString.substr(0,4);
    Miesiac = RokMiesiacDzienString.substr(5,2);
    Miesiac = RokMiesiacDzienString.substr(8,2);
    RokMiesiacDzien = Rok + Miesiac + Dzien;

    RokMiesiacDzienInt = konwersjaStringNaInt(RokMiesiacDzien);

    return RokMiesiacDzienInt;
}

string MetodyPomocnicze::konwersjaPrzecinekNaKropki(string tekstZPrzecinkiem)
{
    for(int i =0; i<tekstZPrzecinkiem.length();i++)
    {
        if(tekstZPrzecinkiem[i] == ',')
        {
            tekstZPrzecinkiem[i] = '.';
            break;
        }
    }
    return tekstZPrzecinkiem;
}
