#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include <QObject>

class FirstClass: public QObject
{
    Q_OBJECT

signals:

public slots:

    void firstSlot(QString string);

public:
    FirstClass();
};

#endif // FIRSTCLASS_H
