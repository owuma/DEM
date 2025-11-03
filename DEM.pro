QT       += core gui
# Включаем необходимые модули Qt
QT += widgets printsupport

# Добавляем файлы QCustomPlot
SOURCES += \
    qcustomplot.cpp

HEADERS += \
    qcustomplot.h

# Добавляем в пути для заголовков стандартные пути GDAL
INCLUDEPATH += /usr/include/gdal

# Линковка с библиотекой GDAL (флаг -lgdal)
LIBS += -lgdal

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
