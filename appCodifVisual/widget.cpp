#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

char descodificar(char *ascii,int *aleatorios){
    return (char)((int)*ascii-*aleatorios);
}
char codificar(char *letra, int *aleatorios){
    int valor_ascii;
    if(isdigit(*letra)){
        return *letra;
    }
    else{
        int ran;
        do{
            ran = rand()%58;
            valor_ascii = (int)*letra+ran;
            *aleatorios = ran;
        }while((valor_ascii > 90 && valor_ascii < 97) || valor_ascii < 65 || valor_ascii > 122);

        return (char)valor_ascii;
    }
}

void Widget::on_pushButton_clicked()
{
    QString texto = ui->lineEdit->text();
    int n = 0;
    char arreglo[n+1];
    int aleatorios[n+1];

    strcpy(arreglo,texto.toStdString().c_str());
    ui->lineEdit_2->setText(arreglo);

    for (int i = 0; i < n; i++) {
         arreglo[i] = codificar(&arreglo[i], &aleatorios[i]);
    }

    ui->lineEdit_2->setText(arreglo);
}
