#ifndef ADDSENSORDIALOG_H
#define ADDSENSORDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>

class AddSensorDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit *nameEdit;
    QLineEdit *IDEdit;
    QComboBox *typeEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    
public:
    explicit AddSensorDialog(QWidget *parent = nullptr);

    void setInfo(const QString &name, const QString &id);
    QString getName() const;
    QString getID() const;
    QString getType() const;
};

#endif