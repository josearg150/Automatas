#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <QObject>

class Conversor : public QObject
{
    Q_OBJECT
public:
    explicit Conversor(QObject *parent = nullptr);

signals:
    void decChanged(const QString &);
    void hexChanged(const QString &);
    void binChanged(const QString &);

public slots:
    void setDec(const QString &);
    void setHexa(const QString &);
    void setBin(const QString &);
};

#endif // CONVERSOR_H
