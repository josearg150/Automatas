#include "notacionpolaca.h"
#include <math.h>


NotacionPolaca::NotacionPolaca()
{

}

char *NotacionPolaca::convertirPostFija(string expInfija)
{
    //VALIDAR O ANALIZAR LA CADENA DE ENTRADA
    //EL ESPACIO REQUERIDO, LA EXP. POSFIJA NO REQUIERE DE PARENTESIS

    char *Epos = new char[expInfija.length()];

    // EL TAMAÑO DEBERA SER SOLO DEL NUMERO DE OPERADORES EN LA EXPRESIÓN
    // MAS LOS PARENTESIS IZQUIERDOS
    //VALIDAR O ANALIZAR LA ENTRADA PARA OBTENER DICHO VALOR
    //  A+B-(D-C)*X^Y
    Pila<int> *stack = new  Pila<int>(int(expInfija.length()));

    int i=0, pos = 0;
    for(   ; i < (expInfija.length()); i++)
    {
        char car = expInfija[unsigned(i)];
        Simbolo actual = tipo_Y_Precedencia(car);
        switch (actual) {
               case OPERANDO: Epos[pos++] = car;
                              break;
               case SUMRES : {
                             while(!stack->esta_vacia() && tipo_Y_Precedencia(char(stack->Tope())) >= actual)
                                  Epos[pos++] = char(stack->pop());
                             stack->push(car);
                             }
                             break;
               case MULTDIV : {
                      while(!stack->esta_vacia() && tipo_Y_Precedencia(char(stack->Tope())) >= actual)
                           Epos[pos++] = char(stack->pop());
                      stack->push(car);
                      }
                      break;
               case POW : {
                      while(!stack->esta_vacia() && tipo_Y_Precedencia(char(stack->Tope())) >= actual)
                           Epos[pos++] = char(stack->pop());
                      stack->push(car);
                      }
                      break;
               case PIZQ : stack->push(car);
                           break;
               case PDER :
                          {
                             char x = char(stack->pop());
                             while(tipo_Y_Precedencia(x) != PIZQ)
                             {
                                 Epos[pos++] = x;
                                 x = char(stack->pop());
                             }
                           }
                           break;

        }//fin del switch
    }//fin del for
    while(!stack->esta_vacia())
    {
        if(pos < int(expInfija.length()))
            Epos[pos++]= char(stack->pop());
        else
            break;
    }
    Epos[pos]='\0';
    return Epos;

}

bool NotacionPolaca::analizarExpresionDigitos(string expInfija)
{
    //Si es falso contiene digitos, si es verdadero solo contiene letras
    bool resultado = false;
    for (int i=0; i < (expInfija.length());i++) {
        if(isalpha(expInfija.at(i)))
            resultado = true;
    }
    return resultado;
}

int NotacionPolaca::operacion(int a, int b, char operacion)
{
    switch (operacion) {
        case '+': return a+b;break;
        case '-':return a-b;break;
        case '*':return a*b;break;
        case '/':return b/a;break;
        case '^':return pow(a,b);break;
    }
}

int NotacionPolaca::resolverExpresion(string expInfija)
{
    Pila<int> *proceso = new  Pila<int>(int(expInfija.length()));
    int auxIzq, auxDer;
    for(int i = 0; i < (int)expInfija.length(); i++){
        if(expInfija.at(i) == '+' || expInfija.at(i) == '-'  ||  expInfija.at(i) == '/'
           ||  expInfija.at(i) == '*'  || expInfija.at(i) == '^' ){
            auxIzq = char(proceso->pop());
            auxDer = char(proceso->pop());
            proceso->push(operacion(auxIzq, auxDer, expInfija.at(i)));
        }
        else{
            proceso->push(double(int(expInfija.at(i))-48));
        }
    }
    return proceso->Tope();
}
bool NotacionPolaca::revisarParentesis(string expInfija)
{
    bool resultado= false;
    int parentesisIZQ = 0, parentesisDER = 0, corcheteIZQ = 0, corcheteDER = 0, llaveIZQ = 0, llaveDER = 0;
    for(int i = 0; i < expInfija.length(); i++){
        switch (expInfija.at(i)) {
            case '(': parentesisIZQ++;break;
            case ')': parentesisDER++;break;
            case '[': corcheteIZQ++;break;
            case ']': corcheteDER++;break;
            case '{': llaveIZQ++;break;
            case '}': llaveDER++;break;
        }
    }
    if((parentesisDER == parentesisIZQ) && (corcheteDER == corcheteIZQ) && (llaveIZQ == llaveDER))
        resultado = true;

    return resultado;

}

Simbolo NotacionPolaca::tipo_Y_Precedencia(char c)
{
    Simbolo simbolo;
    switch(c)
    {
         case '+':
         case '-': simbolo = SUMRES;
                   break;
         case '*':
         case '/': simbolo = MULTDIV;
                   break;

         case '^' : simbolo = POW;
                   break;
         case '(' : simbolo = PIZQ;
                  break;
         case ')' : simbolo = PDER;
                  break;
         default : simbolo = OPERANDO;
                  break;
    }
    return simbolo;
}



//EVALUACIÓN
//diseñe e implemente una app que utilice un arreglo de char con su nombre
// extraiga las consonantes de su nombre y almacenales en otra cadena
//char nombre[100] = "MARTIN OSWALDO";
//char consonantes[100];
