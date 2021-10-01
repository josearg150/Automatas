#include <stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<time.h>
#include "ordenamiento.h"
using namespace std;

int QuickComp = 0;
int QuicInter = 0;

const int MAX = 10;

//void insercion(int arr[], int n)



//void printArray(int arr[], int n)

int main()
{
ordenamiento *ordenar = new ordenamiento();
ordenamiento ordenamiento;


//ASIGNAR 500 DATOS ALEATORIOS A arr
//MOSTRAR LA CANTIDAD DE INTERCAMBIOS Y MOVIMIENTOS
//COMPARAR ESTE RESULTADO CON LA BURBUJA Y EL QUICK
    int arr[MAX];//areglo de 500 numeros
    srand(time(NULL));//inicializar aleatorios
    for(int i = 0; i < MAX; i++)
        arr[i] = rand() % 900 + 100;

//	int n = sizeof(arr) / sizeof(arr[0]);

    cout<< "Datos desordenados \n";
    ordenamiento.printArray(arr, MAX);

    int opcion = 0;
    do{
        cout << "1)Insercion ascendente\n";
        cout << "2)Insercion descendente\n";
        cout << "3)Burbuja ascendente\n";
        cout << "4)Burbuja descendente\n";
        cout << "5)Quicksort ascendente\n";
        cout << "6)Quicksort descendente\n";
        cout << "Ingresa el numero de ordenamiento :";
        cin >> opcion;
    }while(opcion < 1 || opcion > 6);

    switch (opcion){
       case 1: ordenamiento.insercion(arr, MAX);
                cout<< "Datos ordenados con Insercion \n";
                ordenamiento.printArray(arr, MAX);
                break;
       case 2: ordenamiento.insercionDesc(arr, MAX);
            cout<< "Datos ordenados con Insercion descendente \n";
            ordenamiento.printArray(arr, MAX);
            break;
       case 3: ordenamiento.BurbujaAsc(arr, MAX);
             cout<< "Datos ordenados con Burbuja \n";
             ordenamiento.printArray(arr, MAX);
             break;
       case 4: ordenamiento.BurbujaDsc(arr, MAX);
                cout<< "Datos ordenados con Burbuja \n";
                ordenamiento.printArray(arr, MAX);
                break;
       case 5: ordenamiento.quicksortAsc(arr, 0, MAX-1);
                cout << "INTERCAMBIOS Quicksort: " << ordenamiento.intercambios<<endl;
                cout << "Comparaciones quicksort: "<< ordenamiento.comparaciones << endl;
                cout << "Datos ordenados con quicksort"<<endl;
                ordenamiento.printArray(arr, MAX);
                break;
       case 6: ordenamiento.quicksortDesc(arr, 0, MAX-1);
               cout << "INTERCAMBIOS Quicksort: " << ordenamiento.intercambios<<endl;
               cout << "Comparaciones quicksort: "<< ordenamiento.comparaciones << endl;
               cout << "Datos ordenados con quicksort"<<endl;
               ordenamiento.printArray(arr, MAX);
               break;
    }
    return 0;
}
