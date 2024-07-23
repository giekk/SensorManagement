#include "sensorInfo.h"
#include "sensorInfoVisitor.h"

SensorInfo::SensorInfo(Sensor& _sensor, QWidget* parent) : QWidget(parent), sensor(_sensor)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->name = new QLabel();
    this->name->setStyleSheet("font-weight: bold;");
    layout->addWidget(this->name);

    this->id = new QLabel();
    layout->addWidget(this->id);

    this->type = new QLabel();
    layout->addWidget(this->type);

    this->reliability = new QLabel();
    layout->addWidget(this->reliability);

    SensorInfoVisitor visitor;
    this->sensor.accept(visitor);
    this->minimum = visitor.getLabel_1();
    this->maximum = visitor.getLabel_2();
    this->average = visitor.getLabel_3();
}

void SensorInfo::show()
{
    this->name->setText(QString::fromStdString(this->sensor.getName()));
    this->id->setText(QString::fromStdString(this->sensor.getId()));
    this->type->setText("Tipo: " + QString::fromStdString(this->sensor.getType()));
    this->reliability->setText("Affidabilità: " + QString::number(this->sensor.getReliability()) + "%");
}

void SensorInfo::showInfoWidget()
{
    QString infoText;
    infoText += this->minimum->text() + "\n";
    infoText += this->maximum->text() + "\n";
    infoText += this->average->text();
    QMessageBox* info = new QMessageBox();
    info->setText(infoText);
    info->setWindowTitle("Dati sensore");
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - info->width()) / 2;
    int y = (screenGeometry.height() - info->height()) / 2;
    info->move(x, y);
    info->exec();
}

SensorInfo::~SensorInfo()
{
    delete this->name;
    this->name = nullptr;
    delete this->id;
    this->id = nullptr;
    delete this->type;
    this->type = nullptr;
    delete this->reliability;
    this->reliability = nullptr;
}

Sensor& SensorInfo::getSensor() const
{
    return this->sensor;
} 

QLabel* SensorInfo::getName() const
{
    return this->name;
}

QLabel* SensorInfo::getId() const
{
    return this->id;
}

QLabel* SensorInfo::getType() const
{
    return this->type;
}

QLabel* SensorInfo::getReliability() const
{
    return this->reliability;
}

QLabel* SensorInfo::getMinimum() const
{
    return this->minimum;
}

QLabel* SensorInfo::getMaximum() const
{
    return this->maximum;
}

QLabel* SensorInfo::getAverage() const
{
    return this->average;
}

void SensorInfo::updateSensorInfo(Sensor* sensor)
{
    SensorInfoVisitor visitor;
    sensor->accept(visitor);
    this->minimum->setText(visitor.getLabel_1()->text());
    this->maximum->setText(visitor.getLabel_2()->text());
    this->average->setText(visitor.getLabel_3()->text());
}

void SensorInfo::setName(const QString& _name)
{
    this->name->setText(_name);
}

void SensorInfo::setId(const QString& _id)
{
    this->id->setText(_id);
}

void SensorInfo::setType(const QString& _type)
{
    this->type->setText(_type);
}

void SensorInfo::setReliability(const QString& _reliability)
{
    this->reliability->setText(_reliability);
}
