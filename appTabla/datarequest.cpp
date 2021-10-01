#include "datarequest.h"
#include "ui_datarequest.h"

dataRequest::dataRequest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataRequest)
{
    ui->setupUi(this);
    setWindowTitle("Ingresa los datos");
}

dataRequest::~dataRequest()
{
    delete ui;
}
