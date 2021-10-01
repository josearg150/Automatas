#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Contraseña segura");
    ui->comboBox->addItem("Hexadecimal");
    ui->comboBox->addItem("Direccion IPv4");
    ui->comboBox->addItem("Nombre de dominio");
    ui->comboBox->addItem("Fecha dd/mm/YY");
    ui->comboBox->addItem("Codigo postal USA");
    ui->comboBox->addItem("Tarjeta de credito");
    ui->comboBox->addItem("Precio $");
    ui->comboBox->addItem("Separador de miles");
    ui->comboBox->addItem("URL facebook");
    ui->comboBox->addItem("correo@correo.com");
    ui->comboBox->addItem("correo institucional");
    ui->comboBox->addItem("Terminacion aba");


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //QString patron = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString patron = obtenerExpresion();
    QRegularExpression regexp(patron);
    QString entrada = ui->lineEdit->text();
    QRegularExpressionMatch match = regexp.match(entrada);
    bool coincide = match.hasMatch();

    if(coincide){
        ui->label_2->setText("Expresion valida");
    }else
        ui->label_2->setText("Expresion no valida");

}

QString Dialog::obtenerExpresion()
{
  int index = ui->comboBox->currentIndex();
  switch(index){
      case 0: return "^(?=.*[A-Z].*[A-Z])(?=.*[!@#$&*])(?=.*[0-9].*[0-9])(?=.*[a-z].*[a-z].*[a-z]).{8}$";
      case 1: return "#([a-fA-F]|[0-9]){3,6}";
      case 2: return "/b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)b/";
      case 3: return "/https?://(?:[-w]+.)?([-w]+).w+(?:.w+)?/?.*/i";
      case 4: return "^(?:(?:31(/|-|.)(?:0?[13578]|1[02]))1|(?:(?:29|30)(/|-|.)(?:0?[1,3-9]|1[0-2])2))(?:(?:1[6-9]|[2-9]d)?d{2})$|^(?:29(/|-|.)0?23(?:(?:(?:1[6-9]|[2-9]d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1d|2[0-8])(/|-|.)(?:(?:0?[1-9])|(?:1[0-2]))4(?:(?:1[6-9]|[2-9]d)?d{2})$";
      case 5: return "^d{5}(?:[-s]d{4})?$";
      case 6: return "^(?:4[0-9]{12}(?:[0-9]{3})?|5[1-5][0-9]{14}|6(?:011|5[0-9][0-9])[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|(?:2131|1800|35d{3})d{11})$";
      case 7: return "\\$[0-9]+(.[0-9]{2})?";
      case 8: return "\\d{1,3}(?=(d{3})+(?!d))/g";
      case 9: return "/(?:http://)?(?:www.)?facebook.com/(?:(?:w)*#!/)?(?:pages/)?(?:[w-]*/)*([w-]*)/";
      case 10: return "^[A-Z0-9a-z.]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}$";
      case 11: return "^[\\w-]+(\\.[\\w-]+)@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)(\\.[A-Za-z]{2,})$";
      case 12: return "[a|b]*(aba)+$";
  }
}
