#include "dbEditorView.h"

DBEditorView::DBEditorView(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    this->setMinimumSize(600,500);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->home_button = new QPushButton();

    //creo barra superiore
    QLabel* titleBar = new QLabel();
    titleBar->setText("Database Editor");
    titleBar->setFont(QFont("Arial", 20, QFont::Bold));
    QWidget* topbar = new TopBar(this->home_button, titleBar, QPixmap(QCoreApplication::applicationDirPath() + "/img/home_icon.png"));

    QPushButton* save = new QPushButton();
    QPushButton* add = new QPushButton();
   
    QCalendarWidget* calendar = new QCalendarWidget(this);
    calendar->setMinimumSize(200, 200);
    calendar->setMaximumSize(400, 400);

    QHBoxLayout* calendar_layout = new QHBoxLayout();
    calendar_layout->addStretch();
    calendar_layout->addWidget(calendar);
    calendar_layout->addStretch();

    this->temperature = new QLineEdit();
    this->humidity = new QLineEdit();
    this->microdust = new QLineEdit();

    QFormLayout* form = new QFormLayout();
    QLabel* temp_label = new QLabel();
    temp_label->setText("<b>" + tr("Temperatura (°C):") + "</b>");
    QLabel* hum_label = new QLabel();
    hum_label->setText("<b>" + tr("Umidità (%):") + "</b>");
    QLabel* micro_label = new QLabel();
    micro_label->setText("<b>" + tr("Micropolveri (%):") + "</b>");
    form->addRow(temp_label, this->temperature);
    form->addRow(hum_label, this->humidity);
    form->addRow(micro_label, this->microdust);

    QHBoxLayout* form_layout = new QHBoxLayout();
    form_layout->addStretch();
    form_layout->addLayout(form);
    form_layout->addStretch();

    this->model = new DBEditor(calendar->selectedDate());
    QStringList& list = this->model->getList();
    
    this->setLineEdit(list, this->temperature, this->humidity, this->microdust);

    this->buttonStyle(add, save);
    QHBoxLayout* add_button_layout = new QHBoxLayout();
    add_button_layout->addStretch();
    add_button_layout->addWidget(add);
    add_button_layout->addStretch();
    QHBoxLayout* save_button_layout = new QHBoxLayout();
    save_button_layout->addStretch();
    save_button_layout->addWidget(save);
    save_button_layout->addStretch();

    main_layout->addWidget(topbar);
    main_layout->addStretch();
    main_layout->addLayout(calendar_layout);
    main_layout->addLayout(form_layout);
    main_layout->addLayout(add_button_layout);
    main_layout->addLayout(save_button_layout);
    main_layout->addStretch();

    connect(this->home_button, &QPushButton::clicked, this, &DBEditorView::showHomeView);
    connect(add, &QPushButton::clicked, this, [this, calendar](){ this->addData(calendar); });
    connect(save, &QPushButton::clicked, this, &DBEditorView::saveData);
    connect(calendar, &QCalendarWidget::selectionChanged, this, [this, calendar]()
    {
        this->model->updateList(calendar->selectedDate());
        QStringList& list = this->model->getList();
        this->setLineEdit(list, this->temperature, this->humidity, this->microdust);
    });
}

DBEditorView::~DBEditorView()
{
    delete this->home_button;
    this->home_button = nullptr;
    delete this->model;
    this->model = nullptr;
    delete this->temperature;
    this->temperature = nullptr;
    delete this->humidity;
    this->humidity = nullptr;
    delete this->microdust;
    this->microdust = nullptr;
}



void DBEditorView::setLineEdit(const QStringList& list, QLineEdit* temperature, QLineEdit* humidity, QLineEdit* microdust)
{
    
    if (temperature->text() != "") temperature->clear();
    if (humidity->text() != "") humidity->clear();
    if (microdust->text() != "") microdust->clear();
    
    temperature->setPlaceholderText("Inserisci la temperatura");
    humidity->setPlaceholderText("Inserisci l'umidità");
    microdust->setPlaceholderText("Inserisci le micropolveri");
    
    if (!list.isEmpty()) 
    {
        if (list.size() >= 3)
        {
            temperature->setText(list.at(0));
            humidity->setText(list.at(1));
            microdust->setText(list.at(2));
        }
    }
}

void DBEditorView::buttonStyle(QPushButton* button, QPushButton* button2)
{
    button->setText("Aggiungi");
    button2->setText("Salva");
    button->setMaximumWidth(60);
    button->setStyleSheet("QPushButton { background-color: #52ff5b; }");
    button->setCursor(Qt::PointingHandCursor);
    button2->setMaximumWidth(50);
    button2->setStyleSheet("QPushButton { background-color: #acaaaa; }");
    button2->setCursor(Qt::PointingHandCursor);
}

void DBEditorView::addData(QCalendarWidget* calendar)
{
    this->model->createList(calendar->selectedDate().toString("dd/MM/yyyy"), this->temperature->text(), this->humidity->text(), this->microdust->text());
    QStringList& list = this->model->getListToReturn();
    if (!this->model->checkDataInsertion(list))
    {
        QMessageBox::warning(this, "Errore", "Errore nell'inserimento del dato!");
        return;
    }
    QMessageBox::information(this, "Successo", "Dati inseriti correttamente!");
}

void DBEditorView::saveData()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Salva", "Sei sicuro di voler salvare i dati inseriti?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) 
    {
        this->model->save();
    } 
    else 
    {
        return;
    }
}

void DBEditorView::showHomeView()
{
    emit toHomeView();
}