#ifndef SENSORINFODIALOG_H
#define SENSORINFODIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class SensorInfoDialog : public QDialog 
{
    Q_OBJECT

private:
    QLineEdit *nameEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

public:
    explicit SensorInfoDialog(QWidget *parent = nullptr);

    void setInfo(const QString &name); 
    QString getName() const;
};

#endif 