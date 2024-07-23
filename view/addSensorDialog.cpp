#include "addSensorDialog.h"

AddSensorDialog::AddSensorDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Aggiungi sensore");
    setMinimumSize(300, 200);

    this->nameEdit = new QLineEdit(this);
    this->IDEdit = new QLineEdit(this);
    this->typeEdit = new QComboBox(this);

    this->okButton = new QPushButton(tr("OK"), this);
    this->cancelButton = new QPushButton(tr("Annulla"), this);

    this->typeEdit->addItem("Temperatura");
    this->typeEdit->addItem("Umidità");
    this->typeEdit->addItem("Micropolveri");

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Nome:"), this->nameEdit);
    layout->addRow(tr("ID:"), this->IDEdit);
    layout->addRow(tr("Tipo:"), this->typeEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(this->okButton);
    buttonLayout->addWidget(this->cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(buttonLayout);

    connect(this->okButton, &QPushButton::clicked, this, &AddSensorDialog::accept);
    connect(this->cancelButton, &QPushButton::clicked, this, &AddSensorDialog::reject);
}

void AddSensorDialog::setInfo(const QString &name, const QString &id)
{
    this->nameEdit->setText(name);
    this->IDEdit->setText(id);
}

QString AddSensorDialog::getName() const
{
    return this->nameEdit->text();
}

QString AddSensorDialog::getID() const
{
    return this->IDEdit->text();
}

QString AddSensorDialog::getType() const
{
    return this->typeEdit->currentText();
}