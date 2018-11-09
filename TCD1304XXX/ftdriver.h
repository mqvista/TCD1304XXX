#ifndef FTDRIVER_H
#define FTDRIVER_H

#include <QObject>
#include "D2XX/include/ftd2xx.h"
//#include <string>

class Q_DECL_EXPORT FtDriver
{
public:
    explicit FtDriver();
    // List how manay devices are available
    // Param1 pointer numberDevices
    bool GetDeviceList(DWORD *numberDevices);
    // Open one device
    // Param1 device num. Indices are 0 based.
    bool OpenDevice(DWORD iDevice);
    // Close opened Devices
    bool CloseDevice();
    // Send data to device
    bool SendData(QString data);
    // Get data from device
    bool GetData(quint16 *data);
    // Get Device SerialNumber
    //std::string GetDeviceListSerialNum(DWORD numberDevices);
    // Type 2
    char * GetDeviceListSerialNum(DWORD numberDevices);



signals:

public slots:

private:
    FT_STATUS m_FtStatus;
    DWORD m_SelectedDeviceNum;
    DWORD m_NumberDevices;
    FT_HANDLE m_FtHandle;
    bool m_IsOpened;
    DWORD m_Bytereceived;
    DWORD m_ByteWritten;
    //quint32 m_RxBytes;
    //quint32 m_TxBytes;
    quint8 m_RxBuffer[7300];
    quint8 m_TxBuffer[128];


    bool InitDevice();
};

#endif // FTDRIVER_H
