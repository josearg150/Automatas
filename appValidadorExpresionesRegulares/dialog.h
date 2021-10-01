#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QRegularExpression>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    QString obtenerExpresion();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
