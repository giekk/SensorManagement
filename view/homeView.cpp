#include "homeView.h"

HomeView::HomeView(QWidget* parent) : QWidget(parent)
{
    this->setMinimumSize(700, 400);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout = new QVBoxLayout(this);
    this->main_layout->setAlignment(Qt::AlignCenter);

    //creo i bottoni
    this->startSimulation = new QPushButton();
    this->tutorial = new QPushButton();
    this->editDB = new QPushButton();

    QPixmap startSimulationIcon = QPixmap(QCoreApplication::applicationDirPath() + "/img/sensor_icon.png");
    QPixmap tutorialIcon = QPixmap(QCoreApplication::applicationDirPath() + "/img/tutorial_icon.png");
    QPixmap editDBIcon = QPixmap(QCoreApplication::applicationDirPath() + "/img/editDB_icon.png");

    this->setButtonIcon(startSimulationIcon, this->startSimulation);
    this->setButtonIcon(tutorialIcon, this->tutorial);
    this->setButtonIcon(editDBIcon, this->editDB);

    //creo layout opzioni
    QLabel* startSimulationLabel = new QLabel();
    QLabel* tutorialLabel = new QLabel();
    QLabel* editDBLabel = new QLabel();

    this->buttonLabelLayout(tutorialLabel, startSimulationLabel, editDBLabel);
    
    QLayout* startButtonLayout = this->setButtonLayout(this->startSimulation, startSimulationLabel);
    QLayout* tutorialButtonLayout = this->setButtonLayout(this->tutorial, tutorialLabel);
    QLayout* editDBButtonLayout = this->setButtonLayout(this->editDB, editDBLabel);

    QHBoxLayout* options_layout = new QHBoxLayout();
    options_layout->setAlignment(Qt::AlignCenter);
    options_layout->addLayout(startButtonLayout);
    options_layout->addLayout(tutorialButtonLayout);
    options_layout->addLayout(editDBButtonLayout);

    QLabel* title = new QLabel();
    this->titleLayout(title);

    QLabel* subtitle = new QLabel();
    subtitle->setText("Seleziona un'opzione:");
    subtitle->setAlignment(Qt::AlignCenter);
    subtitle->setFont(QFont("Arial", 15, QFont::Bold));
    subtitle->setStyleSheet("QLabel { color: #9b0000; }");

    this->main_layout->addWidget(title);
    this->main_layout->addStretch();
    this->main_layout->addWidget(subtitle);
    this->main_layout->setAlignment(subtitle, Qt::AlignCenter);
    this->main_layout->addLayout(options_layout);
    subtitle->setFixedWidth(options_layout->sizeHint().width()); //setta la larghezza del label in base al layout (che contiene i bottoni
    this->main_layout->addStretch();
   
    connect(startSimulation, &QPushButton::clicked, this, &HomeView::showSimulationView);
    connect(tutorial, &QPushButton::clicked, this, &HomeView::showTutorialView);
    connect(editDB, &QPushButton::clicked, this, &HomeView::showDBEditorView);
}

HomeView::~HomeView() 
{
    delete this->main_layout;
    this->main_layout = nullptr;
    delete this->startSimulation;
    this->startSimulation = nullptr;
    delete this->tutorial;
    this->tutorial = nullptr;
    delete this->editDB;
    this->editDB = nullptr;
}

void HomeView::setButtonIcon(const QPixmap& icon, QPushButton* button)
{
    button->setIcon(icon);
    button->setIconSize(QSize(BUTTON_ICON_WIDTH, BUTTON_ICON_HEIGHT));
    button->resize(QSize(BUTTON_ICON_WIDTH, BUTTON_ICON_HEIGHT));
    button->setStyleSheet("QPushButton { border: 3px solid #d0d0d0; border-radius: 10px; background-color: white; }");
    button->setAutoFillBackground(true);
    button->update();
    button->setCursor(Qt::PointingHandCursor);
}

QLayout* HomeView::setButtonLayout(QPushButton* button, QLabel* label) 
{
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->addWidget(label);
    layout->setAlignment(Qt::AlignCenter);
    return layout;
}

void HomeView::titleLayout(QLabel* title)
{
    title->setText("SENSOR MANAGEMENT");
    title->setAlignment(Qt::AlignCenter);
    title->setFont(QFont("Arial", 30, QFont::Bold));
    title->setStyleSheet("QLabel { border: 5px solid #d0d0d0; border-radius: 10px; background-color: #acaaaa; color: white; }");
}

void HomeView::buttonLabelLayout(QLabel* label1, QLabel* label2, QLabel* label3)
{
    label1->setText("Tutorial");
    label1->setAlignment(Qt::AlignCenter);
    label1->setFont(QFont("Arial", 12, QFont::Bold));
    label1->setStyleSheet("QLabel { border: 3px solid #d0d0d0; border-radius: 5px; background-color: white; }");

    label2->setText("Simulatore");
    label2->setAlignment(Qt::AlignCenter);
    label2->setFont(QFont("Arial", 12, QFont::Bold));
    label2->setStyleSheet("QLabel { border: 3px solid #d0d0d0; border-radius: 5px; background-color: white; }");

    label3->setText("Database Editor");
    label3->setAlignment(Qt::AlignCenter);
    label3->setFont(QFont("Arial", 12, QFont::Bold));
    label3->setStyleSheet("QLabel { border: 3px solid #d0d0d0; border-radius: 5px; background-color: white; }");

}

void HomeView::showSimulationView()
{
    emit toSimulationView();
}

void HomeView::showTutorialView()
{
    emit toTutorialView();
}

void HomeView::showDBEditorView()
{
    emit toDBEditorView();
}

#if 0

void HomeView::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Sensor Management",
        tr("Sei sicuro di uscire dall'applicazione?"),
        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,   QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

#endif