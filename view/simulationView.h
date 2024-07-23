#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QWidget>
#include <QObject>
#include <QFont>
#include <QCoreApplication>

#include "topbar.h"
#include "dataChartView.h"
#include "sensorColumnView.h"

class SimulationView : public QWidget
{
    Q_OBJECT

private:
    SensorColumnView* sensor_column = nullptr;
    DataChartView* data_chart = nullptr;
    QPushButton* home_button;

public:
    explicit SimulationView(QWidget* parent = nullptr);
    ~SimulationView();

signals:
    void toHomeView();

public slots:
    void showHomeView();
};

#endif