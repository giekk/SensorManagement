#ifndef CREATESENSORPANELVISITOR_H
#define CREATESENSORPANELVISITOR_H

#include "IVisitor.h"
#include "temperaturePanel.h"
#include "humidityPanel.h"
#include "microdustPanel.h"

class CreateSensorPanelVisitor : public IVisitor
{
private:
    SensorPanel* panel = nullptr;

public:
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitMicrodust(Microdust& microdust);

    SensorPanel* getPanel() const;
};

#endif