#ifndef USERMODULE_H
#define USERMODULE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "senser01worker.h"
#include "senser02worker.h"

class UserModule : public QObject
{
    Q_OBJECT
    // senser01
    Q_PROPERTY(QStringList senser01List READ readSenser01List NOTIFY senser01ListChanged)
    Q_PROPERTY(QString senser01PixelLength READ readSenser01PixelLength NOTIFY senser01PixelLengthChanged)
    Q_PROPERTY(QString senser01CostTime READ readSenser01CostTime NOTIFY senser01CostTimeChanged)
    Q_PROPERTY(QString senser01MaxCostTime READ readSenser01MaxCostTime NOTIFY senser01MaxCostTimeChanged)
    Q_PROPERTY(QString senser01ErrorTimes READ readSenser01ErrorTimes NOTIFY senser01ErrorTimesChanged)
    // senser02
    Q_PROPERTY(QStringList senser02List READ readSenser02List NOTIFY senser02ListChanged)
    Q_PROPERTY(QString senser02PixelLength READ readSenser02PixelLength NOTIFY senser02PixelLengthChanged)
    Q_PROPERTY(QString senser02CostTime READ readSenser02CostTime NOTIFY senser02CostTimeChanged)
    Q_PROPERTY(QString senser02MaxCostTime READ readSenser02MaxCostTime NOTIFY senser02MaxCostTimeChanged)
    Q_PROPERTY(QString senser02ErrorTimes READ readSenser02ErrorTimes NOTIFY senser02ErrorTimesChanged)

public:
    explicit UserModule(QObject *parent = nullptr);
    void InitPointer(Senser01Worker *target01,Senser02Worker *target02,  QQmlApplicationEngine* target03);
    //
    QStringList readSenser01List();
    QString readSenser01PixelLength();
    QString readSenser01CostTime();
    QString readSenser01MaxCostTime();
    QString readSenser01ErrorTimes();
    //
    QStringList readSenser02List();
    QString readSenser02PixelLength();
    QString readSenser02CostTime();
    QString readSenser02MaxCostTime();
    QString readSenser02ErrorTimes();


    // senser01
    Q_INVOKABLE void getSenser01List();
    Q_INVOKABLE void openSenser01(quint8 num);
    Q_INVOKABLE void closeSenser01();
    Q_INVOKABLE void setSenser01Intergral(quint8 num);
    // senser02
    Q_INVOKABLE void getSenser02List();
    Q_INVOKABLE void openSenser02(quint8 num);
    Q_INVOKABLE void closeSenser02();
    Q_INVOKABLE void setSenser02Intergral(quint8 num);


signals:
    // senser01
    void senser01ListChanged();
    void senser01PixelLengthChanged();
    void senser01CostTimeChanged();
    void senser01MaxCostTimeChanged();
    void senser01ErrorTimesChanged();
    // senser02
    void senser02ListChanged();
    void senser02PixelLengthChanged();
    void senser02CostTimeChanged();
    void senser02MaxCostTimeChanged();
    void senser02ErrorTimesChanged();

public slots:
    void getSenser01DeviceList(QList<QString> devList);
    void getSenser01Opened();
    void getSenser01PixelLength(double length);
    void getSenser01CostTime(qint64 time);
    void getSenser01MaxCostTime(qint64 time);
    void getSenser01ErrorTimes(quint64 times);

    void getSenser02DeviceList(QList<QString> devList);
    void getSenser02Opened();
    void getSenser02PixelLength(double length);
    void getSenser02CostTime(qint64 time);
    void getSenser02MaxCostTime(qint64 time);
    void getSenser02ErrorTimes(quint64 times);


private:
    QQmlApplicationEngine* m_Engine;
    // senser01
    Senser01Worker *m_SenserWorker01;
    QStringList m_Senser01List;
    QString m_Senser01PixelLength;
    QString m_Senser01CostTime;
    QString m_Senser01MaxCostTime;
    // senser02
    Senser02Worker *m_SenserWorker02;
    QStringList m_Senser02List;
    QString m_Senser02PixelLength;
    QString m_Senser02CostTime;
    QString m_Senser02MaxCostTime;
    QString m_Senser01ErrorTimes;
    QString m_Senser02ErrorTimes;

};

#endif // USERMODULE_H
