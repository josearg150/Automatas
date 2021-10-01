#ifndef DIALOGBORRAR_H
#define DIALOGBORRAR_H

#include <QDialog>

namespace Ui {
class DialogBorrar;
}

class DialogBorrar : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBorrar(QWidget *parent = nullptr);
    ~DialogBorrar();

private:
    Ui::DialogBorrar *ui;
};

#endif // DIALOGBORRAR_H
