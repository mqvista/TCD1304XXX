#ifndef TCD1304XXX_H
#define TCD1304XXX_H

#include "tcd1304xxx_global.h"
#include "ftdriver.h"
#include "ployfit.h"
#include "filter.h"


class TCD1304XXXSHARED_EXPORT TCD1304XXX : public FtDriver
{

public:
    TCD1304XXX();
    // Set the CCD intergral time
    // If you are in running loop ,it will send the intergral time
    // after current cycle
    // Param1 intergral time from 1~100
    bool SetIntergral(const quint8 value);
    // Get raw senser data
    // Param1 data[3648]
    bool GetRawData(quint16* data);
    // Get the pixels after poly
    bool GetPolyData(double* pixels);
    // Set to enable or disable filter
    void setRawDataFilterFlag(bool flag);
    void setPloyDataFilterFlag(bool flag);
    // Set to mask pixel, according the device
    void setMaskPixel(quint16 maskLength, quint16 maskValue);


private:
    bool m_IsRunning;
    bool m_NeedtoUpdate;
    quint8 m_Intergral;
    quint16 m_ThresholdValue;
    double m_PloyLength;
    double m_FilteredPloyLength;
    quint16 m_RawData[3648];
    quint16 m_FilteredRawData[3648];
    bool m_RawDataFilterFlag;
    bool m_PloyDataFilterFlag;
    quint16 m_MinThreshold;
    quint16 m_MaxThreshold;
    quint16 m_FillLength;
    quint16 m_FillValue;

    Filter arrayFilter;
    UWindowFilter<double> ployWindowFilter;
    PloyFit ployFit;
    // Set raw data filter
    bool RawFilter(bool flag);
    // Force send data to ftdi
    bool SendIntergralData();
    // Get left and right length use max min
    void GetLeftRight(quint16* senserData, quint16 minCutValue, quint16 maxCutValue,
                      quint16* leftOffset, quint16* leftLength, quint16* rightOffset, quint16* rightLength);
    // Mask left and right where the laser can't touch
    void FillHeadTail(quint16 length, quint16 value);
};

#if defined(Q_OS_WIN)
    extern "C" __declspec(dllexport) TCD1304XXX* TCD1304Create() {return new TCD1304XXX();}
    extern "C" __declspec(dllexport) bool TCD1304XXX_OpenDevice(TCD1304XXX* pTCD1304XXX, DWORD value) {return pTCD1304XXX->OpenDevice(value);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_CloseDevice(TCD1304XXX* pTCD1304XXX) {return pTCD1304XXX->CloseDevice();}
    extern "C" __declspec(dllexport) bool TCD1304XXX_SetIntergral(TCD1304XXX* pTCD1304XXX, quint8 value) {return pTCD1304XXX->SetIntergral(value);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_GetPolyData(TCD1304XXX* pTCD1304XXX, double* pixels) {return pTCD1304XXX->GetPolyData(pixels);}
    extern "C" __declspec(dllexport) void TCD1304XXX_SetRawDataFilterFlag(TCD1304XXX* pTCD1304XXX, bool flag) {return pTCD1304XXX->setRawDataFilterFlag(flag);}
    extern "C" __declspec(dllexport) void TCD1304XXX_SetPloyDataFilterFlag(TCD1304XXX* pTCD1304XXX, bool flag) {return pTCD1304XXX->setPloyDataFilterFlag(flag);}
    extren "C" __declspec(dllexport) void TCD1304XXX_SetMaskPixel(TCD1304XXX* pTCD1304XXX, quint16 maskLength, quint16 maskValue) {return pTCD1304XXX->setMaskPixel(maskLength, maskValue);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_GetDeviceList(TCD1304XXX* pTCD1304XXX, DWORD *numberDevices) {return pTCD1304XXX->GetDeviceList(&numberDevices);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_GetDeviceListInfo(TCD1304XXX* pTCD1304XXX, DWORD numberDevices, DEVICE_LIST_INFO_NODE *device_node) {return pTCD1304XXX->GetDeviceListInfo(numberDevices, device_node);}

#endif


#endif // TCD1304XXX_H
