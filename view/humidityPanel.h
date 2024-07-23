#ifndef HUMIDITYPANEL_H
#define HUMIDITYPANEL_H

#include "../humidity.h"
#include "sensorInfoDialog.h"
#include "sensorPanel.h"

class HumidityPanel : public SensorPanel
{
    Q_OBJECT
private:
    QLabel* artwork;
    SensorInfo* sensor_info;
public:
    HumidityPanel(Sensor& sensor, QWidget* parent = 0);
    ~HumidityPanel();

    virtual SensorInfo& getSensorInfo() const;
    virtual void filterSensor(const QString& type);

public slots:
    virtual void showInfo();

};

#endif