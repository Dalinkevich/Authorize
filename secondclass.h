#ifndef SECONDCLASS_H
#define SECONDCLASS_H

#include <QObject>

class SecondClass: public QObject
{

    Q_OBJECT

signals:

public slots:

    void secondSlot(QString string);

public:
    SecondClass();
};

#endif // SECONDCLASS_H
