#include "dataChartView.h"

DataChartView::DataChartView(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* main_layout = new QVBoxLayout(this);

    this->month_box = new QComboBox();
    this->year_box = new QComboBox();
    QLayout* topbar = this->topBar(this->month_box, this->year_box);

    this->temperature = new QPushButton();
    this->humidity = new QPushButton();
    this->microdust = new QPushButton();
    QLayout* commandbar = this->commandBar(this->temperature, this->humidity, this->microdust, QPixmap(QCoreApplication::applicationDirPath() + "/img/temperature.png"), QPixmap(QCoreApplication::applicationDirPath() + "/img/humidity.png"), QPixmap(QCoreApplication::applicationDirPath() + "/img/microdust.png"));
    
    this->model = new DataChart(this->month_box->currentText().toInt(), this->year_box->currentText().toInt());

    QLineSeries* series = new QLineSeries();
    int index = 1;
    this->datas = this->model->getTemperatures();
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it, ++index)
    {
        series->append(index, *it);
    }

    this->chart = new QChart();
    this->chart->addSeries(series);
    this->chart->legend()->hide();
    QFont font = chart->titleFont();
    font.setBold(true); 
    chart->setTitleFont(font); 
    QBrush brush(Qt::red); 
    chart->setTitleBrush(brush); 

    this->showTemperature();  // Mostra la temperatura di default

    // Crea il QChartView e aggiungo al layout
    QChartView* chartView = new QChartView(this->chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->next = new QPushButton();
    this->previous = new QPushButton();
    QLayout* bottombar = this->bottomBar(this->next, this->previous, QPixmap(QCoreApplication::applicationDirPath() + "/img/next_icon.png"), QPixmap(QCoreApplication::applicationDirPath() + "/img/back_icon.png"));
    
    main_layout->addLayout(topbar);
    main_layout->addLayout(commandbar);
    main_layout->addWidget(chartView);
    main_layout->addLayout(bottombar);

    //apro connessione bottoni
    connect(this->humidity, &QPushButton::clicked, this, &DataChartView::showHumidity);
    connect(this->temperature, &QPushButton::clicked, this, &DataChartView::showTemperature);
    connect(this->microdust, &QPushButton::clicked, this, &DataChartView::showMicrodust);
    
    connect(this->month_box, &QComboBox::currentTextChanged, this, &DataChartView::changeMonth);
    connect(this->year_box, &QComboBox::currentTextChanged, this, &DataChartView::changeYear);

    connect(this->next, &QPushButton::clicked, this, &DataChartView::nextMonth);
    connect(this->previous, &QPushButton::clicked, this, &DataChartView::previousMonth);
}

DataChartView::~DataChartView()
{
    delete this->model;
    this->model = nullptr;
    delete this->chart;
    this->chart = nullptr;
    delete this->month_box;
    this->month_box = nullptr;
    delete this->year_box;
    this->year_box = nullptr;
    delete this->next;
    this->next = nullptr;
    delete this->previous;
    this->previous = nullptr;
    delete this->temperature;
    this->temperature = nullptr;
    delete this->humidity;
    this->humidity = nullptr;
    delete this->microdust;
    this->microdust = nullptr;
}

QLayout* DataChartView::topBar(QComboBox* _month, QComboBox* _year)
{
    QLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QLabel* month_label = new QLabel("Mese:");
    for (int month = 1; month <= 12; ++month)
    {
        _month->addItem(QString::number(month));
    }
    _month->setCurrentText(QString::number(QDate::currentDate().month()));
    QLabel* year_label = new QLabel("Anno:");
    for (int year = 2021; year <= 2024; ++year)
    {
        _year->addItem(QString::number(year));
    }
    _year->setCurrentText(QString::number(QDate::currentDate().year()));
    layout->addWidget(month_label);
    layout->addWidget(_month);
    layout->addWidget(year_label);
    layout->addWidget(_year);
    return layout;
}

QLayout* DataChartView::bottomBar(QPushButton* _next, QPushButton* _previous, QPixmap next_icon, QPixmap previous_icon)
{
    QLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    _previous->setIcon(QIcon(previous_icon));
    _next->setIcon(QIcon(next_icon));
    _previous->setIconSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _previous->resize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _next->setIconSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _next->resize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _previous->setStyleSheet("border: none; background-color: transparent;");
    _next->setStyleSheet("border: none; background-color: transparent;");
    _previous->setCursor(Qt::PointingHandCursor);
    _next->setCursor(Qt::PointingHandCursor);
    _previous->setToolTip("Mese precedente");
    _next->setToolTip("Mese successivo");
    layout->addWidget(_previous);
    layout->addWidget(_next);
    return layout;
}

QLayout* DataChartView::commandBar(QPushButton* _temperature, QPushButton* _humidity, QPushButton* _microdust, QPixmap temperature_icon, QPixmap humidity_icon, QPixmap microdust_icon)
{
    QLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    _temperature->setIcon(QIcon(temperature_icon));
    _humidity->setIcon(QIcon(humidity_icon));
    _microdust->setIcon(QIcon(microdust_icon));
    _temperature->setIconSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _humidity->setIconSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _microdust->setIconSize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _temperature->resize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _humidity->resize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _microdust->resize(QSize(BUTTON_HEIGHT, BUTTON_WIDTH));
    _temperature->setStyleSheet("border: none; background-color: transparent;");
    _humidity->setStyleSheet("border: none; background-color: transparent;");
    _microdust->setStyleSheet("border: none; background-color: transparent;");
    _temperature->setCursor(Qt::PointingHandCursor);
    _humidity->setCursor(Qt::PointingHandCursor);
    _microdust->setCursor(Qt::PointingHandCursor);
    _temperature->setToolTip("Temperatura");
    _humidity->setToolTip("Umidità");
    _microdust->setToolTip("Micropolveri");
    layout->addWidget(_temperature);
    layout->addWidget(_humidity);
    layout->addWidget(_microdust);
    return layout;
}

std::vector<int> DataChartView::getDatas() const
{
    std::vector<int> copy;
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it)
    {
        copy.push_back(*it);
    }
    return copy;
}

void DataChartView::showHumidity()
{
    QLineSeries* series = new QLineSeries();
    int index = 1;
    this->datas.clear();
    this->datas = this->model->getHumidities();
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it, ++index)
    {
        series->append(index, *it);
    }
    this->chart->removeAllSeries();

    // Rimuovi gli assi esistenti
    QList<QAbstractAxis*> existingAxes = this->chart->axes();
    if (!existingAxes.isEmpty())
    {
        foreach (QAbstractAxis* axis, existingAxes) 
        {
            this->chart->removeAxis(axis);
            delete axis; 
        }
    }

    this->chart->addSeries(series);
    this->chart->setTitle("Umidità");

    // Configura l'asse X
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Giorni");
    axisX->setLabelFormat("%i"); 
    axisX->setRange(1, this->model->getDays()); 
    axisX->setTickCount(this->model->getDays()); 
    this->chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configura l'asse Y
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Umidità (%)");
    axisY->setLabelFormat("%i"); 
    axisY->setRange(0, 100); 
    axisY->setTickCount(11); 
    this->chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    this->chart->update();
}

void DataChartView::showTemperature()
{
    QLineSeries* series = new QLineSeries();
    int index = 1;
    this->datas.clear();
    this->datas = this->model->getTemperatures();
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it, ++index)
    {
        series->append(index, *it);
    }
    this->chart->removeAllSeries();

    // Rimuovi gli assi esistenti
    QList<QAbstractAxis*> existingAxes = this->chart->axes();
    if (!existingAxes.isEmpty())
    {
        foreach (QAbstractAxis* axis, existingAxes) 
        {
            this->chart->removeAxis(axis);
            delete axis; 
        }
    }

    this->chart->addSeries(series);
    this->chart->setTitle("Temperatura");

    // Configura l'asse X
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Giorni");
    axisX->setLabelFormat("%i"); 
    axisX->setRange(1, this->model->getDays()); 
    axisX->setTickCount(this->model->getDays()); 
    this->chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configura l'asse Y
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Temperatura (°C)");
    axisY->setLabelFormat("%i"); 
    axisY->setRange(-10, 50); 
    axisY->setTickCount(7); 
    this->chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    this->chart->update();
}

void DataChartView::showMicrodust()
{
    QLineSeries* series = new QLineSeries();
    int index = 1;
    this->datas.clear();
    this->datas = this->model->getMicrodusts();
    for (auto it = this->datas.begin(); it != this->datas.end(); ++it, ++index)
    {
        series->append(index, *it);
    }
    this->chart->removeAllSeries();

    // Rimuovi gli assi esistenti
    QList<QAbstractAxis*> existingAxes = this->chart->axes();
    if (!existingAxes.isEmpty())
    {
        foreach (QAbstractAxis* axis, existingAxes) 
        {
            this->chart->removeAxis(axis);
            delete axis; 
        }
    }

    this->chart->addSeries(series);
    this->chart->setTitle("Micropolveri");

    // Configura l'asse X
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Giorni");
    axisX->setLabelFormat("%i"); 
    axisX->setRange(1, this->model->getDays()); 
    axisX->setTickCount(this->model->getDays());
    this->chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configura l'asse Y
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Micropolveri (%)");
    axisY->setLabelFormat("%i"); 
    axisY->setRange(0, 100); 
    axisY->setTickCount(11); 
    this->chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    this->chart->update();
}

void DataChartView::changeMonth()
{
    this->model->updateData(this->month_box->currentText().toInt(), this->year_box->currentText().toInt());
    if (this->chart->title() == "Temperatura")
    {
        this->showTemperature();
    }
    else if (this->chart->title() == "Umidità")
    {
        this->showHumidity();
    }
    else if (this->chart->title() == "Micropolveri")
    {
        this->showMicrodust();
    }
}

void DataChartView::changeYear()
{
    this->model->updateData(this->month_box->currentText().toInt(), this->year_box->currentText().toInt());
    if (this->chart->title() == "Temperatura")
    {
        this->showTemperature();
    }
    else if (this->chart->title() == "Umidità")
    {
        this->showHumidity();
    }
    else if (this->chart->title() == "Micropolveri")
    {
        this->showMicrodust();
    }
}

void DataChartView::nextMonth()
{
    int lastYearIndex = this->year_box->count() - 1; 
    int lastYear = this->year_box->itemText(lastYearIndex).toInt();

    if (this->month_box->currentText().toInt() == 12 && this->year_box->currentText().toInt() == lastYear)
    {
        return;
    }
    if (this->month_box->currentText().toInt() == 12)
    {
        this->month_box->setCurrentText("1");
        this->year_box->setCurrentText(QString::number(this->year_box->currentText().toInt() + 1));
    }
    else
    {
        this->month_box->setCurrentText(QString::number(this->month_box->currentText().toInt() + 1));
    }
}

void DataChartView::previousMonth()
{
    int firstYear = this->year_box->itemText(0).toInt(); 

    if (this->month_box->currentText().toInt() == 1 && this->year_box->currentText().toInt() == firstYear)
    {
        return;
    }
    if (this->month_box->currentText().toInt() == 1)
    {
        this->month_box->setCurrentText("12");
        this->year_box->setCurrentText(QString::number(this->year_box->currentText().toInt() - 1));
    }
    else
    {
        this->month_box->setCurrentText(QString::number(this->month_box->currentText().toInt() - 1));
    }
}
    