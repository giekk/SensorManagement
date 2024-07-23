#include "sensorFactory.h"

Sensor* SensorFactory::buildSensorByData(const SensorData& data)
{
    if (data.getType() == "Temperatura")
        return new Temperature(data.getName().toStdString(), data.getId().toStdString(), data.getMax(), data.getMin(), data.getAvg());
    else if (data.getType() == "Umidità")
        return new Humidity(data.getName().toStdString(), data.getId().toStdString(), data.getMax(), data.getMin(), data.getAvg());
    else if (data.getType() == "Micropolveri")
        return new Microdust(data.getName().toStdString(), data.getId().toStdString(), data.getMax(), data.getMin(), data.getAvg());
    return nullptr;
}

Sensor* SensorFactory::buildSensorByType(const QString& name, const QString& id, const QString& type)
{
    if (type == "Temperatura")
        return new Temperature(name.toStdString(), id.toStdString());
    else if (type == "Umidità")
        return new Humidity(name.toStdString(), id.toStdString());
    else if (type == "Micropolveri")
        return new Microdust(name.toStdString(), id.toStdString());
    return nullptr;
}
