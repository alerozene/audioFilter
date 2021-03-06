QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    detailview.cpp \
    filter.cpp \
    gaussnoise.cpp \
    main.cpp \
    options_filterwindow.cpp \
    plotter.cpp \
    qcustomplot.cpp \
    startingWindow.cpp \
    wavfile.cpp

HEADERS += \
    detailview.h \
    filter.h \
    gaussnoise.h \
    options_filterwindow.h \
    plotter.h \
    qcustomplot.h \
    startingWindow.h \
    vecutils.h \
    wavfile.h

FORMS += \
    detailview.ui \
    options_filterwindow.ui \
    plotter.ui \
    startingWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    modeltest1.qmodel
