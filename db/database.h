#include <list>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

#include "data.h"
#include "sensorData.h"

#ifndef DATABASE_H
#define DATABASE_H

class Database 
{
private:
    std::string data_path = QCoreApplication::applicationDirPath().toStdString() + "/db/data.csv";
    std::string sensorData_path = QCoreApplication::applicationDirPath().toStdString() + "/db/sensorData.csv";
    std::list<Data*> datas;
    std::list<SensorData*> sensorDatas;
public:
    Database();                             //costruttore di default
    ~Database();                            //distruttore

    void loadDatas();                        //carica la lista di dati dal file data.csv
    void saveDatas();                        //salva la lista di dati sul file data.csv
    void clearDatas();                      //elimina tutti i dati della lista
    void addData(Data* data);               //aggiunge un dato alla lista di dati
    void removeData(Data* data);            //elimina un dato dalla lista di dati
    void setDatas(std::list<Data*> _datas); //copia la lista di dati e la salva con la save()

    void loadSensorDatas();                                     //carica la lista di sensorData dal file sensorData.csv
    void saveSensorDatas();                                     //salva la lista di sensorData sul file sensorData.csv
    void clearSensorDatas();                                    //elimina tutti i sensorData della lista
    void addSensorData(SensorData* sensorData);                 //aggiunge un sensorData alla lista di sensorData
    void removeSensorData(SensorData* sensorData);              //elimina un sensorData dalla lista di sensorData
    void setSensorDatas(std::list<SensorData*> _sensorDatas);   //copia la lista di sensorData e la salva con la save()

    std::string getDataPath() const;                    //restituisce il path del file data.csv
    std::string getSensorDataPath() const;              //restituisce il path del file sensorData.csv
    std::list<Data*> getDatas() const;                 //restituisce la lista di Data
    std::list<SensorData*> getSensorDatas() const;     //restituisce la lista di sensorData
};

#endif