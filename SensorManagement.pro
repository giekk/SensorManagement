QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += widgets gui core
QT += charts 

SOURCES += \
    model/sensor.cpp \
    model/temperature.cpp \
    model/humidity.cpp \
    model/microdust.cpp \
    model/sensorDataVisitor.cpp \
    view/sensorInfoVisitor.cpp \
    view/sensorInfo.cpp \
    view/sensorPanel.cpp \
    view/temperaturePanel.cpp \
    view/humidityPanel.cpp \
    view/microdustPanel.cpp \
    view/sensorInfoDialog.cpp \
    view/addSensorDialog.cpp \
    view/buildSensorDialog.cpp \
    view/simulationView.cpp \
    main.cpp \
    view/homeView.cpp \
    view/topbar.cpp \
    view/tutorialView.cpp \
    db/data.cpp \
    db/sensorData.cpp \
    db/database.cpp \
    model/dataManagement.cpp \
    model/dbEditor.cpp \
    model/dataChart.cpp \
    model/sensorColumn.cpp \
    model/setSensorVisitor.cpp \
    view/createSensorPanelVisitor.cpp \
    model/sensorFactory.cpp \
    view/sensorColumnView.cpp \
    view/dataChartView.cpp \
    view/dbEditorView.cpp \
    ctrl.cpp \
    mainwindow.cpp

HEADERS += \
    model/IVisitor.h \
    model/sensor.h \
    model/temperature.h \
    model/humidity.h \
    model/microdust.h \
    model/sensorDataVisitor.h \
    view/sensorInfoVisitor.h \
    view/sensorInfo.h \
    view/sensorPanel.h \
    view/temperaturePanel.h \
    view/humidityPanel.h \
    view/microdustPanel.h \
    view/sensorInfoDialog.h \
    view/addSensorDialog.h \
    view/buildSensorDialog.h \
    view/simulationView.h \
    view/homeView.h \
    view/topbar.h \
    view/tutorialView.h \
    db/data.h \
    db/sensorData.h \
    db/database.h \
    model/dataManagement.h \
    model/dbEditor.h \
    model/dataChart.h \
    model/sensorColumn.h \
    model/setSensorVisitor.h \
    view/createSensorPanelVisitor.h \
    model/sensorFactory.h \
    view/sensorColumnView.h \
    view/dataChartView.h \
    view/dbEditorView.h \
    ctrl.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
