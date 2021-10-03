#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();


	 //static string doubleToString(double number);
	 //static double konwersjaStringNaDouble(string liczba);
	 //static bool isNumber(string number);
     //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);//
     //static string changeCommaToDot(string number);
	 //static string getFullDateAsStringWithDashes(int date);
	 //static int getFullDateFromString(string date);

};

#endif
