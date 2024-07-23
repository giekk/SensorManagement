// sensorInfoDialog.cpp
#include "sensorInfoDialog.h"

SensorInfoDialog::SensorInfoDialog(QWidget *parent) : QDialog(parent) 
{
    setWindowTitle("Modifica dati sensore");
    setMinimumSize(300, 100);
    this->nameEdit = new QLineEdit(this);

    this->okButton = new QPushButton(tr("OK"), this);
    this->cancelButton = new QPushButton(tr("Annulla"), this);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Nome:"), this->nameEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(this->okButton);
    buttonLayout->addWidget(this->cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(buttonLayout);

    connect(this->okButton, &QPushButton::clicked, this, &SensorInfoDialog::accept);
    connect(this->cancelButton, &QPushButton::clicked, this, &SensorInfoDialog::reject);
}

void SensorInfoDialog::setInfo(const QString &name) 
{
    this->nameEdit->setText(name);
}

QString SensorInfoDialog::getName() const 
{
    return this->nameEdit->text();
}


