#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T13:57:01
#
#-------------------------------------------------

QT       -= gui

TARGET = TCD1304XXX
TEMPLATE = lib

DEFINES += TCD1304XXX_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        tcd1304xxx.cpp \
    ployfit.cpp \
    ftdriver.cpp \
    filter.cpp

HEADERS += \
        tcd1304xxx.h \
        tcd1304xxx_global.h \ 
    ployfit.h \
    ftdriver.h \
    filter.h \
    windowfilter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# include FTDI D2XX library file
# for macOS
macx: LIBS += -L$$PWD/D2XX/mac/ -lftd2xx.1.4.4
# for windows
contains(QT_ARCH, i386) {
    message("32-bit")
    LIBS += -L$$PWD/D2XX/win32/ -lftd2xx
}else {
    message("64-bit")
    LIBS += -L$$PWD/D2XX/win64/ -lftd2xx
}

INCLUDEPATH += $$PWD/D2XX/include/
DEPENDPATH += $$PWD/D2XX/include/


# include for GNU Scientific Library
macx: LIBS += -L$$PWD/GSL/mac/lib/ -lgsl.23
macx: LIBS += -L$$PWD/GSL/mac/lib/ -lgslcblas
win32: LIBS += -L$$PWD/GSL/win/lib/ -llibgsl
win32: LIBS += -L$$PWD/GSL/win/lib/ -llibgslcblas

INCLUDEPATH += $$PWD/GSL/include/
DEPENDPATH += $$PWD/GSL/include/
