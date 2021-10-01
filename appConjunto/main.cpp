#include <iostream>
#include <conjunto.h>

using namespace std;

int main()
{
    Conjunto c1;
    c1.agregarElemento(9);
    c1.agregarElemento(10);
    c1.agregarElemento(20);
    c1.agregarElemento(1);
    c1.agregarElemento(2);
    c1.agregarElemento(3);
    c1.agregarElemento(4);
    c1.agregarElemento(6);
    c1.agregarElemento(5);
    string nombreA = "A";
    c1.mostrarElementos(nombreA);

    cout << endl;

    Conjunto c2;
    c2.agregarElemento(1);
    c2.agregarElemento(2);
    c2.agregarElemento(3);
    c2.agregarElemento(4);
    c2.agregarElemento(5);
    string nombreB = "B";
    c2.mostrarElementos(nombreB);
    cout << endl;
    c1.mostrarElementos(nombreA);

    if(c1==c2)
        cout << "El conjunto: " << nombreA << " y " << nombreB
             << " son iguales" << endl;
    else
        cout << "El conjunto: " << nombreA << " y " << nombreB
             << " no son iguales" << endl;

    cout << endl;


    return 0;
}
