#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QIcon>

class TopBar : public QWidget
{
    Q_OBJECT

public:
    explicit TopBar(QPushButton* button, QLabel* title, QPixmap button_icon);
};

#endif