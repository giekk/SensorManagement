#ifndef DATACHARTVIEW_H
#define DATACHARTVIEW_H

#include <QChartView>
#include <QtWidgets/QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QComboBox>
#include <QLabel>
#include <QFont>
#include <QColor>

#include "dataChart.h"

#define BUTTON_HEIGHT 25
#define BUTTON_WIDTH 25

class DataChartView : public QWidget
{
    Q_OBJECT

private:
    QChart* chart = nullptr;
    DataChart* model;
    std::vector<int> datas;

    QComboBox* month_box;
    QComboBox* year_box;

    QPushButton* next;
    QPushButton* previous;
    QPushButton* temperature;
    QPushButton* humidity;
    QPushButton* microdust;

public:
    explicit DataChartView(QWidget* parent = nullptr);

    ~DataChartView();

    static QLayout* topBar(QComboBox* _month, QComboBox* _year);
    static QLayout* bottomBar(QPushButton* _next, QPushButton* _previous, QPixmap next_icon, QPixmap previous_icon);
    static QLayout* commandBar(QPushButton* _temperature, QPushButton* _humidity, QPushButton* _microdust, QPixmap temperature_icon, QPixmap humidity_icon, QPixmap microdust_icon);

    std::vector<int> getDatas() const;

public slots:
    void showTemperature();
    void showHumidity();
    void showMicrodust();
    void changeMonth();
    void changeYear();
    void nextMonth();
    void previousMonth();
};

#endif