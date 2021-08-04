#include <iostream>
#include "Markup.h"

using namespace std;

int main() {

    string UserID = "AA1234";
    string Name = "Sebastian";
    string Surname = "Dec";
    string Login = "S.Dec";
    string Password = "Admin1";

    CMarkup xml;

    //Je¿eli plik nie isteieje
    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();

    //Jezeli uzytkownik nie istenie (po numerze ID)
    if ((xml.FindElem(UserID)) == false) {
        xml.AddElem(UserID);

        xml.FindElem(UserID);
        xml.IntoElem();

        xml.AddElem("Name", Name);
        xml.AddElem("Surname", Surname);
        xml.AddElem("Login", Login);
        xml.AddElem("Password", Password);

    }
    else {
        xml.FindElem(UserID);
        xml.IntoElem();
    }
    xml.Save("users.xml");

    return 0;
}
