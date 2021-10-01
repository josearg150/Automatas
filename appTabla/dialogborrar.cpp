#include "dialogborrar.h"
#include "ui_dialogborrar.h"

DialogBorrar::DialogBorrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBorrar)
{
    ui->setupUi(this);
}

DialogBorrar::~DialogBorrar()
{
    delete ui;
}
