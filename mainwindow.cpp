#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap> //отображение изображения


//при генерации сигналов firstSignal, secondSignal  в классе MainWindow, в классах FirstClass, SecondClass будут запускаться слоты firstSlot secondSlot

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/Resource/Images/Authorize.png"); // путь к изображению
    int w = ui->logo->width();
    int h = ui->logo->height();

    ui->logo->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio)); // помещаем изображение в logo + изображение растягивается при изменении размера

    //экземпляры классов
    firstClass = new FirstClass();
    secondClass = new SecondClass();
    form = new Form();



    //Новый метод connect
    connect(this, &MainWindow::firstSignal, firstClass, &FirstClass::firstSlot);
    connect(this, &MainWindow::secondSignal, secondClass, &SecondClass::secondSlot);
    connect(this, &MainWindow::signalToTwoWindow, form, &Form::slotToTwoWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// сигналы
void MainWindow::test()
{
    qDebug() << "Слот test запущен" << endl;
    emit firstSignal(ui->login->text());
    emit secondSignal(ui->password->text());

}

void MainWindow::showToWindow()
{
    emit signalToTwoWindow(ui->login->text());
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

        showToWindow();


   } else {
         ui->statusbar->showMessage("Авторизация не успешна");
   }
}
