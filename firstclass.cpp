#include "firstclass.h"
#include <QDebug>


FirstClass::FirstClass()
{

}

void FirstClass::firstSlot(QString string)
{
    qDebug() << "Переданная строка в FirstClass " <<string << endl;

}


