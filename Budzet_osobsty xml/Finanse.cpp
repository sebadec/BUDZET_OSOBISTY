#include "Finanse.h"

int Finanse::pobierzFinanseId()
{
    return finanseId;
}

int Finanse::pobierzUzytkownikId()
{
    return uzytkownikId;
}

string Finanse::pobierzDate()
{
    return data;
}

string Finanse::pobierzWartosc()
{
    return wartosc;
}

string Finanse::pobierzTypFinansu()
{
    return typFinansu;
}

void Finanse::ustawFinanseId(int newFinanseId)
{
    finanseId = newFinanseId;
}

void Finanse::ustawUzytkownikId(int newUzytkownikId)
{
    uzytkownikId = newUzytkownikId;
}

void Finanse::ustawDate(string newDate)
{
    data = newDate;
}

void Finanse::ustawWartosc(string newWartosc)
{
    wartosc = newWartosc;
}

void Finanse::ustawTypFinansu(string newTypFinansu)
{
    typFinansu = newTypFinansu;
}
