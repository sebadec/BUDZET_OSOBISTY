#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int uzytkownikId;
    string imie, nazwisko, login, haslo;

public:
    void ustawUzytkownikId (int noweUzytkownikId);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawLogin (string nowyLogin);
    void ustawHaslo (string noweHaslo);

    int pobierzUzytkownikId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
