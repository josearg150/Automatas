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
    int elem = ui->lineEdit->text().toInt();
    c1+elem;
    ui->pushButton_3->click();
}

void Widget::on_pushButton_3_clicked()
{
    ui->label_5->setText(c1.mostrarElementos());
    ui->label_7->setText(c2.mostrarElementos());
}

void Widget::on_pushButton_2_clicked()
{
    c2.agregarElemento(ui->lineEdit_2->text().toInt());
    ui->pushButton_3->click();
}

void Widget::on_pushButton_4_clicked()
{
    int elem = ui->lineEdit_3->text().toInt();
    if(ui->radioButton->isChecked())
        c1-elem;
    else if(ui->radioButton_2->isChecked())
        c2.borrarElemento(elem);
    ui->pushButton_3->click();
}

void Widget::on_pushButton_7_clicked()
{
    c1.llenarConjunto();
    ui->pushButton_3->click();
}

void Widget::on_pushButton_10_clicked()
{
    c2.llenarConjunto();
    ui->pushButton_3->click();
}

void Widget::on_pushButton_6_clicked()
{
    ui->label_9->setText("¿SON IGUALES?");
    if(c1==c2)
        ui->label_10->setText("Si son iguales los conjuntos 1 y 2");
    else
        ui->label_10->setText("No son iguales los conjuntos 1 y 2");
}

void Widget::on_pushButton_5_clicked()
{
    int elem = ui->lineEdit_3->text().toInt();
    int x = 0;
    if(ui->radioButton->isChecked())
        x = 1;
    else if (ui->radioButton_2->isChecked())
        x = 2;

    switch (x) {
     case 1: if(c1+=elem)
            ui->pushButton_5->setStyleSheet("QPushButton { background-color: green; }");
            else
             ui->pushButton_5->setStyleSheet("QPushButton { background-color: red; }");
        break;
    case 2: if(c2+=elem)
           ui->pushButton_5->setStyleSheet("QPushButton { background-color: green; }");
           else
            ui->pushButton_5->setStyleSheet("QPushButton { background-color: red; }");
       break;

    }
    /*if(ui->radioButton->isChecked() && (c1+=elem))
        ui->pushButton_5->setStyleSheet("QPushButton { background-color: green; }");
    else
       ui->pushButton_5->setStyleSheet("QPushButton { background-color: red; }");
    if(ui->radioButton_2->isChecked() && (c2+=elem))
        ui->pushButton_5->setStyleSheet("QPushButton { background-color: green; }");
    else
       ui->pushButton_5->setStyleSheet("QPushButton { background-color: red; }");
*/

}

void Widget::on_pushButton_9_clicked()
{
     Conjunto c3;
     ui->label_9->setText("CONJUNTO INTERSECCION");
     c3.interseccion(c1,c2);
     ui->label_10->setText(c3.mostrarElementos());

}

void Widget::on_pushButton_8_clicked()
{
    Conjunto c3;
    ui->label_9->setText("CONJUNTO UNION");
    c3.unionConjunto(c1,c2);
    ui->label_10->setText(c3.mostrarElementos());
}
