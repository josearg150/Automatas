#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//Archivos de texto en C
int main()
{
    /*
    FILE *archivo;
    archivo = fopen("C:\\Users\\JOSE ANGEL\\Desktop\\appPrueba.txt","r+t");
    int limite = 0;
    while(!feof(archivo))
        limite++;
    for (int i= 0; i < limite;i++) {
        printf("%c",fgetc(archivo));
    }
    char cad[100];
    while(fgets(cad,100,archivo))
        printf("%s",cad);
    printf("Limite %d",limite);
    fclose(archivo);*/

    FILE *parch;
    string archivo, path;
    char archivoPath[255];

    cout<<"Archivo: ";
    getline(cin,archivo,'\n');
    path = "C:\\Users\\JOSE ANGEL\\Desktop\\";
    path+=archivo;

   // strcpy(archivoPath,path.c_str());
   // strcpy(archivoPath,path.c_str(), 255);

    memcpy(archivoPath, path.c_str(),255);
    char cadena[200];
    if((parch = fopen(archivoPath,"r")) != nullptr){
        while(!feof(parch)){
            fgets(cadena,200,parch);
            cout<<cadena;
        }
    fclose(parch);
    }
   else{
        cout<<"Error";
        exit(0);
    }
    cout<<endl;
    return 0;
}
