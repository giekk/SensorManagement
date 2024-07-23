#include "buildSensorDialog.h"

BuildsensorDialog::BuildsensorDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle("Seleziona mese e anno");
    setMinimumSize(300, 200);

    this->month = new QComboBox(this);
    this->year = new QComboBox(this);

    this->okButton = new QPushButton(tr("OK"), this);
    this->cancelButton = new QPushButton(tr("Annulla"), this);

    for (int i = 1; i <= 12; i++)
        this->month->addItem(QString::number(i));

    for (int i = 2021; i <= 2024; i++)
        this->year->addItem(QString::number(i));

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Mese:"), this->month);
    layout->addRow(tr("Anno:"), this->year);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(this->okButton);
    buttonLayout->addWidget(this->cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(buttonLayout);

    connect(this->okButton, &QPushButton::clicked, this, &BuildsensorDialog::accept);
    connect(this->cancelButton, &QPushButton::clicked, this, &BuildsensorDialog::reject);
}

int BuildsensorDialog::getMonth() const
{
    return this->month->currentText().toInt();
}

int BuildsensorDialog::getYear() const
{
    return this->year->currentText().toInt();
}