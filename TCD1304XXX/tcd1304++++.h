#ifndef TCD1304_H
#define TCD1304_H
#include "tcd1304xxx.h"

#if defined(Q_OS_WIN)
    extern "C" __declspec(dllexport) TCD1304XXX* TCD1304Create() {return new TCD1304XXX();}
    extern "C" __declspec(dllexport) bool TCD1304XXX_OpenDevice(TCD1304XXX* pTCD1304XXX, DWORD value) {return pTCD1304XXX->OpenDevice(value);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_CloseDevice(TCD1304XXX* pTCD1304XXX) {return pTCD1304XXX->CloseDevice();}
    extern "C" __declspec(dllexport) bool TCD1304XXX_SetIntergral(TCD1304XXX* pTCD1304XXX, quint8 value) {return pTCD1304XXX->SetIntergral(value);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_GetPolyData(TCD1304XXX* pTCD1304XXX, double* pixels) {return pTCD1304XXX->GetPolyData(pixels);}
    extern "C" __declspec(dllexport) void TCD1304XXX_SetRawDataFilterFlag(TCD1304XXX* pTCD1304XXX, bool flag) {return pTCD1304XXX->setRawDataFilterFlag(flag);}
    extern "C" __declspec(dllexport) void TCD1304XXX_SetPloyDataFilterFlag(TCD1304XXX* pTCD1304XXX, bool flag) {return pTCD1304XXX->setPloyDataFilterFlag(flag);}
    extern "C" __declspec(dllexport) void TCD1304XXX_SetMaskPixel(TCD1304XXX* pTCD1304XXX, quint16 maskLength, quint16 maskValue) {return pTCD1304XXX->setMaskPixel(maskLength, maskValue);}
    extern "C" __declspec(dllexport) bool TCD1304XXX_GetDeviceList(TCD1304XXX* pTCD1304XXX, DWORD *numberDevices) {return pTCD1304XXX->GetDeviceList(numberDevices);}
    extern "C" __declspec(dllexport) char* TCD1304XXX_GetDeviceListSerialNum(TCD1304XXX* pTCD1304XXX, DWORD devNums) {return pTCD1304XXX->GetDeviceListSerialNum(devNums);}
#endif


#endif // TCD1304_H
