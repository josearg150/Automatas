#include <iostream>
#include <cstring>

using namespace std;

void BurbujaDsc(char vec[10][10], int cantidad)
{

            int comp = 0;
            int interc = 0;
            for (int i = 0; i < cantidad-1; i++)
            {
                //for (int j = cantidad - 1; i < j; j--)
                for (int j = cantidad - 1; i < j; j--)
                {
                    comp++;
                    int valor = strcmp(vec[j-1],vec[j]);
                    //if (vec[j - 1] < vec[j])
                    if(valor < 0 )
                    {
                        char *aux = new char[10]; //= vec[j - 1];
                        strcpy(aux, vec[j-1]);
                        //vec[j - 1] = vec[j];
                        strcpy(vec[j-1],vec[j]);
                        //vec[j] = aux;
                        strcpy(vec[j],aux);
                        interc++;
                    }
                }
            }
            printf("\nNo. de Comparaciones: %d ",comp);
            printf("\nNo. de intercambios: %d ", interc);
            printf("\n");
 }

bool buscar(char nom[10], char vec[10][10],int *posicion){
    for (int i = 0; i < 10; i++) {
       if(strcmp(nom,vec[i]) == 0){
          *posicion = i;
          return true;
       }
    }
    return false;
}

int main()
{
    char nombres[10][10] ={"luis","juan", "jose", "maria", "sara","ivan", "jesus", "daniel","misael","manuel"};
    for (int i=0; i < 10;i++) {
        cout <<nombres[i]<<endl;
    }

    BurbujaDsc(nombres,10);
    cout << "Nombres ordenados por burbuja"<<endl;
    for (int i=0; i < 10;i++) {
        cout <<i+1<<".-"<<nombres[i]<<endl;
    }
    cout << "introduce un nombre a buscar: ";
    char name[10];
    cin >> name;
    //cin.getline(name,10,'\n');
    int posicion;
    cout << hex << &posicion <<dec <<endl;
    bool encontrado = buscar(name,nombres,&posicion);
    if(encontrado)
        cout << "El nombre fue encontrado en la posicion "<< posicion+1 <<endl;
    else
        cout << "El nombre no existe"<<endl;
    return 0;
}


//Ordenar nombres utilizando el metodo burbuja
//Tarea realizar cambios necesarios


