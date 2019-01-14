#ifndef SENSER01WORKER_H
#define SENSER01WORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include "tcd1304xxx.h"

class Senser01Worker : public QObject
{
    Q_OBJECT
public:
    explicit Senser01Worker(QObject *parent = nullptr);
    Q_INVOKABLE void openDevice(const quint8 devNum);
    Q_INVOKABLE void closeDevice();
    Q_INVOKABLE void getSenserList();
    Q_INVOKABLE void setIntergral(const quint8 value);


private:
    TCD1304XXX m_tcd1304xxx;
    QTimer *timer;
    double m_pixelLength;
    QDateTime m_startTime, m_stopTime;
    qint64 m_costTime;
    qint64 m_maxCostTime;
    quint64 m_errorCount = 0;


signals:
    void sendSenserDeviceList(QList<QString> devList);
    void sendSenserOpened();
    void sendPixelLength(double length);
    void sendCostTime(qint64 time);
    void sendMaxCostTime(qint64 time);
    void sendErrorTimes(quint64 times);

public slots:
    void getPolyData();
};

#endif // SENSER01WORKER_H
