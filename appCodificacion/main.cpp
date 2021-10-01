#include <iostream>
#include <time.h>
#include <cstring>
using namespace std;


char codificar(char *letra, int *aleatorios){
    int valor_ascii;
    if(isdigit(*letra)){
        return *letra;
    }
    else{
        int ran;
        do{
            ran = rand()%58;
            valor_ascii = (int)*letra+ran;
            *aleatorios = ran;
        }while((valor_ascii > 90 && valor_ascii < 97) || valor_ascii < 65 || valor_ascii > 122);

        return (char)valor_ascii;

    }
}

char descodificar(char *ascii,int *aleatorios){
    if(isdigit(*ascii))
        return *ascii;
    else
        return (char)((int)*ascii-*aleatorios);
}

int main()
{

    string texto;
    cout << "Ingresa un texto:";
    getline(cin, texto);

    int n = texto.length();
    char arreglo[n+1];
    int aleatorios[n+1];

    strcpy(arreglo, texto.c_str());
    for (int i = 0; i < n; i++) {
        arreglo[i] = codificar(&arreglo[i], &aleatorios[i]);
    }

    cout <<"Texto codificado"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i];
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        arreglo [i]=descodificar(&arreglo[i],&aleatorios[i]);
    }
    cout<<"Texto descodificado"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i];
    }
    cout<<endl;


    return 0;
}

