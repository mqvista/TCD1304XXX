#include "usermodule.h"

UserModule::UserModule(QObject *parent) : QObject(parent)
{

}

void UserModule::InitPointer(Senser01Worker *target01,Senser02Worker *target02,  QQmlApplicationEngine* target03)
{
    m_SenserWorker01 = target01;
    m_SenserWorker02 = target02;
    m_Engine = target03;
}

void UserModule::getSenser01List()
{
    QMetaObject::invokeMethod(m_SenserWorker01, "getSenserList", Qt::QueuedConnection);
}

void UserModule::openSenser01(quint8 num)
{
    QMetaObject::invokeMethod(m_SenserWorker01, "openDevice", Qt::QueuedConnection, Q_ARG(quint8, num));
}

void UserModule::closeSenser01()
{
    QMetaObject::invokeMethod(m_SenserWorker01, "closeDevice", Qt::QueuedConnection);
    QObject * senser01Button = m_Engine->rootObjects()[0]->findChild<QObject *>("buttonOpenSenser01");
    if (senser01Button)
    {
        senser01Button->setProperty("text", "Open");
    }
}

void UserModule::setSenser01Intergral(quint8 num)
{
    QMetaObject::invokeMethod(m_SenserWorker01, "setIntergral", Qt::QueuedConnection, Q_ARG(quint8, num));
}

void UserModule::getSenser02List()
{
    QMetaObject::invokeMethod(m_SenserWorker02, "getSenserList", Qt::QueuedConnection);
}

void UserModule::openSenser02(quint8 num)
{
    QMetaObject::invokeMethod(m_SenserWorker02, "openDevice", Qt::QueuedConnection, Q_ARG(quint8, num));
}

void UserModule::closeSenser02()
{
    QMetaObject::invokeMethod(m_SenserWorker02, "closeDevice", Qt::QueuedConnection);
    QObject * senser02Button = m_Engine->rootObjects()[0]->findChild<QObject *>("buttonOpenSenser02");
    if (senser02Button)
    {
        senser02Button->setProperty("text", "Open");
    }
}

void UserModule::setSenser02Intergral(quint8 num)
{
    QMetaObject::invokeMethod(m_SenserWorker02, "setIntergral", Qt::QueuedConnection, Q_ARG(quint8, num));
}

QStringList UserModule::readSenser01List()
{
    return m_Senser01List;
}

QString UserModule::readSenser01PixelLength()
{
    return m_Senser01PixelLength;
}

QString UserModule::readSenser01CostTime()
{
    return m_Senser01CostTime;
}

QString UserModule::readSenser01MaxCostTime()
{
    return m_Senser01MaxCostTime;
}

QString UserModule::readSenser01ErrorTimes()
{
    return m_Senser01ErrorTimes;
}

QStringList UserModule::readSenser02List()
{
    return m_Senser02List;
}

QString UserModule::readSenser02PixelLength()
{
    return m_Senser02PixelLength;
}

QString UserModule::readSenser02CostTime()
{
    return m_Senser02CostTime;
}

QString UserModule::readSenser02MaxCostTime()
{
    return m_Senser02MaxCostTime;
}

QString UserModule::readSenser02ErrorTimes()
{
    return m_Senser02ErrorTimes;
}


void UserModule::getSenser01DeviceList(QList<QString> devList)
{
    m_Senser01List.clear();
    foreach (QString serial, devList) {
        m_Senser01List.append(serial);
    }
    emit senser01ListChanged();
}

void UserModule::getSenser01Opened()
{
    QObject * senser01Button = m_Engine->rootObjects()[0]->findChild<QObject *>("buttonOpenSenser01");
    if (senser01Button)
    {
        senser01Button->setProperty("text", "Close");
    }
}

void UserModule::getSenser01PixelLength(double length)
{
    m_Senser01PixelLength = QString::number(length, 'f', 1);
    emit senser01PixelLengthChanged();
}

void UserModule::getSenser01CostTime(qint64 time)
{
    m_Senser01CostTime = QString::number(time);
    emit senser01CostTimeChanged();
}

void UserModule::getSenser01MaxCostTime(qint64 time)
{
    m_Senser01MaxCostTime = QString::number(time);
    emit senser01MaxCostTimeChanged();
}

void UserModule::getSenser01ErrorTimes(quint64 times)
{
    m_Senser01ErrorTimes = QString::number(times);
    emit senser01ErrorTimesChanged();
}

void UserModule::getSenser02DeviceList(QList<QString> devList)
{
    m_Senser02List.clear();
    foreach (QString serial, devList) {
        m_Senser02List.append(serial);
    }
    emit senser02ListChanged();
}

void UserModule::getSenser02Opened()
{
    QObject * senser02Button = m_Engine->rootObjects()[0]->findChild<QObject *>("buttonOpenSenser02");
    if (senser02Button)
    {
        senser02Button->setProperty("text", "Close");
    }
}

void UserModule::getSenser02PixelLength(double length)
{
    m_Senser02PixelLength = QString::number(length, 'f', 1);
    emit senser02PixelLengthChanged();
}

void UserModule::getSenser02CostTime(qint64 time)
{
    m_Senser02CostTime = QString::number(time);
    emit senser02CostTimeChanged();
}

void UserModule::getSenser02MaxCostTime(qint64 time)
{
    m_Senser02MaxCostTime = QString::number(time);
    emit senser02MaxCostTimeChanged();
}

void UserModule::getSenser02ErrorTimes(quint64 times)
{
    m_Senser02ErrorTimes = QString::number(times);
    emit senser02ErrorTimesChanged();
}
