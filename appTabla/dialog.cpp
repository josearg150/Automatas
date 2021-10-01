#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Ingresa los datos");
}

Dialog::~Dialog()
{
    delete ui;
}

string Dialog::nombre() const
{
    return ui->lineEdit->text().toStdString();
}

int Dialog::valor() const
{
    return ui->spinBox->value();
}

void Dialog::on_buttonBox_accepted()
{
   accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}
