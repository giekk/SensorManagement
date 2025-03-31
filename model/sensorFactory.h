#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "sensorData.h"
#include "sensor.h"
#include "temperature.h"
#include "humidity.h"
#include "microdust.h"

class SensorFactory 
{
public:
    static Sensor* buildSensorByData(const SensorData& data);
    static Sensor* buildSensorByType(const QString& name, const QString& id, const QString& type);
};

#endif