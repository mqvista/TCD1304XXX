#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QThread>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "userinterfacemodule.h"
#include "senser01worker.h"

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
    UserInterfaceModule m_UserInterfaceModule;
};

#endif // SERVICE_H
