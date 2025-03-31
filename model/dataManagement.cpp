#include "dataManagement.h"

DataManagement::DataManagement()
{
    this->database = new Database();
    this->database->loadDatas();
    this->database->loadSensorDatas();
}

DataManagement::~DataManagement()
{
    delete this->database;
    this->database = nullptr;
}

std::vector<int> DataManagement::monthTemperatures(const int& month, const int& year)
{
    std::vector<int> temperatures;
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate().month() == month && (*it)->getDate().year() == year)
            temperatures.push_back((*it)->getTemperature());
    }
    datas.clear();
    return temperatures;
}

std::vector<int> DataManagement::monthHumidities(const int& month, const int& year)
{
    std::vector<int> humidities;
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate().month() == month && (*it)->getDate().year() == year)
            humidities.push_back((*it)->getHumidity());
    }
    datas.clear();
    return humidities;
}

std::vector<int> DataManagement::monthMicrodusts(const int& month, const int& year)
{
    std::vector<int> microdusts;
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate().month() == month && (*it)->getDate().year() == year)
            microdusts.push_back((*it)->getMicrodust());
    }
    datas.clear();
    return microdusts;
}

std::vector<Sensor*> DataManagement::buildSensors()
{
    std::vector<Sensor*> sensors;
    std::list<SensorData*> sensorDatas = this->database->getSensorDatas();
    for (auto it = sensorDatas.begin(); it != sensorDatas.end(); ++it)
    {
        Sensor* sensor = SensorFactory::buildSensorByData(**it);
        if (sensor != nullptr) 
            sensors.push_back(sensor);
    }

    sensorDatas.clear();
    return sensors;
}

void DataManagement::setSensorDataList(std::vector<Sensor*> sensors)
{
    std::list<SensorData*> sensorDatas;
    SensorDataVisitor visitor;
    int min = 0, max = 0, avg = 0;
    for (auto it = sensors.begin(); it != sensors.end(); ++it)
    {
        if (*it == nullptr) continue;
        (*it)->accept(visitor);
        min = visitor.getMin();
        max = visitor.getMax();
        avg = visitor.getAvg();
        SensorData* sensorData = new SensorData(QString::fromStdString((*it)->getName()), QString::fromStdString((*it)->getId()), QString::fromStdString((*it)->getType()), (*it)->getReliability(), min, max, avg);
        sensorDatas.push_back(sensorData);
    }
    this->database->setSensorDatas(sensorDatas);
    sensorDatas.clear();
}

QStringList DataManagement::getDataDay(const QDate& date) const
{
    QStringList list;
    bool find = false;
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate() == date)
        {
            find = true;
            list.append(QString::number((*it)->getTemperature()));
            list.append(QString::number((*it)->getHumidity()));
            list.append(QString::number((*it)->getMicrodust()));
        }
    }
    if (find == false)
    {
        list.append("");
    }
    datas.clear();
    return list;
}

void DataManagement::insertDataDay(const QStringList& list)
{
    if (list.isEmpty()) return;
    this->database->addData(new Data(QDate::fromString(list.at(0), "dd/MM/yyyy"), list.at(1).toInt(), list.at(2).toInt(), list.at(3).toInt()));
}

void DataManagement::saveData()
{
    this->database->saveDatas();
}

bool DataManagement::checkDataInsertion(const QStringList& list)
{
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate() == QDate::fromString(list.at(0), "dd/MM/yyyy"))
        {
            if (list.at(1) == QString::number((*it)->getTemperature()) && list.at(2) == QString::number((*it)->getHumidity()) && list.at(3) == QString::number((*it)->getMicrodust()))
            {
                return true;
            }
        }
    }
    datas.clear();
    return false;
}

bool DataManagement::checkDataExistence(const int& month, const int& year)
{
    bool find = false;
    std::list<Data*> datas = this->database->getDatas();
    for (auto it = datas.begin(); it != datas.end(); ++it)
    {
        if ((*it)->getDate().month() == month && (*it)->getDate().year() == year)
        {
            find = true;
        }
    }
    datas.clear();
    return find;
}

int DataManagement::getDaysInMonth(const int& month, const int& year)
{
    return QDate(year, month, 1).daysInMonth();
}

  