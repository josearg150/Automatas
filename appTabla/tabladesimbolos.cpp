#include "tabladesimbolos.h"
TablaDeSimbolos::TablaDeSimbolos()
{
    int tam = 20;
    if(tam <= 0){
        size = 0;
        tabla = nullptr;
    }
    else if((tabla = new Simbolo*[size = tam]) != NULL )
        for (int i = 0; i < size; i++) {
            tabla[i] = NULL;
        }
    else
        size = 0;
}
TablaDeSimbolos::TablaDeSimbolos(int tam)
{
    if(tam <= 0){
        size = 0;
        tabla = nullptr;
    }
    else if((tabla = new Simbolo*[size = tam]) != NULL )
        for (int i = 0; i < size; i++) {
            tabla[i] = NULL;
        }
    else
        size = 0;
}
int TablaDeSimbolos::Hash(char *nombre)
{
    int slot = 0;
    while (*nombre)
        slot += *nombre++;
    return slot % size;
}
Simbolo *TablaDeSimbolos::addSym(char *nombre, valorSimbolo valor)
{
    Simbolo *sym;
    int slot = Hash(nombre);

    if((sym = new Simbolo) != nullptr && (sym->nombre = new char[strlen(nombre)+1]) != nullptr){
        cout<<sym<<endl;
        strcpy(sym->nombre,nombre);
        sym->valor = valor;
        sym->next = tabla[slot];
        tabla[slot] = sym;
    }
    else{
        delete sym;
        sym = 0;
    }
    return sym;
}

Simbolo *TablaDeSimbolos::findSym(char *nombre)
{
    int slot = Hash(nombre);
    Simbolo *sym = tabla[slot];
    for(; sym ;sym = sym->next)
        if(strcasecmp(sym->nombre, nombre) == 0)
            break;
    return sym;
}

bool TablaDeSimbolos::borrarSimbolo(char *nombre)
{
    int slot = Hash(nombre);
    Simbolo *sym = tabla[slot];
    string aux = sym->nombre;
    if(sym && strcmp(sym->nombre,nombre) == 0){
        tabla[slot] = sym->next;
        delete sym;
        return true;
    }
    for (sym = tabla[slot];sym->next;sym = sym->next)
        if(strcmp(sym->next->nombre, nombre)){
            Simbolo *tmp = sym->next;
            sym->next = sym->next->next;
            delete tmp;
            return true;
        }
    return false;
}

void TablaDeSimbolos::imprimirTabla()
{
    for (int i = 0; i < size; i++)
        for(Simbolo *sym = tabla[i]; sym ; sym = sym->next)
            cout<<sym<<setw(20)<<sym->nombre<<setw(10)<<sym->valor<<setw(15)<<"Next :"<<hex<<sym->next<<dec<<endl;
}



bool TablaDeSimbolos::setValue(char *nombre, valorSimbolo val)
{
    Simbolo *sym = findSym(nombre);
    if(sym == nullptr)
        return addSym(nombre, val) != nullptr;
    else
        sym->valor = val;
    return true;
}

bool TablaDeSimbolos::getValue(char *nombre, valorSimbolo *val)
{
    Simbolo *sym = findSym(nombre);
    if(sym != nullptr)
        *val = sym->valor;
    return sym != nullptr;
}
