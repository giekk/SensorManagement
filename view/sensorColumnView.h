#ifndef SENSORCOLUMNVIEW_H
#define SENSORCOLUMNVIEW_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>
#include <QFont>
#include <QCoreApplication>
#include <QScrollArea>
#include <QScrollBar>

#include "../sensorColumn.h"
#include "sensorPanel.h"
#include "temperaturePanel.h"
#include "humidityPanel.h"
#include "microdustPanel.h"
#include "addSensorDialog.h"
#include "sensorInfoDialog.h"
#include "buildSensorDialog.h"
#include "createSensorPanelVisitor.h"
#include "sensorFactory.h"

class SensorColumnView : public QWidget
{
    Q_OBJECT

private:
    SensorColumn* sensorColumn;

public:
    explicit SensorColumnView(QWidget* parent = nullptr);
    ~SensorColumnView();

    static QLayout* columnTopBar(QPushButton* button1, QPushButton* button2, QLabel* filterTitle, QComboBox* filter, QPixmap icon1, QPixmap icon2);
    bool sensorExists(const QString& id);

signals:
    void filter(const QString& type);

public slots:
    void addSensor(QLayout* sensor_layout);
    void removeSensor(const std::string& id, QWidget* panel, QLayout* sensor_layout);
    void modifySensor(const std::string& id, SensorPanel* panel);
    void saveSensors();
    void buildSensorData(SensorPanel* panel);
    void filterChanged(const QString& type);
};

#endif