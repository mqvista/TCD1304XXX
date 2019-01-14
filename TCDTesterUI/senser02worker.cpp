#include "senser02worker.h"

Senser02Worker::Senser02Worker()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Senser02Worker::getPolyData);
    m_maxCostTime = 0;
}

void Senser02Worker::openDevice(const quint8 devNum)
{
    if (m_tcd1304xxx.OpenDevice(devNum))
    {
        m_tcd1304xxx.setMaskPixel(5, 48000);
        emit sendSenserOpened();
        timer->start(100);
    }
}

void Senser02Worker::closeDevice()
{
    timer->stop();
    m_tcd1304xxx.CloseDevice();
}

void Senser02Worker::getSenserList()
{
    QList<QString> devList;
    m_tcd1304xxx.GetDeviceListSerialNum(&devList);
    emit sendSenserDeviceList(devList);
}

void Senser02Worker::setIntergral(const quint8 value)
{
    m_tcd1304xxx.SetIntergral(value);
}

void Senser02Worker::getPolyData()
{
    m_startTime = QDateTime::currentDateTime();
    if (!m_tcd1304xxx.GetPolyData(&m_pixelLength))
    {
        m_errorCount++;
        emit sendErrorTimes(m_errorCount);
    }
    m_stopTime = QDateTime::currentDateTime();
    m_costTime = m_startTime.msecsTo(m_stopTime);
    if (m_maxCostTime < m_costTime)
    {
        m_maxCostTime = m_costTime;
        emit sendMaxCostTime(m_maxCostTime);
    }
    emit sendPixelLength(m_pixelLength);
    emit sendCostTime(m_costTime);
}
