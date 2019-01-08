#include "senser01worker.h"

Senser01Worker::Senser01Worker(QObject *parent) : QObject(parent)
{

}

void Senser01Worker::openDevice(const quint8 devNum)
{
    m_tcd1304xxx.OpenDevice(devNum);
}

void Senser01Worker::getSenserList()
{
    QList<QString> devList;
    m_tcd1304xxx.GetDeviceListSerialNum(&devList);
    qDebug()<< devList;
    emit sendSenser01DeviceList(devList);
}

void Senser01Worker::setIntergral(const quint8 value)
{

}

void Senser01Worker::getPolyData(double *pixels)
{

}

void Senser01Worker::setSenserMask(quint16 maskLength, quint16 maskValue)
{

}
