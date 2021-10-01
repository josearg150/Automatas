#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
using namespace std;
class ordenamiento
{
public:
    ordenamiento();
    void insercion(int *a, int n);
    void insercionDesc(int *a, int n);
    void printArray(int *a, int n);
    void BurbujaAsc(int *vec, int cantidad);
    void BurbujaDsc(int *vec, int cantidad);
    void quicksortAsc(int *vec, int izq, int der);
    void quicksortDesc(int *vec, int izq, int der);
    int intercambios = 0;
    int comparaciones = 0;

private:

protected:
};
#endif // ORDENAMIENTO_H
