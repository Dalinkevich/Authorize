#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QtGui>
#include <QtWidgets>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    //Центрирование окна
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(this);
    QPoint center = rect.center();
    int x = center.x() - (width() / 2);
    int y = center.y() - (height() / 2);
    center.setX(x);
    center.setY(y);
    move(center);

}

Form::~Form()
{
    delete ui;
    
}

void Form::slotToTwoWindow(QString login)
{
    ui->resultLabel->setText("Пользователь-  " + login + "  Авторизовался");
    ui->time->setText("Первое окно было закрыто: " + QTime::currentTime().toString("hh:mm:ss"));

}


