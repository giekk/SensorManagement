#ifndef SENSORCOLUMN_H
#define SENSORCOLUMN_H

#include "dataManagement.h"
#include "setSensorVisitor.h"

class SensorColumn : public DataManagement
{
private:
    std::vector<Sensor*> sensors;
public:
    explicit SensorColumn();
    ~SensorColumn();

    void addSensor(Sensor* sensor);
    void removeSensor(const std::string& id);
    void modifySensor(const std::string& id, const QString& nameToCopy);
    void setSensorData(const QString& id, int month, int year);
    std::vector<Sensor*> getSensors();
};

#endif