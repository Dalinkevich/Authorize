#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MARK: QSettings
    QApplication::setOrganizationName("Admin");
    QApplication::setApplicationName("Authorize");

    MainWindow w;
    w.show();
    return a.exec();
}
