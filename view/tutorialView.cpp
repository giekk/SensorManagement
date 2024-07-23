#include "tutorialView.h"

TutorialView::TutorialView(QWidget* parent) : QWidget(parent)
{
    this->setMinimumSize(800,600);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->main_layout = new QVBoxLayout(this);
    this->main_layout->setAlignment(Qt::AlignCenter);
    this->home_button = new QPushButton();

    //creo barra superiore
    QLabel* titleBar = new QLabel();
    titleBar->setText("Tutorial");
    titleBar->setFont(QFont("Arial", 20, QFont::Bold));
    QWidget* topbar = new TopBar(this->home_button, titleBar, QPixmap(QCoreApplication::applicationDirPath() + "/img/home_icon.png"));

    
    QPixmap image(QCoreApplication::applicationDirPath() + "/img/screen_simulatore.png");   
    image = image.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* image_label = new QLabel();
    image_label->setPixmap(image);
    QLabel* image_title = new QLabel();
    image_title->setText("Schermata del simulatore:");
    image_title->setFont(QFont("Arial", 15, QFont::Bold));
    image_title->setAlignment(Qt::AlignCenter);

    QLabel* title = new QLabel();
    title->setText("Descrizione dell'applicazione:\n");
    title->setFont(QFont("Arial", 15, QFont::Bold));
    title->setAlignment(Qt::AlignCenter);

    QLabel* description = new QLabel();
    this->setDescription(description);

    this->main_layout->addWidget(topbar);
    QVBoxLayout* layout = new QVBoxLayout();
    QHBoxLayout* image_title_layout = new QHBoxLayout();
    image_title_layout->addStretch();
    image_title_layout->addWidget(image_title);
    image_title_layout->addStretch();
    QHBoxLayout* image_layout = new QHBoxLayout();
    image_layout->addStretch();
    image_layout->addWidget(image_label);
    image_layout->addStretch();
    layout->addLayout(image_title_layout);
    layout->addLayout(image_layout);
    layout->addStretch();
    layout->addWidget(title);
    QHBoxLayout* description_layout = new QHBoxLayout();
    description_layout->addStretch();
    description_layout->addWidget(description);
    description_layout->addStretch();
    layout->addLayout(description_layout);

    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* container = new QWidget();
    container->setLayout(layout);
    container->adjustSize();
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->main_layout->addWidget(scrollArea);

    connect(home_button, &QPushButton::pressed, this, &TutorialView::showHomeView);
}

TutorialView::~TutorialView()
{
    delete this->main_layout;
    this->main_layout = nullptr;
    delete this->home_button;
    this->home_button = nullptr;
}

void TutorialView::setDescription(QLabel* description)
{
    description->setText("\nQuesta applicazione è un sistema di gestione di dati atmosferici.\n"
    "Si tratta di un'applicazione per la gestione di sensori meteo, che permette di visualizzare i dati raccolti dai sensori e di effettuare delle simulazioni.\n"
    "L'applicazione permette di creare e di rimuovere sensori e di visualizzare i dati meteorologici raccolti ogni anno.\n"
    "Nel simulatore si possono creare tre tipologie di sensori: temperatura, umidità e micropolveri.\n"
    "Ogni sensore avrà 4 bottoni disponibili: uno per visualizzare i dati raccolti, uno per estrarre i dati necessari per effettuare una simulazione, uno per rimuovere il sensore e uno per modificare i dati del sensore.\n"
    "Una volta creati i sensori è possibile salvare i sensori e i relativi dati nel database.\n"
    "Per creare un sensore è necessario inserire un id univoco, mentre per effettuare una simulazione è necessario selezionare un sensore e inserire un dato mese da cui estrarre i dati necessari.\n"
    "I dati meteorologici estrapolati dai sensori per effettuare le simulazioni vengono visualizzati in un grafico.\n"
    "Il grafico mostra i dati di temperatura, umidità e micropolveri in un determinato mese dell'anno.\n"
    "E' possibile quindi visualizzare i dati di un mese specifico selezionando il mese e l'anno desiderato dal menu a tendina.\n"
    "Vi è inoltre la possibilità di modificare il database, ovvero di aggiungere o rimuovere dati dei vari mesi dell'anno.\n");
    description->setFont(QFont("Arial", 12));
    description->setWordWrap(true);
    description->setStyleSheet("border: 3px solid #d0d0d0;  background-color: white;");
    description->setAlignment(Qt::AlignCenter);
    description->setFixedWidth(600);
}

void TutorialView::showHomeView()
{
    emit toHomeView();
}