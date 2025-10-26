#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>


void basics()
{
    QFile file("test.txt");
    if(!file.open(QIODevice::ReadWrite))
    {
        qCritical() << "Could not open file:";
        qCritical() << file.errorString();
        return;
    }

    qInfo() << "Writing file...";
    file.write(QByteArray("Hello world"));
    file.flush();

    qInfo() << "Reading file...";
    file.seek(0);
    qInfo() << file.readAll();

    file.close();
}

bool writeFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {

        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    for(int i = 0;i<5;i++)
    {
        stream << QString::number(i)<< "Hello world \r\n";
    }

    file.close();
    return true;
}

void readFile(QString filename)
{
    QFile file(filename);

    if(!file.exists())
    {

        qCritical() << "file not found";
        return ;
    }


    if(!file.open(QIODevice::ReadOnly))
    {

        qCritical() << file.errorString();
        return ;
    }

    QTextStream stream(&file);

    //QString data=stream.readAll();

    while (!stream.atEnd()){
        QString line = stream.readLine();
        qInfo()<<line;
    }

    file.close();


}

int main(int argc, char *argv[])
{

    //extract from youtube
    //Qt 6 - Episode 19 - Read and writing text files

    QApplication a(argc, argv);

    //basics();

    writeFile("test.text");

    readFile("ttt.text");

    MainWindow w;
    w.show();
    return a.exec();

}
