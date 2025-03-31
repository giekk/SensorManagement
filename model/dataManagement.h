#ifndef DATAMANAGEMENT_H
#define DATAMANAGEMENT_H

#include "data.h"
#include "database.h"
#include "sensor.h"
#include "temperature.h"
#include "humidity.h"
#include "microdust.h"
#include "sensorDataVisitor.h"
#include "sensorFactory.h"

class DataManagement
{
private:
    Database* database;

public:
    explicit DataManagement();
    virtual ~DataManagement();

    std::vector<int> monthTemperatures(const int& month, const int& year);   //restituisce le temperature di un determinato mese
    std::vector<int> monthHumidities(const int& month, const int& year);     //restituisce l'umidita' di un determinato mese
    std::vector<int> monthMicrodusts(const int& month, const int& year);     //restituisce le micropolveri di un determinato mese

    std::vector<Sensor*> buildSensors();                    //restituisce un vector con i sensori presenti nel database
    void setSensorDataList(std::vector<Sensor*> sensors);   //trasforma la lista di sensori in una lista di SensorDatas e la salva nel database

    QStringList getDataDay(const QDate& date) const;       //restituisce i dati come QStringList di un giorno
    void insertDataDay(const QStringList& list);           //trasforma una lista QStringList in una lista di Datas e la inserisce nel database
    void saveData();                                                      
    bool checkDataInsertion(const QStringList& list);     //controlla che il dato sia stato inserito correttamente

    bool checkDataExistence(const int& month, const int& year);   //controlla che esistano dati per un determinato mese e anno
    static int getDaysInMonth(const int& month, const int& year);  //restituisce il numero di giorni in un mese
};

#endif