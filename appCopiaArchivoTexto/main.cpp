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
    if((pfile2 = fopen("//home/jose/Escritorio/archivo8.txt","wt"))== 0)  //NULL)
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
