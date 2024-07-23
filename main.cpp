#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DataManagement model = DataManagement();
    Ctrl controller(&model);
    MainWindow* view = new MainWindow(&controller);
    view->show();
    return app.exec();
}
