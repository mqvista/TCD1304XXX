#include "service.h"

Service::Service(QQmlApplicationEngine *appEng, QObject *parent) : QObject(parent)
{
    m_Engine = appEng;
    m_Senser01Worker.moveToThread(&m_Senser01Thread);
    m_Senser01Thread.start();

    initContext();
}

Service::~Service()
{
    m_Senser01Thread.quit();
    m_Senser01Thread.wait();
}

void Service::initContext()
{
    //Q_DECLARE_METATYPE(m_UserInterfaceModule)
    m_Engine->rootContext()->setContextProperty("UserInterfaceModule", &m_UserInterfaceModule);
}
