#include "conversor.h"

Conversor::Conversor(QObject *parent): QObject(parent)
{

}

void Conversor::setDec(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok);
    if(ok){
        emit hexChanged(QString::number(num,16));
        emit binChanged(QString::number(num,2));
    }
    else{
        emit hexChanged("");
        emit binChanged("");
    }
}

void Conversor::setHexa(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok,16);
    if(ok){
        emit decChanged(QString::number(num));
        emit binChanged(QString::number(num,2));
    }
    else{
        emit decChanged("");
        emit binChanged("");
    }
}

void Conversor::setBin(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok,2);
    if(ok){
        emit decChanged(QString::number(num));
        emit hexChanged(QString::number(num,16));
    }
    else{
        emit decChanged("");
        emit hexChanged("");
    }

}
