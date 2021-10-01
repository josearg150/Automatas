#ifndef DATAREQUEST_H
#define DATAREQUEST_H

#include <QDialog>

namespace Ui {
class dataRequest;
}

class dataRequest : public QDialog
{
    Q_OBJECT

public:
    explicit dataRequest(QWidget *parent = nullptr);
    ~dataRequest();

private:
    Ui::dataRequest *ui;
};

#endif // DATAREQUEST_H
