#include "sensorPanel.h"

SensorPanel::SensorPanel(QWidget* parent) : QWidget(parent)
{
}

QLayout* SensorPanel::buttonsLayout(QPushButton* button1, QPushButton* button2, QPushButton* button3, QPushButton* button4)
{
    QLayout* buttonLayout = new QVBoxLayout();

    QPixmap button1_icon(QCoreApplication::applicationDirPath() + "/img/remove_icon.png");
    button1->setIcon(QIcon(button1_icon));
    button1->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button1->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button1->setStyleSheet("border: none; background-color: transparent;");
    button1->setCursor(Qt::PointingHandCursor);
    button1->setToolTip("Rimuovi");

    QPixmap button2_icon(QCoreApplication::applicationDirPath() + "/img/modify_icon.png");
    button2->setIcon(QIcon(button2_icon));
    button2->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button2->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button2->setStyleSheet("border: none; background-color: transparent;");
    button2->setCursor(Qt::PointingHandCursor);
    button2->setToolTip("Modifica");

    QPixmap button3_icon(QCoreApplication::applicationDirPath() + "/img/info_icon.png");
    button3->setIcon(QIcon(button3_icon));
    button3->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button3->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button3->setStyleSheet("border: none; background-color: transparent;");
    button3->setCursor(Qt::PointingHandCursor);
    button3->setToolTip("Dati Sensore");

    QPixmap button4_icon(QCoreApplication::applicationDirPath() + "/img/build_icon.png");
    button4->setIcon(QIcon(button4_icon));
    button4->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button4->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button4->setStyleSheet("border: none; background-color: transparent;");
    button4->setCursor(Qt::PointingHandCursor);
    button4->setToolTip("Setta");

    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);
    buttonLayout->addWidget(button4);
    
    return buttonLayout;
}

