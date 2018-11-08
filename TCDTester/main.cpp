#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include "tcd1304xxx.h"
//#include "ftdriver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    double length;
    TCD1304XXX tcd;

    //
    DWORD devNums;
    qDebug()<<tcd.GetDeviceList(&devNums);
    TCD1304XXX::DEVICE_LIST_INFO_NODE *node;
    node = (TCD1304XXX::DEVICE_LIST_INFO_NODE*)malloc(sizeof (TCD1304XXX::DEVICE_LIST_INFO_NODE)*devNums);
    if( tcd.GetDeviceListInfo(devNums, node) )
    {
        for (quint8 i=0; i<devNums; i++)
        {
            qDebug()<< "Dev:" << i;
            qDebug()<< node[i].LocId;
            qDebug()<< node[i].Type;
            qDebug()<< node[i].SerialNumber;
            qDebug()<< node[i].ID;
        }
    }





    // 开启设备
    tcd.OpenDevice(0);
    // 设定积分时间
    tcd.SetIntergral(2);
    // 按照实际设备设置遮罩
    tcd.setMaskPixel(5, 48000);
    // 开启滤波
    //tcd.setPloyDataFilterFlag(true);



    while (true)
    {
        qDebug()<< "time1" << QTime::currentTime();

        //获取数据
        if(tcd.GetPolyData(&length))
            qDebug() << "length:" << length;
        else
            qDebug() << "false";

        qDebug()<< "time2" << QTime::currentTime();
    }

    // 关闭设备
    qDebug()<< "Close:"<<tcd.CloseDevice();
    return a.exec();
}

