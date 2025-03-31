#ifndef DBEDITOR_H
#define DBEDITOR_H

#include "dataManagement.h"

class DBEditor : public DataManagement
{
private:
    QStringList list;
    QStringList listToReturn;
    
public:
    explicit DBEditor(const QDate& date);

    void updateList(const QDate& date);
    void createList(const QString& day, const QString& temperature, const QString& humidity, const QString& microdust);
    void save();
    QStringList& getList();
    QStringList& getListToReturn();
};

#endif