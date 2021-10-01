#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include <string.h>

//  Macros de c/c++
#define leerCai(i) cadena[i++]
#define retrocede i--



//Variables globales
int i, inicioToken, estadoInicial, estadoActual;
//Prototipos
void inicializaEstados()
{
    estadoInicial = estadoActual = 0;//inicio del diag. de transiciones
}
bool identificaSimboloIgual(char c){
    if (c == '=')
        return true;
    return false;    
}

bool esEntero(char c){
    if(((c - '0') % 2) == 0)
        return true;
    return false;
}
bool esReal(char c){
    if(((c - '0') % 2) != 0)
        return true;
    return false;
}
bool estadoDeAceptacion(){
    switch (estadoActual) {
        case 2:
        case 5:
        case 8:
    case 10:
        return true;
    default: return false;
    }
    return false;
}
bool esDelimitador(char c)
{
    if(c == ' ' || c == '\n' || c == '\t')
        return true;
    return false;
}
void fallo()
{
    switch(estadoInicial){
    case 0:{
            estadoInicial = 3;
            i = inicioToken;
        }break;
    case 3: estadoInicial = 6;
        i = inicioToken;
        break;
    }

    estadoActual = estadoInicial;
}
bool esLetra(char c)
{
    return isalpha(c);
}
bool esDigito(char c)
{
    return isdigit(c);
}

void scanner(char cadena[255])
{
    char caracter;
    inicializaEstados();
    //Variables globales
    i = inicioToken = 0;
    while(i< (int)strlen(cadena) || estadoDeAceptacion()){
        switch(estadoActual){
        case 0: caracter = leerCai(i);
            if(esDelimitador(caracter))
                estadoActual = 1;
            else
                fallo();
            break;
        case 1: caracter = leerCai(i);
            if(esDelimitador(caracter))
                estadoActual = 1;
            else
                estadoActual = 2;
            break;
        case 2: retrocede;
            cout <<"\nDelimitador";
            inicializaEstados();
            inicioToken = 1;
            break;

        case 3: caracter = leerCai(i);
            if(esLetra(caracter) || caracter)
                estadoActual = 4;
            else
                fallo();
            break;
        case 4: caracter = leerCai(i);
            if(esLetra(caracter) || esDigito(caracter) || caracter == '_')
                estadoActual = 4;
            else
                estadoActual = 5;
            break;
        case 5: retrocede;
            cout<<"\nIdentificador";
            inicializaEstados();
            inicioToken = i;
            break;
        }
    }

}//Scanner o lexico



int main()
{
    string cadena = " a   ";
    char cadenaC[255];
    char opcion;
    do{
       cout<<"Cadena a analizar: ";
       getline(cin,cadena,'\n');
       cadena+=";";
       strcpy(cadenaC,cadena.c_str());
       cout<<"\nCadena de entrada: "<<cadenaC<<endl;
       scanner(cadenaC);
       cout<<"\nAnalizar otra cadena (s/n): ";
       cin>>opcion;
       cin.get();
       fflush(stdin);
    }while(strchr("Ss",opcion));

    return 0;
}

