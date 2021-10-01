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


void Widget::on_pushButton_clicked()
{
    QString msg1 = "EXPRESION POSTFIJA: ";
    QString msg2 = "EL RESULTADO DE LA EXPRESION ES: ";
    expInfija = ui->lineEdit->text();
    std::string exp = expInfija.toLocal8Bit().constData();
    char *expPos = new char[exp.length()];
    if(expresion->revisarParentesis(exp)){
        strcpy(expPos, expresion->convertirPostFija(exp));
        if(expresion->analizarExpresionDigitos(expPos)){//Si es verdadero, son solo letras
            ui->label_2->setText(msg1.append(expPos));
        }
        else{
            int resultado = expresion->resolverExpresion(expPos);
            ui->label_2->setText(msg2.append(QString::number(resultado)));
        }
    }
    else
        ui->label_2->setText("Error en la sintaxis, revisa los parentesis, corchetes y llaves");
}
