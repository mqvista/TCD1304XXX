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

#endif // TCD1304XXX_H
