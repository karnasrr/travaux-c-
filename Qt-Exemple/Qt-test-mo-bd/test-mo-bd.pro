QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-mo-bd
TEMPLATE = app

SOURCES += main.cpp \
    basededonnees.cpp

HEADERS  += basededonnees.h

unix:!macx:
{
    !android:
    {
        # copie la base de données dans le dossier build
        CONFIG += file_copies
        COPIES += bd
        bd.files = bd-sqlite.sqlite
        bd.path = $$OUT_PWD/
        bd.base = $$PWD/
    }
}
