#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "tcd1304xxx.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    double length;
    TCD1304XXX tcd;

    DWORD xxx;
    qDebug()<<tcd.ListDevices(&xxx);
    qDebug() << "list:" << xxx;


    // 开启设备
    tcd.OpenDevice(0);
    // 设定积分时间
    tcd.SetIntergral(2);
    // 按照实际设备设置遮罩
    tcd.setMaskPixel(5, 48000);
    // 开启滤波
    tcd.setPloyDataFilterFlag(true);



    while (true)
    {
        //获取数据
        if(tcd.GetPolyData(&length))
            qDebug() << "length:" << length;
        else
            qDebug() << "false";
    }

    // 关闭设备
    qDebug()<< "Close:"<<tcd.CloseDevice();
    return a.exec();
}

