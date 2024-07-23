#ifndef TUTORIALVIEW_H
#define TUTORIALVIEW_H

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QCoreApplication>
#include <QScrollArea>

#include "topbar.h"

class TutorialView : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* main_layout;
    QPushButton* home_button;

public:
    explicit TutorialView(QWidget* parent = nullptr);
    ~TutorialView();

    static void setDescription(QLabel* description);  //imposta il layout della descrizione

signals:
    void toHomeView();  //segnale per tornare alla home

public slots:
    void showHomeView();  //slot per mostrare la home
};

#endif