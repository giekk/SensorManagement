#ifndef SENSORINFOVISITOR_H
#define SENSORINFOVISITOR_H

#include <QLabel>

#include "IVisitor.h"
#include "../temperature.h"
#include "../humidity.h"
#include "../microdust.h"

class SensorInfoVisitor : public IVisitor
{
private:
    QLabel* label_1;
    QLabel* label_2;
    QLabel* label_3;

public:
    QLabel* getLabel_1();
    QLabel* getLabel_2();
    QLabel* getLabel_3();
    
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitMicrodust(Microdust& microdust);
};

#endif