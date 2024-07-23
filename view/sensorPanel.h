#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QIcon>
#include <QPushButton>
#include <QCoreApplication>

#include "sensorInfo.h"

#define IMG_HEIGHT 35
#define IMG_WIDTH 35
#define BTN_HEIGHT 20
#define BTN_WIDTH 20

class SensorPanel : public QWidget
{
    Q_OBJECT

public:
    explicit SensorPanel(QWidget* parent = nullptr);
    virtual ~SensorPanel() = default;

    virtual SensorInfo& getSensorInfo() const = 0;
    virtual void filterSensor(const QString& type) = 0;

    static QLayout* buttonsLayout(QPushButton* button1, QPushButton* button2, QPushButton* button3, QPushButton* button4);

signals:
    void remove();
    void modify();
    void build();

public slots:
    virtual void showInfo() = 0;
    
};

#endif