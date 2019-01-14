#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QThread>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "usermodule.h"
#include "senser01worker.h"
#include "senser02worker.h"

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QQmlApplicationEngine* appEng, QObject *parent = nullptr);
    ~Service();
    void initContext();

signals:

public slots:

private:
    QQmlApplicationEngine* m_Engine;
    Senser01Worker m_Senser01Worker;
    QThread m_Senser01Thread;
    Senser02Worker m_Senser02Worker;
    QThread m_Senser02Thread;
    UserModule m_UserMoudle;
};

#endif // SERVICE_H
