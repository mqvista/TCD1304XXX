#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "tcd1304xxx.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    double length;
    TCD1304XXX tcd;
    // 开启设备
    tcd.OpenDevice(0);
    // 设定积分时间
    tcd.SetIntergral(6);
    // 开启滤波
    tcd.setPloyDataFilterFlag(true);


    qDebug() << tcd.GetPolyData(&length);
    qDebug() << "length" << length;
    while (1)
    {
        // 获取数据
        if(tcd.GetPolyData(&length))
            qDebug() << false;
        qDebug() << "length" << length;
    }

    // 关闭设备
    tcd.CloseDevice();
    return a.exec();
}
