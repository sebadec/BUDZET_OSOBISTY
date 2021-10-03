#include "Uzytkownik.h"

void Uzytkownik::ustawUzytkownikId (int noweUzytkownikId)
{
    if (noweUzytkownikId >= 0)
        uzytkownikId = noweUzytkownikId;
}
void Uzytkownik::ustawImie (string noweImie)
{
    imie = noweImie;
}
void Uzytkownik::ustawNazwisko (string noweNazwisko)
{
    nazwisko = noweNazwisko;
}
void Uzytkownik::ustawLogin (string nowyLogin)
{
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo (string noweHaslo)
{
    haslo = noweHaslo;
}

int Uzytkownik::pobierzUzytkownikId()
{
    return uzytkownikId;
}
string Uzytkownik::pobierzImie()
{
   return imie;
}
string Uzytkownik::pobierzNazwisko()
{
    return nazwisko;
}
string Uzytkownik::pobierzLogin()
{
    return login;
}
string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
