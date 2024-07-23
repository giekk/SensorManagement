#include "humidityPanel.h"

HumidityPanel::HumidityPanel(Sensor& sensor, QWidget* parent) : SensorPanel(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QPixmap image(QCoreApplication::applicationDirPath() + "/img/humidity.png");   //aggiungo immagine sensore temperatura
    image = image.scaled(IMG_WIDTH, IMG_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->artwork = new QLabel();
    this->artwork->setPixmap(image); // Ridimensiona mantenendo le proporzioni e applica una trasformazione fluida
    
    layout->addWidget(this->artwork);

    this->sensor_info = new SensorInfo(sensor);  //aggiungo info base sensore
    this->sensor_info->show();
    layout->addWidget(this->sensor_info);

    //bottoni
    QPushButton* remove = new QPushButton();
    QPushButton* modify = new QPushButton();
    QPushButton* info = new QPushButton();
    QPushButton* build = new QPushButton();
    QLayout* buttonLayout = this->buttonsLayout(remove, modify, info, build);

    layout->addLayout(buttonLayout);

    //apro connessione bottoni
    connect(remove, &QPushButton::clicked, this, &SensorPanel::remove);
    connect(modify, &QPushButton::clicked, this, &SensorPanel::modify);
    connect(info, &QPushButton::clicked, this, &HumidityPanel::showInfo);
    connect(build, &QPushButton::clicked, this, &SensorPanel::build);
}

HumidityPanel::~HumidityPanel()
{
    delete this->artwork;
    this->artwork = nullptr;
    delete this->sensor_info;
    this->sensor_info = nullptr;
}

SensorInfo& HumidityPanel::getSensorInfo() const
{
    return *(this->sensor_info);
}

void HumidityPanel::filterSensor(const QString& type)
{
    if (type == "Umidità" || type == "Tutti")
        this->show();
    else
        this->hide();
}

void HumidityPanel::showInfo()
{
    this->sensor_info->showInfoWidget();
}



