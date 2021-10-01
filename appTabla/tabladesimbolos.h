#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include <iostream>
#include <string>
using namespace std;
#include <string.h>
#include <iomanip>

typedef int valorSimbolo;//Declarar tipos int

struct Simbolo{
    char *nombre;
    valorSimbolo valor;
    Simbolo *next;
};

class TablaDeSimbolos
{
private:
    Simbolo **tabla;
    int size;
    int Hash(char *);//metodo de dispersion
    string getnombre();
public:
    TablaDeSimbolos();
    TablaDeSimbolos(int);
    Simbolo *addSym(char *, valorSimbolo);
    Simbolo *findSym(char *);
    bool borrarSimbolo(char *);
    void imprimirTabla();
    bool setValue(char *nombre, valorSimbolo val);
    bool getValue(char *nombre, valorSimbolo *val);
};

#endif // TABLADESIMBOLOS_H
