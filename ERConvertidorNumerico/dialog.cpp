#include "dialog.h"
#include "ui_dialog.h"
#include "conversor.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog),conversor(new Conversor)
     //ui(new Ui::Dialog)
{
    //4294967295

    ui->setupUi(this);

    QIntValidator *decVal = new QIntValidator(0,(4294967295/2)-1,ui->decimalEdit);
    ui->decimalEdit->setValidator(decVal);

   /* QRegularExpressionValidator *decVal = new QRegularExpressionValidator(
                QRegularExpression("[0-9]{5}"),ui->binEdit);
    ui->decimalEdit->setValidator(decVal);*/

    QRegularExpressionValidator *hexVal = new QRegularExpressionValidator
                                               (QRegularExpression("[A-fa-f0-9]{1,8}"),ui->hexaEdit);
    ui->hexaEdit->setValidator(hexVal);

    QRegularExpressionValidator *binVal = new QRegularExpressionValidator(
                QRegularExpression("[0|1]{32}"),ui->binEdit);
    ui->binEdit->setValidator(binVal);

    connect(ui->decimalEdit,SIGNAL(textChanged(QString)), conversor, SLOT(setDec(QString)));
    connect(ui->hexaEdit,SIGNAL(textChanged(QString)), conversor, SLOT(setHexa(QString)));
    connect(ui->binEdit,SIGNAL(textChanged(QString)), conversor, SLOT(setBin(QString)));
    connect(conversor, SIGNAL(hexChanged(QString)), ui->hexaEdit,SLOT(setText(QString)));
    connect(conversor, SIGNAL(binChanged(QString)), ui->binEdit,SLOT(setText(QString)));
    connect(conversor, SIGNAL(decChanged(QString)), ui->decimalEdit,SLOT(setText(QString)));

}

Dialog::~Dialog()
{
    delete ui;
}

