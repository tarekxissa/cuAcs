#-------------------------------------------------
#
# Project created by QtCreator 2019-01-24T15:59:00
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP3004
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QTCUACS_ROOT=\\\"$$_PRO_FILE_PWD_\\\"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
    animal.cpp \
    animalcareshelter.cpp \
    bird.cpp \
    mammal.cpp \
    server.cpp \
    client.cpp \
    reptile.cpp \
    fish.cpp \
    amphibian.cpp \
    mainwindow.cpp \
    storagecenter.cpp \
    match.cpp \
    matchcombinations.cpp \
    matchidcombination.cpp \
    compatibility.cpp \
    acm.cpp

HEADERS += \
        mainwindow.h \
    linkedlist.h \
    animal.h \
    animalcareshelter.h \
    bird.h \
    mammal.h \
    animalheaders.h \
    server.h \
    client.h \
    reptile.h \
    fish.h \
    amphibian.h \
    storagecenter.h \
    match.h \
    matchcombinations.h \
    matchidcombination.h \
    compatibility.h \
    acm.h \
    acmlibrary.h

FORMS += \
        mainwindow.ui
