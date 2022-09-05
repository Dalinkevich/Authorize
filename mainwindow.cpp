#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <QtGui>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    //Лого
    QPixmap pix(":/Resource/Images/Authorize.png");
    int w = ui->logo->width();
    int h = ui->logo->height();

    ui->logo->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); // помещаем изображение в logo + изображение растягивается при изменении размера

    //Экземпляры классов
    firstClass = new FirstClass();
    secondClass = new SecondClass();
    form = new Form();
    timer = new QTimer();

    //Settings
    settings = new QSettings(this);
    loadSettings();

    connect(this, &MainWindow::firstSignal, firstClass, &FirstClass::firstSlot);
    connect(this, &MainWindow::secondSignal, secondClass, &SecondClass::secondSlot);
    connect(this, &MainWindow::signalToTwoWindow, form, &Form::slotToTwoWindow);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    timer->start(1000);

}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}


//MARK: QSettings
void MainWindow::saveSettings()
{
    settings->beginGroup("Closing_APP");
    settings->setValue("Application_closing_time", QTime::currentTime().toString("hh:mm:ss"));
    settings->endGroup();
}

void MainWindow::loadSettings()
{
   qDebug() << settings->fileName() << endl;
   settings->beginGroup("Launching_APP");
   settings->setValue("Application_launching_time", QTime::currentTime().toString("hh:mm:ss"));
   settings->endGroup();
}



void MainWindow::test()
{
    emit firstSignal(ui->login->text());
    emit secondSignal(ui->password->text());

}


void MainWindow::showToWindow()
{
    emit signalToTwoWindow(ui->login->text());
}


//Таймер
void MainWindow::slotTimerAlarm()
{
     QTime::currentTime().toString("hh:mm:ss");
}



void MainWindow::on_pushButton_clicked()
{
    test();

    QString login = ui->login->text();
    QString password = ui->password->text();

    if(login == "123456" && password == "qwerty") {
        ui->statusbar->showMessage("Вы успешно авторизовались");

        form->show();
        this->close();

        timer->stop();
        showToWindow();


   } else {
         ui->statusbar->showMessage("Авторизация не успешна");
   }

}



