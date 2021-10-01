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
    letraClave = ui->lineEdit->text();
    QChar letra = letraClave.at(0).toLatin1();
    QString texto = ui->plainTextEdit->toPlainText();
    QString codificado = letra & texto;
    ui->plainTextEdit_2->setPlainText(letra);

}
