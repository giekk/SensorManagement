#include "sensorColumnView.h"

SensorColumnView::SensorColumnView(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QPushButton* add_sensor = new QPushButton();
    QPushButton* save = new QPushButton();
    QLabel* filterTitle = new QLabel();
    QComboBox* typeFilter = new QComboBox();
    QLabel* titleBar = new QLabel();
    titleBar->setText("Sensori:");
    titleBar->setFont(QFont("Arial", 12, QFont::Bold));
    QLayout* columnTopBar = this->columnTopBar(add_sensor, save, filterTitle, typeFilter, QPixmap(QCoreApplication::applicationDirPath() + "/img/add_icon.png"), QPixmap(QCoreApplication::applicationDirPath() + "/img/save_icon.png"));

    this->sensorColumn = new SensorColumn();

    QLayout* sensor_layout = new QVBoxLayout();
    sensor_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    connect(typeFilter, &QComboBox::currentTextChanged, this, &SensorColumnView::filterChanged);

    std::vector<Sensor*> sensors = this->sensorColumn->getSensors();
    for (auto it = sensors.begin(); it != sensors.end(); ++it)
    {
        const std::string& sensorId = (*it)->getId();
        CreateSensorPanelVisitor visitor;
        (*it)->accept(visitor);
        SensorPanel* panel = visitor.getPanel();
        if (panel != nullptr) 
        {
            sensor_layout->addWidget(panel);
            connect(panel, &SensorPanel::remove, this, [this, sensorId, panel, sensor_layout](){ this->removeSensor(sensorId, panel, sensor_layout); });
            connect(panel, &SensorPanel::modify, this, [this, sensorId, panel](){ this->modifySensor(sensorId, panel); });
            connect(panel, &SensorPanel::build, this, [this, panel](){ this->buildSensorData(panel); });
            connect(this, &SensorColumnView::filter, panel, &SensorPanel::filterSensor);
        }
    }
    sensors.clear();

    QScrollArea* scrollArea = new QScrollArea(this); 
    QWidget* sensorContainer = new QWidget(); 
    sensorContainer->setLayout(sensor_layout);
    sensorContainer->adjustSize();
    scrollArea->setMaximumWidth(sensorContainer->sizeHint().width() - 100 + scrollArea->verticalScrollBar()->width());
    scrollArea->setWidget(sensorContainer); 
    scrollArea->setWidgetResizable(true); 
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); 

    layout->addWidget(titleBar);
    layout->addLayout(columnTopBar);
    layout->addWidget(scrollArea);

    connect(add_sensor, &QPushButton::clicked, this, [this, sensor_layout] { this->addSensor(sensor_layout); });
    connect(save, &QPushButton::clicked, this, &SensorColumnView::saveSensors);
}

SensorColumnView::~SensorColumnView()
{
    delete this->sensorColumn;
    this->sensorColumn = nullptr;
}

QLayout* SensorColumnView::columnTopBar(QPushButton* button1, QPushButton* button2, QLabel* filterTitle, QComboBox* filter, QPixmap icon1, QPixmap icon2)
{
    QLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    
    button1->setIcon(QIcon(icon1));
    button1->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button1->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button1->setStyleSheet("border: none; background-color: transparent;");
    button1->setCursor(Qt::PointingHandCursor);
    button1->setToolTip("Aggiungi sensore");
    button2->setIcon(QIcon(icon2));
    button2->setIconSize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button2->resize(QSize(BTN_HEIGHT, BTN_WIDTH));
    button2->setStyleSheet("border: none; background-color: transparent;");
    button2->setCursor(Qt::PointingHandCursor);
    button2->setToolTip("Salva");
    filterTitle->setText("Filtra:");
    filter->addItem("Tutti");
    filter->addItem("Temperatura");
    filter->addItem("Umidità");
    filter->addItem("Micropolveri");
    filter->setCurrentText("Tutti");
    filter->setMinimumWidth(120);
    filter->setStyleSheet(" border-radius: 5px; background-color: #d0d0d0; ");
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(filterTitle);
    layout->addWidget(filter);
    
    return layout;
}

void SensorColumnView::buildSensorData(SensorPanel* panel)
{
    BuildsensorDialog dialog(this);
    if (dialog.exec() && QDialog::Accepted)
    {
        int month = dialog.getMonth();
        int year = dialog.getYear();
        if (!this->sensorColumn->checkDataExistence(month, year))
        {
            QMessageBox::warning(this, "Errore", "Nessun dato disponibile per il mese e l'anno selezionati");
            return;
        }
        SensorInfo& sensor_info = panel->getSensorInfo(); 
        this->sensorColumn->setSensorData(sensor_info.getId()->text(), month, year);
        std::vector<Sensor*> sensors = this->sensorColumn->getSensors();
        for (auto it = sensors.begin(); it != sensors.end(); ++it)
        {
            if (sensor_info.getId()->text().toStdString() == (*it)->getId())
                sensor_info.updateSensorInfo(*it);
        }
        QMessageBox::information(this, "Successo", "Dati sensore aggiornati");
        sensors.clear();
    }
}

bool SensorColumnView::sensorExists(const QString& id)
{
    std::vector<Sensor*> sensors = this->sensorColumn->getSensors();
    for (auto it = sensors.begin(); it != sensors.end(); ++it)
    {
        if ((*it)->getId() == id.toStdString())
        {
            return true;
        }
    }
    sensors.clear();
    return false;
}

void SensorColumnView::addSensor(QLayout* sensor_layout)
{
    AddSensorDialog dialog(this);
    if (dialog.exec() && QDialog::Accepted)
    {
        QString name = dialog.getName();
        QString id = dialog.getID();
        QString type = dialog.getType();

        if (this->sensorExists(id))
        {
            QMessageBox::warning(this, "Errore", "Sensore già esistente");
            return;
        }
        if (name.isEmpty())
        {
            QMessageBox::warning(this, "Errore", "Nome sensore non valido");
            return;
        }
        if (id.isEmpty())
        {
            QMessageBox::warning(this, "Errore", "ID sensore non valido");
            return;
        }

        Sensor* sensor = SensorFactory::buildSensorByType(name, id, type);
        CreateSensorPanelVisitor visitor;
        sensor->accept(visitor);
        SensorPanel* panel = visitor.getPanel();

        if (sensor != nullptr && panel != nullptr) 
        {
            const std::string& sensorId = sensor->getId();
            this->sensorColumn->addSensor(sensor);
            sensor_layout->addWidget(panel);
            connect(panel, &SensorPanel::remove, this, [this, sensorId, panel, sensor_layout](){ this->removeSensor(sensorId, panel, sensor_layout); });
            connect(panel, &SensorPanel::modify, this, [this, sensorId, panel](){ this->modifySensor(sensorId, panel); });
            connect(panel, &SensorPanel::build, this, [this, panel](){ this->buildSensorData(panel); });
            connect(this, &SensorColumnView::filter, panel, &SensorPanel::filterSensor);
        }
    }
}

void SensorColumnView::saveSensors()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Salva", "Sei sicuro di voler salvare le modifiche apportate?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) 
    {
        std::vector<Sensor*> sensors = this->sensorColumn->getSensors();
        this->sensorColumn->setSensorDataList(sensors);
        sensors.clear();
    } 
    else 
    {
        return;
    }
}

void SensorColumnView::removeSensor(const std::string& id, QWidget* panel, QLayout* sensor_layout)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Conferma eliminazione", "Sei sicuro di voler eliminare il sensore?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) 
    {
        this->sensorColumn->removeSensor(id);
        sensor_layout->removeWidget(panel);
        panel->deleteLater();
    } 
    else 
    {
        return;
    }
}

void SensorColumnView::modifySensor(const std::string& id, SensorPanel* panel)
{
    SensorInfoDialog dialog(this);
    SensorInfo& sensor_info = panel->getSensorInfo();
    dialog.setInfo(sensor_info.getName()->text());

    if (dialog.exec() == QDialog::Accepted) 
    {
        if (dialog.getName().isEmpty())
        {
            QMessageBox::warning(this, "Errore", "Nome sensore non valido");
            return;
        }
        this->sensorColumn->modifySensor(id, dialog.getName());
        sensor_info.setName(dialog.getName());
    }
}

void SensorColumnView::filterChanged(const QString& type)
{
    emit filter(type);
}
