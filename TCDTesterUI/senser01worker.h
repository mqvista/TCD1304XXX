#ifndef SENSER01WORKER_H
#define SENSER01WORKER_H

#include <QObject>
#include <QDebug>
#include "tcd1304xxx.h"

class Senser01Worker : public QObject
{
    Q_OBJECT
public:
    explicit Senser01Worker(QObject *parent = nullptr);
    Q_INVOKABLE void openDevice(const quint8 devNum);
    Q_INVOKABLE void getSenserList();
    Q_INVOKABLE void setIntergral(const quint8 value);
    Q_INVOKABLE void getPolyData(double* pixels);
    Q_INVOKABLE void setSenserMask(quint16 maskLength, quint16 maskValue);


private:
    TCD1304XXX m_tcd1304xxx;

signals:
    void sendSenser01DeviceList(QList<QString> devList);

public slots:
};

#endif // SENSER01WORKER_H
