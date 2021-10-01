#include <iostream>
#include <time.h>
#include "ordenamiento.h"
using namespace std;
char nombre_archivo[10];
ordenamiento ordenamiento;

void menu(){
    cout << "Escribe un nombre y extension para el archivo: ";
    cin >> nombre_archivo;
    cout << "El nombre sera: "<<nombre_archivo<<endl;
}

void menuOrdenamiento(int *vec, int n){
    int opcion = 0;
    do{
        cout << "<<<<<<<<<<<<<<<<<<<<<Menu de ordenamiento>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
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
       case 1: ordenamiento.insercion(vec, n);
                cout<< "Datos ordenados con Insercion \n";
                ordenamiento.printArray(vec, n);
                break;
       case 2: ordenamiento.insercionDesc(vec, n);
            cout<< "Datos ordenados con Insercion descendente \n";
            ordenamiento.printArray(vec, n);
            break;
       case 3: ordenamiento.BurbujaAsc(vec, n);
             cout<< "Datos ordenados con Burbuja \n";
             ordenamiento.printArray(vec, n);
             break;
       case 4: ordenamiento.BurbujaDsc(vec, n);
                cout<< "Datos ordenados con Burbuja \n";
                ordenamiento.printArray(vec, n);
                break;
       case 5:  ordenamiento.interc = ordenamiento.comp = 0;
                ordenamiento.quicksortAsc(vec, 0, n-1);
                cout << "INTERCAMBIOS Quicksort: " << ordenamiento.interc<<endl;
                cout << "Comparaciones quicksort: "<< ordenamiento.comp << endl;
                cout << "Datos ordenados con quicksort"<<endl;
                ordenamiento.printArray(vec, n);
                break;
       case 6: ordenamiento.quicksortDesc(vec, 0, n-1);
               cout << "INTERCAMBIOS Quicksort: " << ordenamiento.interc<<endl;
               cout << "Comparaciones quicksort: "<< ordenamiento.comp<< endl;
               cout << "Datos ordenados con quicksort"<<endl;
               ordenamiento.printArray(vec, n);
               break;
    }
}

void escribirEnArchivo(char *narchivo,int n){
    printf("\nInsertando datos en archivo\n");
    FILE *parchivo;
    if((parchivo = fopen(narchivo,"ab")) == nullptr){
        printf("Error, no se puede crear el archivo");
        exit(0);
    }
    srand((unsigned int)time(NULL));
    for(int i= 0;i < n ;i++){
        int dato = rand()%900 + 100;
        fprintf(parchivo,"%d\n",dato);
        printf("%d\n",dato);
    }
    fclose(parchivo);
}

int *leerArchivo(char *narchivo){
    FILE *parchivo;
    if((parchivo = fopen(narchivo, "rb")) == NULL){
        cout << "Error, no se puede encontro el archivo"<<endl;
        exit(0);
    }
    cout << "Leyendo datos desde archivos"<<endl;

    int cant = 0 ;//para contar los datos que hay en el archivo

    int num;
    //Se debe realizar una lectura previa para detectar si no hay datos
    //Puede que solo contenga EOF
    fscanf(parchivo,"%d",&num);
    while(!feof(parchivo)){
        cant++;
        fscanf(parchivo,"%d",&num);
    }
    fclose(parchivo);

    //Probar el metodo rewind al inicio
    //Volvemos a abrir el archivo

    if((parchivo = fopen(narchivo, "rb")) == nullptr){
        cout << "Error, no  se encontro el archivo"<<endl;
        exit(0);
    }
    cout << "Guardando datos desde archivo en arreglo"<<endl;

    int *datos = new int [cant];
    int i= 0;
    fscanf(parchivo, "%d", &datos[i]);
    while(!feof(parchivo)){
        printf("%d\n",datos[i]);
        i++;
        fscanf(parchivo, "%d", &datos[i]);
    }
    fclose(parchivo);
    return datos;
}

void BurbujaDsc(int *vec, int cantidad)
        {
            int comp = 0;
            int interc = 0;
            for (int i = 0; i < cantidad-1; i++)
            {
                for (int j = cantidad - 1; i < j; j--)
                {
                    comp++;
                    if (vec[j - 1] < vec[j])
                    {
                        int aux = vec[j - 1];
                        vec[j - 1] = vec[j];
                        vec[j] = aux;
                        interc++;
                    }
                }
            }
            printf("\nNo. de Comparaciones: %d ",comp);
            printf("\nNo. de intercambios: %d ", interc);
            printf("\n");

        }

int main()
{
    menu();


    srand((unsigned int)time(NULL));
    //int n = rand()%5 + 5;
    int n = 500;
    //char narchivo[]= "numeros.jarg";
    escribirEnArchivo(nombre_archivo, n);
    int *vec = leerArchivo(nombre_archivo);
    cout << "Datos en el vector "<<endl;
    menuOrdenamiento(vec, n);
    /*cout << "Datos del vector ordenados "<<endl;
    for (int i = 0;i < n;i++) {
        cout << vec[i]<<endl;
    }*/

    return 0;
}


