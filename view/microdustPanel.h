#ifndef MICRODUSTPANEL_H
#define MICRODUSTPANEL_H

#include "../microdust.h"
#include "sensorInfoDialog.h"
#include "sensorPanel.h"

class MicrodustPanel : public SensorPanel
{
    Q_OBJECT
private:
    QLabel* artwork;
    SensorInfo* sensor_info;
public:
    MicrodustPanel(Sensor& sensor, QWidget* parent = 0);
    ~MicrodustPanel();

    virtual SensorInfo& getSensorInfo() const;
    virtual void filterSensor(const QString& type);

public slots:
    virtual void showInfo();
};

#endif