#include "secondclass.h"
#include <QDebug>


SecondClass::SecondClass()
{


}

void SecondClass::secondSlot(QString string)
{
    qDebug() << "Переданная строка в SecondClass " <<string << endl;
}
