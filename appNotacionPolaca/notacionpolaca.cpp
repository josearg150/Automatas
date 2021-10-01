#include "notacionpolaca.h"

NotacionPolaca::NotacionPolaca()
{

}

char *NotacionPolaca::convertirPostFija(string expInfija)
{
    //Validar el espacio requerido, la exp posfija no requiere de parentesis

    char *Epos = new char[expInfija.length()];
    //EL tamaño debera ser solo del numero de operadores en la expresion
    //Mas los parentesis izquierdos
    //Validar o analizar la entrada para obtener dicho valor
    Pila<int> *stack = new Pila<int>(int(expInfija.length()));

    int i, pos=0;
    for ( i=0; i < int(expInfija.length()) ;i++) {
        char car = expInfija[unsigned(i)];
        Simbolo actual = tipo_y_predencia(car);
        switch (actual) {
            case OPERANDO: Epos[pos++] = car;break;
            case SUMRES :{ while(!stack->esta_vacia() && tipo_y_predencia(char(stack->Tope())) >= actual)
                           Epos[pos++] = char(stack->pop());
                           stack->push(car);}
                           break;
            case MULTDIV :{ while(!stack->esta_vacia() && tipo_y_predencia(char(stack->Tope())) >= actual)
                            Epos[pos++] = char(stack->pop());
                            stack->push(car);}
                            break;
            case POW :{ while(!stack->esta_vacia() && tipo_y_predencia(char(stack->Tope())) >= actual)
                            Epos[pos++] = char(stack->pop());
                            stack->push(car);}
                            break;
            case PIZQ: stack->push(car);
            case PDER: {char x = char(stack->pop());
                       while(tipo_y_predencia(x) != PIZQ){
                           Epos[pos++] = x;
                           x =  char(stack->pop());
                       }

                    }break;



        }

    }
    while(!stack->esta_vacia()){
        if(pos < int(expInfija.length()))
            Epos[pos++] = char(stack->pop());
        else
            break;
    }
    Epos[pos] = '\0';
            return Epos;
}

Simbolo NotacionPolaca::tipo_y_predencia(char c)
{
    Simbolo simbolo;
    switch (c) {
        case '+':
        case '-': simbolo = SUMRES;break;
        case '*':
        case '/': simbolo = MULTDIV;break;
        case '^': simbolo = POW;break;
        case '(': simbolo = PIZQ;break;
        case ')': simbolo = PDER;break;
        default: simbolo = OPERANDO;break;

    }
        return simbolo;
}
