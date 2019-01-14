#include "service.h"

Service::Service(QQmlApplicationEngine *appEng, QObject *parent) : QObject(parent)
{
    m_Engine = appEng;
    m_Senser01Worker.moveToThread(&m_Senser01Thread);
    m_Senser01Thread.start();
    m_Senser02Worker.moveToThread(&m_Senser02Thread);
    m_Senser02Thread.start();
    initContext();
}

Service::~Service()
{
    m_Senser01Thread.quit();
    m_Senser01Thread.wait();
    m_Senser02Thread.quit();
    m_Senser02Thread.wait();
}

void Service::initContext()
{
    connect(&m_Senser01Worker, &Senser01Worker::sendSenserDeviceList, &m_UserMoudle, &UserModule::getSenser01DeviceList);
    connect(&m_Senser01Worker, &Senser01Worker::sendSenserOpened, &m_UserMoudle, &UserModule::getSenser01Opened);
    connect(&m_Senser01Worker, &Senser01Worker::sendPixelLength, &m_UserMoudle, &UserModule::getSenser01PixelLength);
    connect(&m_Senser01Worker, &Senser01Worker::sendCostTime, &m_UserMoudle, &UserModule::getSenser01CostTime);
    connect(&m_Senser01Worker, &Senser01Worker::sendMaxCostTime, &m_UserMoudle, &UserModule::getSenser01MaxCostTime);
    connect(&m_Senser01Worker, &Senser01Worker::sendErrorTimes, &m_UserMoudle, &UserModule::getSenser01ErrorTimes);

    connect(&m_Senser02Worker, &Senser02Worker::sendSenserDeviceList, &m_UserMoudle, &UserModule::getSenser02DeviceList);
    connect(&m_Senser02Worker, &Senser02Worker::sendSenserOpened, &m_UserMoudle, &UserModule::getSenser02Opened);
    connect(&m_Senser02Worker, &Senser02Worker::sendPixelLength, &m_UserMoudle, &UserModule::getSenser02PixelLength);
    connect(&m_Senser02Worker, &Senser02Worker::sendCostTime, &m_UserMoudle, &UserModule::getSenser02CostTime);
    connect(&m_Senser02Worker, &Senser02Worker::sendMaxCostTime, &m_UserMoudle, &UserModule::getSenser02MaxCostTime);
    connect(&m_Senser02Worker, &Senser02Worker::sendErrorTimes, &m_UserMoudle, &UserModule::getSenser02ErrorTimes);

    m_UserMoudle.InitPointer(&m_Senser01Worker, &m_Senser02Worker, m_Engine);
    m_Engine->rootContext()->setContextProperty("UserInterfaceModule", &m_UserMoudle);
}
