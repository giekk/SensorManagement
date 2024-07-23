#ifndef DBEDITORVIEW_H
#define DBEDITORVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QCalendarWidget>
#include <QLabel>

#include "dbEditor.h"
#include "topbar.h"

class DBEditorView : public QWidget
{
    Q_OBJECT

private:
    DBEditor* model;
    QPushButton* home_button;
    QLineEdit* temperature;
    QLineEdit* humidity;
    QLineEdit* microdust;

public:
    explicit DBEditorView(QWidget* parent = nullptr);
    ~DBEditorView();
    
    static void setLineEdit(const QStringList& list, QLineEdit* lineEdit1, QLineEdit* lineEdit2, QLineEdit* lineEdit3); 
    static void buttonStyle(QPushButton* button, QPushButton* button2);

signals:
    void toHomeView();

public slots:
    void addData(QCalendarWidget* calendar);
    void saveData();
    void showHomeView();
};

#endif
