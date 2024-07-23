#include "createSensorPanelVisitor.h"

void CreateSensorPanelVisitor::visitTemperature(Temperature& temperature)
{
    this->panel = new TemperaturePanel(temperature);
}

void CreateSensorPanelVisitor::visitHumidity(Humidity& humidity)
{
    this->panel = new HumidityPanel(humidity);
}

void CreateSensorPanelVisitor::visitMicrodust(Microdust& microdust)
{
    this->panel = new MicrodustPanel(microdust);
}

SensorPanel* CreateSensorPanelVisitor::getPanel() const
{
    return this->panel;
}