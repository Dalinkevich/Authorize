#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
    
}

void Form::slotToTwoWindow(QString login)
{
    ui->resultLabel->setText("Пользователь-  " + login + "  Авторизовался");
    qDebug() << "второе окно дебаг " << login;

}


