#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char texto[255], opcion;
        do{
            cout<<"Texto : "<<endl;
            //cin>>texto;  //CAPTURA HASTA EL PRIMER ESPACIO EN BLANCO
            cin.getline(texto,sizeof(texto));
            //INSTITUTO TECNOLOGICO DE LA LAGUNA, BLVD. REV. S/N Y CALZ. CUAUTEMOC #1300
            cout<<texto<<endl;
            char clave = 67;
            texto[0] &= clave;

            for(int i = 0; i < 4; i++){
                texto[i] &= clave;
            }
            cout<<endl<<"OTRO TEXTO (s/n) : ";
            cin>>opcion;
            //opcion = tolower(opcion);
            //( opcion == 's')
        }while(strchr("Ss",opcion));

        // caracteres ASCII
        //  A = 65
        //  Z = 90

        //  a = 97
        //  z = 122
}
