#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "tcd1304xxx.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTimer timer = new QTimer(this);
    //QObject::connect(timer, &QTimer::timeout, this, )


    double length;
    TCD1304XXX tcd;
    qDebug() << tcd.OpenDevice(0);
    qDebug() << tcd.SetIntergral(6);
    //tcd.setRawDataFilterFlag(true);
    tcd.setPloyDataFilterFlag(true);


    qDebug() << tcd.GetPolyData(&length);
    qDebug() << "length" << length;
    while (1)
    {
        if(tcd.GetPolyData(&length))
            qDebug() << false;
        qDebug() << "length" << length;
    }


    tcd.CloseDevice();
    return a.exec();
}
