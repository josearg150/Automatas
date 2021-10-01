#include <iostream>
#include "lexico.h"
using namespace std;

int main()
{
    lexico analizador;

    int menu;
    do{
    cout<<"Elija una opcion:\n1)Analizar cadenas\n2)Analizar archivo de texto\n3)Salir"<<endl;
    cout<<"Opcion: ";
    cin>>menu;
    }while(menu < 0 && menu > 4);
    cin.ignore();
    fflush(stdin);
    switch(menu){
        case 1: analizador.menuCadenas();break;
        case 2: analizador.menuArchivos();break;
    }
    return 0;
}
