#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QDate>

class Data
{
private:
    QDate date;
    int temperature;
    int humidity;
    int microdust;
public:
    Data();
    Data(
        const QDate& _date,
        const int& _temperature,
        const int& _humidity,
        const int& _microdust
    );
    Data(const Data& _data); 
    ~Data() = default;

    const QDate& getDate() const;
    int getTemperature() const;
    int getHumidity() const;
    int getMicrodust() const;

    void setDate(const QDate& _date);
    void setTemperature(const int& _temperature);
    void setHumidity(const int& _humidity);
    void setMicrodust(const int& _microdust);
};

#endif 