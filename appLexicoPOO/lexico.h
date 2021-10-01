#ifndef LEXICO_H
#define LEXICO_H


class lexico
{
public:
    lexico();
    void menuCadenas();
    void menuArchivos();

private:
    int i, inicioToken, estadoInicial, estadoActual;
    void scanner(char cadena[255]); //   scanner  =  A. lexico
    void inicializaEstados();
    void fallo();
    bool esLetra(char c);
    bool esDigito(char c);
    bool esDelimitador(char c);
    bool estadoDeAceptacion();
    bool identificaSimboloIgual(char c);
    bool identificaSimboloAdmiracion(char c);
    bool mayorQue(char c);
    bool menorQue(char c);
    bool simboloMas(char c);
    bool simboloMenos(char c);
    bool simboloMulti(char c);
    bool simboloDiv(char c);
    bool esEntero(char c);
    bool esReal(char c);
};

#endif // LEXICO_H
