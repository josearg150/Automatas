#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H

#include <string>
using namespace std;

#include <string.h>

#include "pila.h"
#include "pila.cpp"  //EN EL USO DE PLANTILLAS O TEMPLATES SE REQUIERE INCLUIR
                     // EL ARCHIVO .cpp

//const int Pot= 3;
//INVESTIGAR LOS TIPOS ENUMERADO

enum Simbolo{OPERANDO, PIZQ, PDER, SUMRES, MULTDIV, POW};

class NotacionPolaca
{

public:
    NotacionPolaca();
    char *convertirPostFija(string expInfija);
    bool analizarExpresionDigitos(string expInfija);
    int operacion(int a, int b, char operacion);
    int resolverExpresion(string expInfija);
    bool revisarParentesis(string expInfija);
    Simbolo tipo_Y_Precedencia(char c);
};

#endif // NOTACIONPOLACA_H
