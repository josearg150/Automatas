#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "pila.h"
#include "notacionpolaca.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
     NotacionPolaca *expresion = new NotacionPolaca();
     QString expInfija;
};
#endif // WIDGET_H
