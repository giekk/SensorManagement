#include "dbEditor.h"

DBEditor::DBEditor(const QDate& date)
{
    this->list = this->getDataDay(date);
}

void DBEditor::updateList(const QDate& date)
{
    this->list.clear();
    this->list = this->getDataDay(date);
}

void DBEditor::createList(const QString& day, const QString& temperature, const QString& humidity, const QString& microdust)
{
    if (!this->listToReturn.isEmpty()) this->listToReturn.clear();
    if (day == "") return;
    else this->listToReturn.append(day);
    if (temperature == "") this->listToReturn.append("0");
    else listToReturn.append(temperature);
    if (humidity == "") this->listToReturn.append("0");
    else listToReturn.append(humidity);
    if (microdust == "") this->listToReturn.append("0");
    else listToReturn.append(microdust);
    this->insertDataDay(this->listToReturn);
}

void DBEditor::save() 
{
    this->saveData();
}

QStringList& DBEditor::getList() 
{
    return this->list;
}

QStringList& DBEditor::getListToReturn() 
{
    return this->listToReturn;
}