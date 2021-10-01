// ejemplo1.c: Muestra un fichero dos veces.
#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
    FILE *pfile;
    // SI FOPEN REGRESA NULL, NO ENCOTRO EL ARCHIVO
    pfile = fopen("/home/jose/Escritorio/archivo3.txt","r+t");      //"ejemplo1.c", "r");
    if(pfile == nullptr)   //0 )  //NULL)
    {
        cout<<"ERROR EL ARCHIVO NO EXISTE"<<endl;
        exit(0);
    }


    FILE *pfile2;
    if((pfile2 = fopen("/home/jose/Escritorio/archivo5.txt","wt"))== 0)  //NULL)
    {
        cout<<"ERROR EL ARCHIVO NO SE PUEDE CREAR"<<endl;
        exit(0);
    }
    while(!feof(pfile))
        fputc(fgetc(pfile),pfile2); //stdout);
    // REGRESA EL PUNTERO A FILE AL INICIO DEL ARCHIVO
    rewind(pfile);
    //HACE OTRA COPI
    while(!feof(pfile))
        fputc(fgetc(pfile), pfile2); //stdout);
    fclose(pfile);
    getchar();
    return 0;
}
/*
int main()
{
   FILE *pfile;
   //SI fopen regresa a null no encontro el archivo
   pfile = fopen("/home/jose/Escritorio/archivo3.txt", "r+t"); //"ejemplo1.c", "r");
   if(pfile == NULL){
       cout<< "Error el archivo no existe\n";
       exit(0);
   }
   FILE *pfile2;
   if((pfile2 = fopen("/home/jose/Escritorio/archivo4.txt","wt"))== NULL){
       cout<< "Error el archivo no se puede crear"<<endl;
       exit(0);
   }
   while(!feof(pfile))
       fputc(fgetc(pfile),pfile2); //stdout);
   //Regresa el puntero al inicio del archivo
   rewind(pfile);
   //hace otra copia
   while(!feof(pfile)) fputc(fgetc(pfile), stdout);
    fputc(fgetc(pfile),stdout);
   fclose(pfile);
   getchar();
   return 0;
}*/
