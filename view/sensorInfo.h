#ifndef SENSORINFO_H
#define SENSORINFO_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>

#include "../sensor.h"

class SensorInfo : public QWidget
{
    Q_OBJECT
private:
    Sensor& sensor;
    QLabel* name;
    QLabel* id;
    QLabel* type;
    QLabel* reliability;
    QLabel* minimum;
    QLabel* maximum;
    QLabel* average;
public:
    SensorInfo(Sensor& sensor, QWidget* parent = 0);
    ~SensorInfo();

    void show();

    void showInfoWidget();

    Sensor& getSensor() const;

    QLabel* getName() const;
    QLabel* getId() const;
    QLabel* getType() const;
    QLabel* getReliability() const;
    QLabel* getMinimum() const;
    QLabel* getMaximum() const;
    QLabel* getAverage() const;
    
    void updateSensorInfo(Sensor* sensor);
    
    void setName(const QString& name);
    void setId(const QString& id);
    void setType(const QString& type);
    void setReliability(const QString& reliability);
};

#endif