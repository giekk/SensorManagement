#ifndef TEMPERATUREPANEL_H
#define TEMPERATUREPANEL_H

#include "../temperature.h"
#include "sensorInfoDialog.h"
#include "sensorPanel.h"

class TemperaturePanel : public SensorPanel
{
    Q_OBJECT
private:
    QLabel* artwork;
    SensorInfo* sensor_info;
    
public:
    TemperaturePanel(Sensor& sensor, QWidget* parent = 0);
    ~TemperaturePanel();

    virtual SensorInfo& getSensorInfo() const;
    virtual void filterSensor(const QString& type);

public slots:
    virtual void showInfo();
};

#endif