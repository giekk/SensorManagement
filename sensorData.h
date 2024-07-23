#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <QString>

class SensorData
{
private:
    QString name;
    QString id;
    QString type;
    int reliability;
    int max;
    int min;
    int avg;
public:
    SensorData();
    SensorData(
        QString _name,
        QString _id,
        QString _type,
        int _reliability,
        int _max,
        int _min,
        int _avg
    );
    SensorData(const SensorData& _sensorData);
    ~SensorData() = default;

    const QString& getName() const;
    const QString& getId() const;
    const QString& getType() const;
    int getReliability() const;
    int getMax() const;
    int getMin() const;
    int getAvg() const;

    void setName(const QString& _name);
    void setId(const QString& _id);
    void setType(const QString& _type);
    void setReliability(const int& _reliability);
    void setMax(const int& _max);
    void setMin(const int& _min);
    void setAvg(const int& _avg);
};

#endif