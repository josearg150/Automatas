#include "lexico.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
lexico::lexico()
{

}
#define leer_car(i) cadena[i++]    //MACROS
#define retrocedeCar i--


void lexico::menuCadenas(){
    cout<<"EDITOR (para terminar enter en linea nueva"<<endl;
    char _cadenas[21][255];
    string cadena;
    int ii;
    for(ii=0; ii<22; ii++){
        cout << ii+1 << " : ";
        getline(cin, cadena, '\n');
        strcpy(_cadenas[ii], cadena.c_str());
        if(strcmp(_cadenas[ii], "") == 0)
            break;
    }
    int indice=0;
    while(indice < ii){
        scanner(_cadenas[indice++]);
        cout << "\n------------------------------" << endl;
    }

}
void lexico::menuArchivos(){
    //FILE *parch;
    string archivo, path;
    char archivoPath[255];

    cout<<"Archivo: ";
    getline(cin,archivo,'\n');
    path = "C:\\Users\\JOSE ANGEL\\Desktop\\";
    path+=archivo;

    string cadena;
    ifstream datos(path);
    int i = 0;
    if(datos.fail())
        cout<<"Archivo no existe"<<endl;
    else
        while(!datos.eof()){
            getline(datos,cadena);
            strcpy(archivoPath,cadena.c_str());
            cout<<cadena<<endl;
            scanner(archivoPath);
            cout<<endl;
        }


}
void lexico::scanner(char cadena[255])
{
    char caracter;
    inicializaEstados();
    i = inicioToken = 0;
    while(i < (int)strlen(cadena) || estadoDeAceptacion())
    {
        switch (estadoActual) {
             //DELIMITADORES
        case 0: caracter = leer_car(i);
            if(esDelimitador(caracter))
                estadoActual = 1;
            else
                fallo(); //CAMBIAR DE ESTADO
            break;
        case 1: caracter = leer_car(i);
            if(esDelimitador(caracter))
                estadoActual=1;
            else   // OTRO caracter
                estadoActual = 2;
            break;
        case 2: retrocedeCar;  // i--
            cout<<"\n DELIMITADOR ";
            inicializaEstados();
            inicioToken = i;  //DONDE VA EL VALOR DE LA i se INICIA EL TOKEN
            break;
            //VARIABLES O IDENTIFICADORES
       case 3: caracter = leer_car(i);
                    if(esLetra(caracter) || caracter == '_')
                         estadoActual=4;
                    else
                       fallo();
            break;
        case 4: caracter = leer_car(i);
            if(esLetra(caracter) || esDigito(caracter) || caracter == '_')
                estadoActual=4;
            else
                estadoActual = 5;
            break;
        case 5: retrocedeCar;
            cout<<"\n IDENTIFICADOR ";
            inicializaEstados();
            inicioToken = i;
            break;

            //NUMEROS ENTEROS Y REALES
        case 6: caracter = leer_car(i);
            if(esDigito(caracter))
                estadoActual = 7;
            else
                fallo();
            break;
        case 7: caracter = leer_car(i);
            if(esDigito(caracter))
                estadoActual=7;
            else if(caracter == '.')
                estadoActual = 9;
            else
                estadoActual = 8;
            break;
        case 8: retrocedeCar;
            cout<<"\nNUMERO ENTERO";
            inicializaEstados();
            inicioToken = i;
            break;
        case 9: caracter = leer_car(i);
            if(esDigito(caracter))
                estadoActual=9;
            else
                estadoActual = 10;
            break;
        case 10: retrocedeCar;
            cout<<"\nNUMERO REAL";
            inicializaEstados();
            inicioToken = i;
            break;
        case 11: caracter = leer_car(i);
            if(identificaSimboloIgual(caracter))
                estadoActual = 12;
            else
                fallo();
            break;
        case 12: caracter = leer_car(i);
             if(identificaSimboloIgual(caracter))
                 estadoActual = 14;
             else
                 estadoActual = 13;
             break;
         case 13: retrocedeCar;
                 cout << "\n ASIGNACION";
                 inicializaEstados();
                 inicioToken = i;
              break;
         case 14: leer_car(i);
                 estadoActual = 15;
              break;
         case 15: retrocedeCar;
                 cout << "\n RELACIONAL";
                 inicializaEstados();
                 inicioToken = i;
              break;
         case 16: caracter = leer_car(i);
              if(identificaSimboloAdmiracion(caracter))
                  estadoActual = 17;
              else
                  fallo();
             break;
         case 17: caracter = leer_car(i);
               if(identificaSimboloIgual(caracter))
                   estadoActual = 19;
               else
                   estadoActual = 18;
              break;
          case 18: retrocedeCar;
                   cout << "\n LOGICO";
                   inicializaEstados();
                   inicioToken = i;
              break;
          case 19: leer_car(i);
                   estadoActual = 20;
              break;
          case 20: retrocedeCar;
                   cout << "\n RELACIONAL";
                   inicializaEstados();
                   inicioToken = i;
              break;
          case 21: caracter = leer_car(i);
              if(mayorQue(caracter))
                   estadoActual = 22;
              else
                   fallo();
              break;
          case 22: caracter = leer_car(i);
              if(identificaSimboloIgual(caracter))
                   estadoActual = 24;
              else
                   estadoActual = 23;
              break;
           case 23: retrocedeCar;
                   cout << "\n RELACIONAL";
                   inicializaEstados();
                   inicioToken = i;
              break;
           case 24: leer_car(i);
                   estadoActual = 25;
              break;
           case 25: retrocedeCar;
                   cout << "\n RELACIONAL";
                   inicializaEstados();
                   inicioToken = i;
              break;
           case 26: caracter = leer_car(i);
              if(menorQue(caracter))
                   estadoActual = 27;
              else
                   fallo();
              break;
           case 27: caracter = leer_car(i);
              if(identificaSimboloIgual(caracter))
                    estadoActual = 29;
              else
                    estadoActual = 28;
              break;
           case 28: retrocedeCar;
                   cout << "\n RELACIONAL";
                   inicializaEstados();
                   inicioToken = i;
              break;
           case 29: caracter = leer_car(i);
                   estadoActual = 30;
              break;
           case 30: retrocedeCar;
                   cout << "\n RELACIONAL";
                   inicializaEstados();
                   inicioToken = i;
              break;
           case 31: caracter = leer_car(i);
               if(simboloMas(caracter))
                   estadoActual = 32;
               else
                   fallo();
               break;
           case 32: caracter = leer_car(i);
                   estadoActual = 33;
               break;
           case 33: retrocedeCar;
                   cout << "\n ARITMETICO";
                   inicializaEstados();
                   inicioToken = i;
               break;
           case 34: caracter = leer_car(i);
                   if(caracter == '-')
                       estadoActual = 35;
                   else
                       fallo();
               break;
           case 35: caracter =leer_car(i);
                   estadoActual = 36;
               break;
           case 36: retrocedeCar;
                   cout << "\n ARITMETICO";
                   inicializaEstados();
                   inicioToken = i;
               break;
           case 37: caracter = leer_car(i);
                   if(simboloMulti(caracter))
                       estadoActual = 38;
                   else
                       fallo();
               break;
           case 38:caracter = leer_car(i);
                   estadoActual = 39;
               break;
           case 39: retrocedeCar;
                   cout << "\n ARITMETICO";
                   inicializaEstados();
                   inicioToken = i;
               break;
           case 40: caracter = leer_car(i);
                if(simboloDiv(caracter))
                   estadoActual = 41;
                else
                   fallo();
                break;
           case 41: caracter = leer_car(i);
                   estadoActual = 42;
                   break;
           case 42: retrocedeCar;
                   cout << "\n ARITMETICO";
                   inicializaEstados();
                   inicioToken = i;
                   break;
               default:
                   break;

           //AGREGAR LOS OPERADORES LOGICOS Y RELACIONALES



            //AGREAGAR LOS OPERADORES ARITMETICOS



            // ACTUALIZAR LOS METODOS:  fallo  y estadoDeAceptacion

        }
    }

}
void lexico::inicializaEstados()
{
    estadoInicial = estadoActual =0;

}
void lexico::fallo()
{
    switch (estadoInicial) {
    case 0:{
        estadoInicial = 3;
        i = inicioToken;
    }break;
    case 3:{
        estadoInicial = 6;
        i = inicioToken;
    }break;
    case 6:{
        estadoInicial = 11;
        i = inicioToken;
    }break;
    case 11:{
        estadoInicial = 16;
        i = inicioToken;
    }break;
    case 16:{
        estadoInicial = 21;
        i = inicioToken;
    }break;
    case 21:{
        estadoInicial = 26;
        i = inicioToken;
    }break;
    case 26:{
        estadoInicial = 31;
        i = inicioToken;
    }break;
    case 31:{
        estadoInicial = 34;
        i = inicioToken;
    }break;
    case 34:{
        estadoInicial = 37;
        i = inicioToken;
    }break;
    case 37:{
        estadoInicial = 40;
        i = inicioToken;
    }break;
    }
    estadoActual = estadoInicial;
}

bool lexico::esDelimitador(char c)
{
    if(c == ' ' || c == '\t' || c == '\n')
        return true;
    else
        return false;

}
bool lexico::lexico::estadoDeAceptacion()
{
    switch (estadoActual) {
      case 2:
      case 5:
      case 8:
      case 10:
      case 13:
      case 15:
      case 18:
      case 20:
      case 23:
      case 25:
      case 28:
      case 30:
      case 33:
      case 36:
      case 39:
      case 42:
          return true;
      default: return false;
      }
}
bool lexico::esLetra(char c)
{
    if((c>='A' && c <= 'Z') || ( c >= 'a' && c <= 'z' ))
          return true;
    else
        return false;
}
bool lexico::esDigito(char c)
{
    if( c >= '0' && c <= '9')
        return true;
    else
         return false;
}


bool lexico::identificaSimboloIgual(char c){
    if (c == '=')
        return true;
    return false;
}
bool lexico::identificaSimboloAdmiracion(char c){
    if (c == '!')
        return true;
    return false;
}
bool lexico::mayorQue(char c){
    if(c == '>')
        return true;
    return false;
}
bool lexico::menorQue(char c){
    if(c == '<')
        return true;
    return false;
}

bool lexico::simboloMas(char c){
    if(c == '+')
        return true;
    return false;
}
bool lexico::simboloMenos(char c){
    if(c == '-')
        return true;
    return false;
}
bool lexico::simboloMulti(char c){
    if(c=='*')
        return true;
    return false;
}
bool lexico::simboloDiv(char c){
    if(c=='/')
        return true;
    return false;
}

bool lexico::esEntero(char c){
    if(((c - '0') % 2) == 0)
        return true;
    return false;
}
bool lexico::esReal(char c){
    if(((c - '0') % 2) != 0)
        return true;
    return false;
}


