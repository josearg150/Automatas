#ifndef BORRARDATOS_H
#define BORRARDATOS_H

#include <QDialog>

namespace Ui {
class borrarDatos;
}

class borrarDatos : public QDialog
{
    Q_OBJECT

public:
    explicit borrarDatos(QWidget *parent = nullptr);
    ~borrarDatos();

private:
    Ui::borrarDatos *ui;
};

#endif // BORRARDATOS_H
