#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QDialog>
#include <QInputDialog>
#include <QDir>
#include <QScreen>

#include "view/homeView.h"
#include "view/tutorialView.h"
#include "view/dbEditorView.h"
#include "view/simulationView.h"
#include "ctrl.h"

class Ctrl;
class HomeView;
class TutorialView;
class EditDBView;
class SimulationView;

class MainWindow : public QWidget 
{
    Q_OBJECT

private:
    Ctrl* ctrl;
    HomeView* home_view = nullptr;
    TutorialView* tutorial_view = nullptr;
    DBEditorView* dbEditor_view = nullptr;
    SimulationView* simulation_view = nullptr;

    QVBoxLayout* main_layout;
    
public:
    explicit MainWindow(Ctrl* _ctrl);
    ~MainWindow();
    
    void hideCurrentView();

public slots:
    void viewShowTutorialView();
    void viewShowHomeView();
    void viewShowSimulationView();
    void viewShowDBEditorView();
};

#endif