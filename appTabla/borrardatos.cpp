#include "borrardatos.h"
#include "ui_borrardatos.h"

borrarDatos::borrarDatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::borrarDatos)
{
    ui->setupUi(this);
}

borrarDatos::~borrarDatos()
{
    delete ui;
}
