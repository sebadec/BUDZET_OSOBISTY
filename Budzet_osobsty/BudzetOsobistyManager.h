#ifndef BUDZETOSOBISTYMANAGER_H
#define BUDZETOSOBISTYMANAGER_H

#include <iostream>

#include "UzytkonikMenager.h"
#include "FinanseMenager.h"

using namespace std;

class BudzetOsobistyManager
{
	//UserManager userManager;
	UzytkonikMenager uzytkownikMenager;
	//IncomesAndExpansesManager *incomesAndExpansesManager;
	FinanseMenager *finanseMenager;

	const string NAZWA_PLIKU_Z_PRZYCHODAMI;
	const string NAZWA_PLIKU_Z_WYDATKAMI;

public:
    BudzetOsobistyManager(string nazwaPlikuZUzytkownikami, string test)
    : uzytkownikMenager(nazwaPlikuZUzytkownikami)
    {
    finanseMenager = NULL;
    };
    ~BudzetOsobistyManager()
    {
      delete finanseMenager;
      finanseMenager = NULL;
    };

	void rejestracjaUzytkownika();
	void wypiszWszytkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogujUzytkownika();

	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	void wyszukajPoImieniu();
	void wyszukajPoNazwisku();
	void usunAdresata();

	void wypiszWszystkichUzytkownikow();
	void wylogowanieUzytkownika();

	void wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA();

	bool czyUzytkownikJestZalogowany();
	void wyswietlWszytskichAdresatow();

};

#endif
