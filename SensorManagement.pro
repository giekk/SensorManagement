QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += widgets gui core
QT += charts 

SOURCES += \
    sensor.cpp \
    temperature.cpp \
    humidity.cpp \
    microdust.cpp \
    sensorDataVisitor.cpp \
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
    data.cpp \
    sensorData.cpp \
    database.cpp \
    dataManagement.cpp \
    dbEditor.cpp \
    dataChart.cpp \
    sensorColumn.cpp \
    setSensorVisitor.cpp \
    view/createSensorPanelVisitor.cpp \
    sensorFactory.cpp \
    view/sensorColumnView.cpp \
    view/dataChartView.cpp \
    view/dbEditorView.cpp \
    ctrl.cpp \
    mainwindow.cpp

HEADERS += \
    IVisitor.h \
    sensor.h \
    temperature.h \
    humidity.h \
    microdust.h \
    sensorDataVisitor.h \
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
    data.h \
    sensorData.h \
    database.h \
    dataManagement.h \
    dbEditor.h \
    dataChart.h \
    sensorColumn.h \
    setSensorVisitor.h \
    view/createSensorPanelVisitor.h \
    sensorFactory.h \
    view/sensorColumnView.h \
    view/dataChartView.h \
    view/dbEditorView.h \
    ctrl.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
