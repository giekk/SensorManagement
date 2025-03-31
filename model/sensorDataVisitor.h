#ifndef SENSORDATAVISITOR_H
#define SENSORDATAVISITOR_H

#include "IVisitor.h"
#include "temperature.h"
#include "humidity.h"
#include "microdust.h"

class SensorDataVisitor : public IVisitor
{
private:
    int min;
    int max;
    int avg;

public:
    int getMin();
    int getMax();
    int getAvg();
    
    virtual void visitTemperature(Temperature& temperature);
    virtual void visitHumidity(Humidity& humidity);
    virtual void visitMicrodust(Microdust& microdust);
};

#endif