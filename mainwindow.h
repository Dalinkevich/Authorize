#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <firstclass.h>
#include <secondclass.h>
#include <form.h>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveSettings();
    void loadSettings();

public slots:
    void test();
    void showToWindow();


signals:
    void firstSignal(QString string);
    void secondSignal(QString string);
    void signalToTwoWindow(QString string);


private slots:
    void on_pushButton_clicked();
    void slotTimerAlarm();


private:
    Ui::MainWindow *ui;

    // экзкмпляры классов
    FirstClass *firstClass {};
    SecondClass *secondClass {};
    QTimer *timer;
    Form *form;

    QSettings *settings;
};
#endif // MAINWINDOW_H
