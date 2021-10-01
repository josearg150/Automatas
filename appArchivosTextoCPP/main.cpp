#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    FILE *parch;
    string archivo, path;
    char archivoPath[255];

    cout<<"Archivo: ";
    getline(cin,archivo,'\n');
    path = "C:\\Users\\JOSE ANGEL\\Desktop\\";
    path+=archivo;

    string cadena;
    ifstream datos(path);
    if(datos.fail())
        cout<<"Archivo no existe"<<endl;
    else
        while(!datos.eof()){
            getline(datos,cadena);
            cout<<cadena<<endl;
        }
    return 0;
}
