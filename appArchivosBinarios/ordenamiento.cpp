#include "ordenamiento.h"

ordenamiento::ordenamiento()
{

}

void ordenamiento::insercion(int *a, int n)
{

    comp = interc = 0;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        comp++;
        while (j >= 0 && a[j] > key )
        {
            a[j + 1] = a[j];
            j = j - 1;
            interc ++;
        }
        a[j + 1] = key;
    }
    cout<< "\nNo. de Comparaciones: ";
    cout<< comp;
    cout<< "\nNo. de Intercambios: ";
    cout<< interc <<endl;
}
void ordenamiento::printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void ordenamiento::BurbujaAsc(int *vec, int cantidad)
{
    comp = 0;
    interc = 0;
    for (int i = 0; i < cantidad-1; i++)
    {
        for (int j = cantidad - 1; i < j; j--)
        {
            comp++;
            if (vec[j - 1] > vec[j])
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



void ordenamiento::BurbujaDsc(int *vec, int cantidad)
        {
            comp = 0;
            interc = 0;
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



void ordenamiento::quicksortAsc(int *vec, int izq, int der)
        {

            int i,j,pivote,aux;
            i = izq;
            j = der;
            pivote = vec[izq];

            do
            {
                comp++;
                while (vec[i] < pivote && i < der)
                {
                    i++;
                }
                comp++;
                while (vec[j] > pivote && j > izq)
                {
                    j--;
                }
                if(i <= j)
                {
                   aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    i++;
                    j--;
                    interc++;
                }
            }while(i <=j);
             if(izq < j)
                quicksortAsc(vec,izq,j);
            if(i < der)
                quicksortAsc(vec,i,der);
}

void ordenamiento::quicksortDesc(int *vec, int izq, int der)
{
    int i,j,pivote,aux;
    i = izq;
    j = der;
    pivote = vec[izq];

    do
    {
        comp++;
        while (vec[i] > pivote && i < der)
        {
            i++;
        }
        comp++;
        while (vec[j] < pivote && j > izq)
        {
            j--;
        }
        if(i <= j)
        {
           aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            i++;
            j--;
            interc++;
        }
    }while(i <=j);
     if(izq < j)
        quicksortAsc(vec,izq,j);
    if(i < der)
        quicksortAsc(vec,i,der);
}

void ordenamiento::insercionDesc(int *a, int n)
{
    comp = interc = 0;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        comp++;
        while (j >= 0 && a[j] < key )
        {
            a[j + 1] = a[j];
            j = j - 1;
            interc ++;
        }
        a[j + 1] = key;
    }
    cout<< "\nNo. de Comparaciones: ";
    cout<< comp;
    cout<< "\nNo. de Intercambios: ";
    cout<< interc <<endl;
}

