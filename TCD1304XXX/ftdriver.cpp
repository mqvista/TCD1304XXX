#include "ftdriver.h"

FtDriver::FtDriver()
{
    m_SelectedDeviceNum = 0;
    m_IsOpened = false;
}

bool FtDriver::GetDeviceList(DWORD* numberDevices)
{
    m_FtStatus = FT_CreateDeviceInfoList(&m_NumberDevices);
    if (m_FtStatus == FT_OK) {
        *numberDevices = m_NumberDevices;
        return true;
    } else
        return false;
}

char *FtDriver::GetDeviceListSerialNum(DWORD numberDevices)
{
    static char tempString[128];
    FT_DEVICE_LIST_INFO_NODE* devInfo;
    devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE) * m_NumberDevices);
    m_FtStatus = FT_GetDeviceInfoList(devInfo, &m_NumberDevices);
    if (m_FtStatus == FT_OK)
    {
        for (quint8 i = 0; i < numberDevices; i++)
        {
            memcpy(tempString + (i*8) + i, devInfo[i].SerialNumber, 8);
            tempString[(i+1)*8+i] = '#';
        }
        // 末尾+ '\0'
        tempString[numberDevices * 8 + numberDevices] = '\0';
    }
    return tempString;

    // 0, 17, 34, 51
    //    16, 33, 50
}

bool FtDriver::OpenDevice(DWORD iDevice)
{
    m_SelectedDeviceNum = iDevice;
    m_FtStatus = FT_Open(m_SelectedDeviceNum, &m_FtHandle);
    if (m_FtStatus == FT_OK) {
        if (InitDevice()) {
            m_IsOpened = true;
            return true;
        } else {
            FT_ResetDevice(m_FtHandle);
            FT_Close(m_FtHandle);
            return false;
        }
    } else {
        return false;
    }
}

bool FtDriver::CloseDevice()
{
    m_FtStatus = FT_Close(m_FtHandle);
    if (m_FtStatus == FT_OK) {
        m_IsOpened = false;
        return true;
    } else {
        m_IsOpened = false;
        return false;
    }
}

bool FtDriver::SendData(QString data)
{
    if (!m_IsOpened) {
        return false;
    }
    memset(m_TxBuffer, 0, sizeof(m_TxBuffer));
    for (quint16 i = 0; i < data.size(); i++) {
        m_TxBuffer[i] = data.toStdString()[i];
    }
    m_FtStatus = FT_Write(m_FtHandle, m_TxBuffer, data.size(), &m_ByteWritten);
    if (m_FtStatus == FT_OK) {
        return true;
    }
    return false;
}

bool FtDriver::GetData(quint16* data)
{
    if (!m_IsOpened) {
        return false;
    }
    bool loopFlag = true;
    quint16 currentPoint = 0;

    FT_SetTimeouts(m_FtHandle, 100, 0);
    while (loopFlag) {
        m_FtStatus = FT_Read(m_FtHandle, (quint8*)(m_RxBuffer + currentPoint), 128, &m_Bytereceived);
        if (m_FtStatus != FT_OK)
        {
            return false;
        }
        else if (m_Bytereceived !=128)
        {
            FT_Purge(m_FtHandle, FT_PURGE_TX | FT_PURGE_RX);
            return false;
        }
        else
        {

            currentPoint += m_Bytereceived;
        }
        if (currentPoint >= 7296)
        {
            loopFlag = false;
        }
    }

    for (quint16 i = 0; i < 3648; i++) {
        quint16 tmpData;
        tmpData = (m_RxBuffer[i * 2] << 8) | m_RxBuffer[i * 2 + 1];
        data[i] = tmpData;
    }
    return true;
}

bool FtDriver::InitDevice()
{
    m_FtStatus = FT_ResetDevice(m_FtHandle);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    m_FtStatus = FT_SetBaudRate(m_FtHandle, 1400000);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    m_FtStatus = FT_SetDataCharacteristics(m_FtHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    m_FtStatus = FT_SetFlowControl(m_FtHandle, FT_FLOW_NONE, 0, 0);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    m_FtStatus = FT_SetTimeouts(m_FtHandle, FT_DEFAULT_RX_TIMEOUT, FT_DEFAULT_TX_TIMEOUT);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    m_FtStatus = FT_Purge(m_FtHandle, FT_PURGE_TX | FT_PURGE_RX);
    if (m_FtStatus != FT_OK) {
        return false;
    }
    return true;
}
