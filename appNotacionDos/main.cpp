#include <QApplication>
#include <iostream>
using namespace std;
#include "notacionpolaca.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //string expInfija = "(a+b)-c";
    //string expInfija = "a*(b+c)+d/e";
    string expInfija = "4+8*(7+3)/2";


    cout<<"\tNOTACION POLACA"<<endl;
    cout<<"\nEXPRESION INFIJA : "<<expInfija<<endl;

    NotacionPolaca *expresion = new NotacionPolaca();

    char *expPos = new char[expInfija.length()];
    if(expresion->revisarParentesis(expInfija)){
        strcpy(expPos, expresion->convertirPostFija(expInfija));

        if(expresion->analizarExpresionDigitos(expInfija))
            cout<<endl<<"EXPRESION POSTFIJA : "<<expPos<<endl;
        else{
            cout << "Resultado: "<<expresion->resolverExpresion(expPos) <<endl;
}
    }
    else
        cout << "Error en la sintaxis, revisa los parentesis, corchetes y llaves"<<endl;



    return a.exec();



}
