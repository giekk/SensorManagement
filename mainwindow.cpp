#include "mainwindow.h"

MainWindow::MainWindow(Ctrl* _ctrl) : ctrl(_ctrl)
{
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    this->home_view = new HomeView(this);
    setMinimumSize(700, 400);
    move(QPoint(600,250));
    this->main_layout = new QVBoxLayout(this);
    this->main_layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    this->home_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout->addWidget(this->home_view);
    this->home_view->show();

    connect(this->home_view, &HomeView::toTutorialView, this, &MainWindow::viewShowTutorialView);
    connect(this->home_view, &HomeView::toSimulationView, this, &MainWindow::viewShowSimulationView);
    connect(this->home_view, &HomeView::toDBEditorView, this, &MainWindow::viewShowDBEditorView);

    setWindowTitle("Sensor Management");
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/img/sensor_icon.png"));
}

MainWindow::~MainWindow()
{
    delete this->home_view;
    this->home_view = nullptr;
    delete this->tutorial_view;
    this->tutorial_view = nullptr;
    delete this->dbEditor_view;
    this->dbEditor_view = nullptr;
    delete this->simulation_view;
    this->simulation_view = nullptr;
    delete this->main_layout;
    this->main_layout = nullptr;
}

void MainWindow::hideCurrentView()
{
    if (this->home_view != nullptr && this->home_view->isVisible()) {
        this->home_view->hide();
        this->main_layout->removeWidget(this->home_view);
    }
    if (this->tutorial_view != nullptr && this->tutorial_view->isVisible()) {
        this->tutorial_view->hide();
        this->main_layout->removeWidget(this->tutorial_view);
    }
    if (this->dbEditor_view != nullptr && this->dbEditor_view->isVisible()) {
        this->dbEditor_view->hide();
        this->main_layout->removeWidget(this->dbEditor_view);
    }
    if (this->simulation_view != nullptr && this->simulation_view->isVisible()) {
        this->simulation_view->hide();
        this->main_layout->removeWidget(this->simulation_view);
    }
}

void MainWindow::viewShowHomeView()
{
    this->hideCurrentView();
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x=(screenGeometry.width()-home_view->width())/2;
    int y=(screenGeometry.height()-home_view->height())/2;
    move(QPoint(x,y));
    setMinimumSize(700, 400);
    this->home_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout->addWidget(this->home_view);
    this->home_view->show();
}


void MainWindow::viewShowTutorialView()
{
    this->hideCurrentView();
    delete this->tutorial_view;
    this->tutorial_view = new TutorialView(this);
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x=(screenGeometry.width()-home_view->width())/2;
    int y=(screenGeometry.height()-home_view->height())/2;
    move(QPoint(x,y));
    setMinimumSize(820,600);
    this->tutorial_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout->addWidget(this->tutorial_view);
    this->tutorial_view->show();
    connect(this->tutorial_view, &TutorialView::toHomeView, this, &MainWindow::viewShowHomeView);
}

void MainWindow::viewShowSimulationView()
{
    this->hideCurrentView();
    delete this->simulation_view;
    this->simulation_view = new SimulationView(this);
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x=(screenGeometry.width()-home_view->width())/2;
    int y=(screenGeometry.height()-home_view->height())/2;
    move(QPoint(x,y));
    setMinimumSize(1120, 600);
    this->simulation_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout->addWidget(this->simulation_view);
    this->simulation_view->show();
    connect(this->simulation_view, &SimulationView::toHomeView, this, &MainWindow::viewShowHomeView);
}

void MainWindow::viewShowDBEditorView()
{
    this->hideCurrentView();
    delete this->dbEditor_view;
    this->dbEditor_view = new DBEditorView(this);
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x=(screenGeometry.width()-home_view->width())/2;
    int y=(screenGeometry.height()-home_view->height())/2;
    move(QPoint(x,y));
    setMinimumSize(620,520);
    this->dbEditor_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout->addWidget(this->dbEditor_view);
    this->dbEditor_view->show();
    connect(this->dbEditor_view, &DBEditorView::toHomeView, this, &MainWindow::viewShowHomeView);
}