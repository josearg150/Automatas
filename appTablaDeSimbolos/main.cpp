/*#include <iostream>

using namespace std;

int main()
{
    int _ = 10;
    cout << "Valor de _: "<<_<<endl;
    _++;
    cout << "Valro de _: " <<_ << endl;
    return 0;
}*/
#include <iostream>

using namespace std;
#include "tabladesimbolos.h"


int main()
{
      //OBJETO ESTATICO
    //TablaDeSimbolos tabla(5);
       //OBJETO DINAMICO
       TablaDeSimbolos *tabla = new TablaDeSimbolos(5);

    char *cad1 = new char[128];
    //strcpy(cad1,string("Codificar").c_str());
    string cad1S = "val1";
    strcpy(cad1,cad1S.c_str());//c_str() => convierte a arreglo de char

    //ANALIZAR LAS DIRECCIONES PROPORCIONADAS POR EL COMPILADOR
    //UBICAR LOS ENLACES

    cout<<"AGREGANDO SIMBOLOS A LA TABLA (DIRECCIONES) "<<endl;
    tabla->addSym(cad1,5);

    tabla->addSym("val1_",1);
    tabla->addSym("num1",0);
    tabla->addSym("num2",10);
    tabla->addSym("val2",1);
    tabla->addSym("num11",2);
    tabla->addSym("num111",1);
    tabla->addSym("num",100);

    cout<<"\n\tTABLA DE SIMBOLOS"<<endl;
    tabla->imprimirTabla();


    cout<<"Valor de val1 : "<<tabla->findSym("val1")->valor<<endl;
    cout<<"Valor de num  : "<<tabla->findSym("num")->valor<<endl;

    cout<<"Eliminar: val1"<<endl;
    tabla->borrarSimbolo("val1");
    tabla->imprimirTabla();
    cout<<"Eliminar : num "<<endl;
    tabla->borrarSimbolo("num");

    tabla->imprimirTabla();

    return 0;
}

