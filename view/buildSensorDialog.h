#ifndef BUILDSENSORDIALOG_H
#define BUILDSENSORDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>

class BuildsensorDialog : public QDialog
{
    Q_OBJECT
private:
    QComboBox *month;
    QComboBox *year;
    QPushButton *okButton;
    QPushButton *cancelButton;
public:
    explicit BuildsensorDialog(QWidget* parent = nullptr);

    int getMonth() const;
    int getYear() const;
};

#endif