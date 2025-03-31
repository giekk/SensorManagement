#ifndef IVISITOR_H
#define IVISITOR_H

class Temperature;
class Humidity;
class Microdust;

class IVisitor {
public:
    virtual ~IVisitor() = default;
    virtual void visitTemperature(Temperature& temperature) = 0;
    virtual void visitHumidity(Humidity& humidity) = 0;
    virtual void visitMicrodust(Microdust& microdust) = 0;
};

#endif