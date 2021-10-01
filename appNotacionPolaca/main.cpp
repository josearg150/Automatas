#include <iostream>
#include "notacionpolaca.h"
#include <cstring>
using namespace std;

int main(){
    string expInfija = "(a+b)-c";

    cout << "Notacion polaca"<<endl;
    cout << "\n Expresion infija: "<<expInfija<<endl;

    NotacionPolaca *expresion = new NotacionPolaca();

    char *expPos = new char[expInfija.length()];
    strcpy(expPos, expresion->convertirPostFija(expInfija));
    cout<<endl<<"Expresion postfija: "<<expPos<<endl;
    return 0;
}
