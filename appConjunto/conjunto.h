#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>
#include <iostream>
#include <time.h>
using namespace std;

const int MAX = 10;
enum Mensaje{overflow, ok, yaExiste};

class Conjunto
{
    int elementos[MAX];
    //int *elems
    int nelems = 0;
private:
    void borrar2(int posicion);
    void quickSort(int arr[],int low, int high);
    int busquedaBinaria(int elem);
public:
    Conjunto();
    //~Conjunto(){cout << "\nEntra destructor";}

    void vaciar(){ nelems = 0; }//metodo en linea
    //Tarea implementar propuesta para mañana
    Mensaje agregarElemento(int);
    bool pertenece(const int);// E o >
    void borrarElemento(int); // - o -=
    void mostrarElementos(string set);
    void copiar(Conjunto); // >
    bool esIgual(Conjunto); // ==
    void unionConjunto(Conjunto *a, Conjunto *b);
    void interseccion(Conjunto *a, Conjunto *b);
    void llenarConjunto();


    //Operadores

    Mensaje operator+(int);//Agregar elemento
    void operator-(int);//Borrar
    bool operator+=(int);//Pertenece
    void operator>(Conjunto);//copiar
    bool operator==(Conjunto);//Es igual
};

#endif // CONJUNTO_H
