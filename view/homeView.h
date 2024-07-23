#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFont>
#include <QLabel>
#include <QPixmap>
#include <QCoreApplication>
#include <QMessageBox>
#include <QCloseEvent>

#define BUTTON_ICON_HEIGHT 150
#define BUTTON_ICON_WIDTH 150

class HomeView : public QWidget 
{
    Q_OBJECT
private:
    QVBoxLayout* main_layout;
    QPushButton* startSimulation;
    QPushButton* tutorial;
    QPushButton* editDB;

    static void setButtonIcon(const QPixmap& icon, QPushButton* button);
    static QLayout* setButtonLayout(QPushButton* button, QLabel* label);
    static void titleLayout(QLabel* title);
    static void buttonLabelLayout(QLabel* label1, QLabel* label2, QLabel* label3);

public:
    explicit HomeView(QWidget* parent = nullptr);
    ~HomeView();

signals:
    void toSimulationView();  //segnale per mostrare la schermata simulazione dell'applicazione
    void toTutorialView();    //segnale per mostrare la schermata tutorial dell'applicazione
    void toDBEditorView();      //segnale per mostrare la schermata modifica database dell'applicazione

public slots:
    void showSimulationView();
    void showTutorialView();
    void showDBEditorView();
    
};

#endif