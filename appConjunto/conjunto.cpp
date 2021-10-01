#include "conjunto.h"

Conjunto::Conjunto()
{

}

Mensaje Conjunto::agregarElemento(int elem)
{
    if (pertenece(elem))
        return yaExiste;
    if(nelems < MAX){
        elementos[nelems++] = elem;
        return ok;
    }
    return overflow;
}


bool Conjunto::pertenece(const int elem)
{
    for(int i=0; i<nelems; i++)
        if(elementos[i] ==  elem)
            return true;
    return false;
}

void Conjunto::borrarElemento(int elem)
{
    /*if(pertenece(elem)){
        for(int i=0; i<nelems; i++){
            if(elementos[i] == elem){
                for(int j=i+1; j<nelems; j++){
                    elementos[j-1] = elementos[j];
                }
                nelems--;
                break;
            }
        }
    }*/
    int pos = busquedaBinaria(elem);
    if( pos >= 0)
        borrar2(pos);
}

void Conjunto::mostrarElementos(string set)
{
    quickSort(elementos,0,nelems-1);
    cout << "Elementos en el conjunto " << set << endl;
    for(int i=0; i<nelems; i++)
        cout << elementos[i] <<", ";
    cout << endl;
}

void Conjunto::copiar(Conjunto conj)
{
    if(nelems == conj.nelems)
       for (int i = 0; i < nelems; i++)
           elementos[i] = conj.elementos[i];
}

bool Conjunto::esIgual(Conjunto conj)
{
    for(int i=0; i<nelems; i++)
        if(!pertenece(conj.elementos[i]))
            return false;
    return true;
}

void Conjunto::unionConjunto(Conjunto *a,Conjunto *b)
{
    for (int i=0 ;i < a->nelems;i++)
          this->agregarElemento(a->elementos[i]);
    for (int i=0 ;i < b->nelems;i++)
          this->agregarElemento(b->elementos[i]);

}

void Conjunto::interseccion(Conjunto *a, Conjunto *b)
{
    for (int i=0 ;i < b->nelems;i++) {
          if(a->pertenece(b->elementos[i])){
              this->agregarElemento(b->elementos[i]);
          }
    }
}

void Conjunto::llenarConjunto()
{
    srand(time(NULL));
    int num;
    for(int i = 0; i <= MAX; i++){
       num = 1 + rand()%10;
       agregarElemento(num);
    }
}

void Conjunto::borrar2(int posicion)
{
    if(posicion > 0){
        for (int i = posicion+1; i <= nelems; i++) {
            elementos[i-1] = elementos[i];
        }
        nelems--;
    }
}

void Conjunto::quickSort(int arr[],int low,int high)
{

    int i, j, x , aux;
    i = low;
    j = high;
    x = arr[ (low + high) /2 ];
        do{
            while( (arr[i] < x) && (j <= high) )
            {
                i++;
            }

            while( (x < arr[j]) && (j > low) )
            {
                j--;
            }

            if( i <= j )
            {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                i++;  j--;
            }

        }while( i <= j );

        if( low < j )
            quickSort( arr, low, j );
        if( i < high )
            quickSort( arr, i, high );
}

int Conjunto::busquedaBinaria(int elem)
{
    int i = 0, inf = 0, sup, mitad;
    bool existe = false;
    sup= nelems;

    while((inf <= sup)){
     mitad = (inf+sup)/2;
     if(elementos[mitad] == elem){
        existe = true;
        break;
     }
     if(elementos[mitad] > elem){
        sup = mitad;
        mitad = (inf+sup)/2;
     }
     if(elementos[mitad] < elem){
        inf = mitad;
        mitad = (inf+sup)/2;
     }

     i++;
    }
   if(existe)
   {
    //borrar2(mitad);
    return mitad;
   }
   else{
    return -1;
   }
}

bool Conjunto::operator ==(Conjunto conj){
    return esIgual(conj);
}
Mensaje Conjunto::operator +(int elem){
     agregarElemento(elem);
}

void Conjunto::operator -(int elem){
    borrarElemento(elem);
}

bool Conjunto::operator +=(int elem)
{
    return pertenece(elem);
}

void Conjunto::operator >(Conjunto conj)
{
    this->copiar(conj);
}

