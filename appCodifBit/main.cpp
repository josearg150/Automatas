#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char letraClave;
    string texto;
    cout << "Ingresa el texto a codificar: "<<endl;
    getline(cin, texto);

    cout << "Ingresa la letra clave: ";
    cin >> letraClave;


    int n = texto.length();
    char arreglo[n+1];

    strcpy(arreglo, texto.c_str());

    for (int i = 0; i < n; i++) {
        arreglo[i] = (char)((int)letraClave & (int)arreglo[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arreglo[i];
    }

    for (int i = 0; i < n; i++) {
        arreglo[i] = (char)((int)letraClave << (int)arreglo[i]);
    }

    cout <<endl;
    cout << "Descodificado"<<endl;


    for (int i = 0; i < n; i++) {
        cout << arreglo[i];
    }

    cout <<endl;
    return 0;
}
