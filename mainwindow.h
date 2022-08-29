#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//подгружаем нужные классы
#include <firstclass.h>
#include <secondclass.h>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots: // описание слотов

    void test();
    void showToWindow();

signals: // сигналы, которые  может испускать данный конкретный класс

    void firstSignal(QString string);
    void secondSignal(QString string);


    void signalToTwoWindow(QString string);


private slots:// описание слотов
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    // экзкмпляры классов
    FirstClass *firstClass {};
    SecondClass *secondClass {};

    Form *form;
};
#endif // MAINWINDOW_H
