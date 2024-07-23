#include "database.h"

Database::Database() {
}

Database::~Database() 
{
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        delete *it;
    }
    for (auto it = this->sensorDatas.begin(); it != this->sensorDatas.end(); ++it)
    {
        delete *it;
    }
}

void Database::removeData(Data* data)
{
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        if ((*it)->getDate() == data->getDate()) 
        {
            (*it)->setTemperature(0);
            (*it)->setHumidity(0);
            (*it)->setMicrodust(0);
        }
    }
}

void Database::removeSensorData(SensorData* sensorData)
{
    for (auto it = this->sensorDatas.begin(); it != this->sensorDatas.end(); ++it)
    {
        if ((*it)->getId() == sensorData->getId())
        {
            this->sensorDatas.erase(it);
        }
    }
}

void Database::addData(Data* data)
{
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        if ((*it)->getDate() == data->getDate())
        {
            (*it)->setTemperature(data->getTemperature());
            (*it)->setHumidity(data->getHumidity());
            (*it)->setMicrodust(data->getMicrodust());
            return;
        }
        else if ((*it)->getDate() > data->getDate())
        {
            this->datas.insert(it, data);
            return;
        }
    }
    this->datas.push_back(data);
}
    
  

void Database::addSensorData(SensorData* sensor_data)
{
    for (auto it = this->sensorDatas.begin(); it != this->sensorDatas.end(); ++it)
    {
        if ((*it)->getId() == sensor_data->getId())
        {
            (*it)->setReliability(sensor_data->getReliability());
            (*it)->setMax(sensor_data->getMax());
            (*it)->setMin(sensor_data->getMin());
            (*it)->setAvg(sensor_data->getAvg());
            return;
        }
    }
    this->sensorDatas.push_back(sensor_data);
}

void Database::clearDatas()
{
    for (auto it = this->datas.end(); it != this->datas.begin(); ++it)
    {
        delete *it;
    }
}

void Database::clearSensorDatas()
{
    for (auto it = this->sensorDatas.end(); it != this->sensorDatas.begin(); ++it)
    {
        delete *it;
    }
}

std::string Database::getDataPath() const 
{
    return this->data_path;
}

std::string Database::getSensorDataPath() const 
{
    return this->sensorData_path;
}

std::list<Data*> Database::getDatas() const
{
    std::list<Data*> datasCopy;
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        datasCopy.push_back(new Data(**it));
    }
    return datasCopy;
}

std::list<SensorData*> Database::getSensorDatas() const
{
    std::list<SensorData*> sensorDatasCopy;
    for (auto it = this->sensorDatas.begin(); it != this->sensorDatas.end(); ++it)
    {
        sensorDatasCopy.push_back(new SensorData(**it));
    }
    return sensorDatasCopy;
}

void Database::loadDatas()
{
    this->clearDatas();
    QFile file(QString::fromStdString(this->data_path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Errore", "Database non trovato!");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QDate date = QDate::fromString(fields[0], "dd/MM/yyyy");       
        int temperature = fields[1].toInt();                             
        int humidity = fields[2].toInt();                                
        int microdust = fields[3].toInt();                               
        Data* data = new Data(date, temperature, humidity, microdust);   
        this->datas.push_back(data);                                      
    }
    file.close();
}

void Database::loadSensorDatas()
{
    this->clearSensorDatas();
    QFile file(QString::fromStdString(this->sensorData_path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Errore", "Database non trovato!");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QString name = fields[0]; 
        QString id = fields[1];
        QString type = fields[2];
        int reliability = fields[3].toInt();
        int max = fields[4].toInt();
        int min = fields[5].toInt();
        int avg = fields[6].toInt();
        SensorData* sensorData = new SensorData(name, id, type, reliability, max, min, avg);
        this->sensorDatas.push_back(sensorData);
    }
    file.close();
}                                      

void Database::saveDatas()
{
    QFile::remove(this->data_path.c_str());  //elimino file.csv se esiste
    //creo nuovo file.csv
    QFile file(this->data_path.c_str());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Errore", "Database non trovato!");
        return;
    }
    //salvo i dati nel file.csv
    QTextStream out(&file);
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        out << (*it)->getDate().toString("dd/MM/yyyy") << ","
            << (*it)->getTemperature() << ","
            << (*it)->getHumidity() << ","
            << (*it)->getMicrodust() << "\n";
    }
    file.close();
}

void Database::saveSensorDatas()
{
    QFile::remove(this->sensorData_path.c_str());  //elimino file.csv se esiste
    //creo nuovo file.csv
    QFile file(this->sensorData_path.c_str());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Errore", "Database non trovato!");
        return;
    }
    //salvo i dati nel file.csv
    QTextStream out(&file);
    for (auto it = this->sensorDatas.begin(); it != this->sensorDatas.end(); ++it)
    {
        out << (*it)->getName() << ","
            << (*it)->getId() << ","
            << (*it)->getType() << ","
            << (*it)->getReliability() << ","
            << (*it)->getMax() << ","
            << (*it)->getMin() << ","
            << (*it)->getAvg() << "\n";
    }
    file.close();
}

void Database::setDatas(std::list<Data*> _datas)
{
    this->datas.clear();  
    for (auto it = _datas.begin(); it != _datas.end(); ++it)
    {
        if (*it != nullptr) this->datas.push_back(new Data(**it));
    }
    this->saveDatas();
}

void Database::setSensorDatas(std::list<SensorData*> _sensorDatas)
{
    this->sensorDatas.clear();  
    for (auto it = _sensorDatas.begin(); it != _sensorDatas.end(); ++it)
    {
        if (*it != nullptr) this->sensorDatas.push_back(new SensorData(**it));
    }
    this->saveSensorDatas();
}



