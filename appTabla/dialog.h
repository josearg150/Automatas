#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
#include <string>
using namespace std;
#include <string.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    string nombre() const;
    int valor() const;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
