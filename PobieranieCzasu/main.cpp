#include <iostream>
#include <windows.h>
#include <winbase.h>

#include <ctime>
#include <cstdio>

using namespace std;
int main()
{

    ////////////////// win //////////////////
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout << "Biezacy rok to " << st.wYear<< endl;
    cout << "Biezacy miesiac to " << st.wMonth<< endl;
    cout << "Biezacy dzien tygodnia to " << st.wDayOfWeek<< endl;
    cout << "Biezacy dzien  to " << st.wDay<< endl;
    cout << "Biezaca godzina  to " << st.wHour<< endl;
    cout << "Biezaca minuta  to " << st.wMinute<< endl;
    cout << "Biezaca sekunda  to " << st.wSecond<< endl;
    cout << "Biezaca milisekunda  to " << st.wMilliseconds<< endl;

    int rok = st.wYear;
    cout << "Biezacy rok to " << rok << endl;

    ////////////////// ctime //////////////////

    time_t czas;
    struct tm * aktualnyCzas;

    time( & czas );
    aktualnyCzas = localtime( & czas );

    cout << "Aktualny czas i data:" << endl;
    cout << asctime( aktualnyCzas );

    ////////////////// ctime 2 //////////////////

    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%Y-%m-%d", localtime(&t));
    cout << s << endl;

    return 0;
}
