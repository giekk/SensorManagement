#ifndef CTRL_H
#define CTRL_H

#include "dataManagement.h"
#include "mainwindow.h"

class MainWindow;

class Ctrl : public QObject
{
    Q_OBJECT

private:
    DataManagement* model;
    MainWindow* view;

public:
    Ctrl(DataManagement* model);
    void setView(MainWindow* view);
};

#endif