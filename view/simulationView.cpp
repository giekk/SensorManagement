#include "simulationView.h"

SimulationView::SimulationView(QWidget* parent) : QWidget(parent)
{
    this->setWindowTitle("Sensor Management");
    this->setMinimumSize(1100, 600);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //creo topbar
    this->home_button = new QPushButton();
    QLabel* titleBar = new QLabel();
    titleBar->setText("Simulatore");
    titleBar->setFont(QFont("Arial", 20, QFont::Bold));
    QWidget* topbar = new TopBar(this->home_button, titleBar, QPixmap(QCoreApplication::applicationDirPath() + "/img/home_icon.png"));
    topbar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //creo colonna sensori
    this->sensor_column = new SensorColumnView();

    //creo grafico
    this->data_chart = new DataChartView();

    layout->addWidget(this->sensor_column);
    layout->addWidget(this->data_chart);
    layout->setStretch(0, 1);
    layout->setStretch(1, 3);
    main_layout->addWidget(topbar);
    main_layout->addLayout(layout);
    this->setLayout(main_layout);

    connect(this->home_button, &QPushButton::pressed, this, &SimulationView::showHomeView);
}

SimulationView::~SimulationView()
{
    delete this->home_button;
    this->home_button = nullptr;
    delete this->sensor_column;
    this->sensor_column = nullptr;
    delete this->data_chart;
    this->data_chart = nullptr;
}

void SimulationView::showHomeView()
{
    emit toHomeView();
}