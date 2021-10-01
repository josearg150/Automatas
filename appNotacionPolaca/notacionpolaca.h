#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H
#include <string>
#include <string.h>
#include "pila.h"
#include "pila.cpp" //En el uso de plantillas o templates se requiere incluir el archivo.cpp

using namespace std;
//const int pot = 3;
//Investigar los tipos enumerado
enum Simbolo{OPERANDO, PIZQ, PDER, SUMRES, MULTDIV, POW};
class NotacionPolaca
{
public:
    NotacionPolaca();
    char *convertirPostFija(string expInfija);
    Simbolo tipo_y_predencia(char c);
};

#endif // NOTACIONPOLACA_H
