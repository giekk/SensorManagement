#include "sensorColumn.h"

SensorColumn::SensorColumn() 
{
    this->sensors = this->buildSensors();
}

SensorColumn::~SensorColumn() 
{
    for (auto it = this->sensors.begin(); it != this->sensors.end(); ++it)
    {
        delete *it;
    }
    this->sensors.clear();
}

void SensorColumn::addSensor(Sensor* sensor) 
{
    this->sensors.push_back(sensor);
}

void SensorColumn::removeSensor(const std::string& id) 
{
    for (auto it = this->sensors.begin(); it != this->sensors.end();)
    {
        if ((*it)->getId() == id)
            it = this->sensors.erase(it);
        else ++it;
    }
}

void SensorColumn::modifySensor(const std::string& id, const QString& nameToCopy) 
{
    for (auto it = this->sensors.begin(); it != this->sensors.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            (*it)->setName(nameToCopy.toStdString());
            return;
        }
    }
}

void SensorColumn::setSensorData(const QString& id, int month, int year) 
{
    for (auto it = this->sensors.begin(); it != this->sensors.end(); ++it)
    {
        if ((*it)->getId() == id.toStdString())
        {
            SetSensorVisitor visitor(*this, month, year);
            (*it)->accept(visitor);
            return;
        }
    }
}

std::vector<Sensor*> SensorColumn::getSensors() 
{
    std::vector<Sensor*> sensors;
    for (auto it = this->sensors.begin(); it != this->sensors.end(); ++it)
    {
        sensors.push_back(*it);
    }
    return sensors;
}
