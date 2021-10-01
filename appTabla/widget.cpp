#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include "borrardatos.h"
#include <string>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList encabezados;
    encabezados<<"Nombre"<<"Valor";
    setWindowTitle("Tabla");
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0,200); ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setHorizontalHeaderLabels(encabezados);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    string nom;
    //TablaDeSimbolos tabla(50);
    int val;
    Dialog frame(this);
    int result = frame.exec();
    if(result == Dialog::Rejected)
        return;//No guardar nada
    nom = frame.nombre();
    val = frame.valor();
    char *cString = &nom[0];
    t->addSym(cString,val);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,
                             new QTableWidgetItem(t->findSym(cString)->nombre));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,
                             new QTableWidgetItem(QString::number(t->findSym(cString)->valor)));

    ui->tableWidget->update();
}

void Widget::on_pushButton_2_clicked()
{


}
