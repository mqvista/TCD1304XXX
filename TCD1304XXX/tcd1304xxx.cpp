#include "tcd1304xxx.h"


TCD1304XXX::TCD1304XXX():FtDriver(),ployWindowFilter(20)
{
    m_IsRunning = false;
    m_NeedtoUpdate = false;
    m_ThresholdValue = 30000;
    m_RawDataFilterFlag = false;
    m_PloyDataFilterFlag = false;
    m_MinThreshold = 20000;
    m_MaxThreshold = 40000;
    m_FillLength = 0;
    m_FillValue = 0;
}

bool TCD1304XXX::SetIntergral(const quint8 value)
{
    m_Intergral = value;
    if (m_IsRunning)
    {
        m_NeedtoUpdate = true;
        return true;
    }
    else
    {
        return SendIntergralData();
    }
}

bool TCD1304XXX::GetRawData(quint16 *data)
{
    if (m_NeedtoUpdate)
    {
        if(SendIntergralData())
            m_NeedtoUpdate = false;
        else
            return false;
    }

    if (! SendData("#?data%"))
        return false;
    if (! GetData(data))
        return false;
    return true;
}

bool TCD1304XXX::GetPolyData(double *pixels)
{
    // Update the intergral data
    if (m_NeedtoUpdate)
    {
        if(SendIntergralData())
            m_NeedtoUpdate = false;
        else
            return false;
    }

    if (! SendData("#?data%"))
        return false;
    if (! GetData(m_RawData))
        return false;
    // Fill pixels (填充激光无法照射到)
    FillHeadTail(m_FillLength, m_FillValue);

    // 窗口滤波原始数据
    if (m_RawDataFilterFlag)
    {
        arrayFilter.get(m_RawData, m_FilteredRawData);
    }
    else
    {
        std::copy(std::begin(m_RawData), std::end(m_RawData), std::begin(m_FilteredRawData));
    }

    // 计算AB两斜线的位置
    quint16 leftOffset, leftLength, rightOffset, rightLength;
    GetLeftRight(m_FilteredRawData, m_MinThreshold, m_MaxThreshold, &leftOffset, &leftLength,
                 &rightOffset, &rightLength);

    // 提取斜线的数据到新数组
    quint16 *dataAX = new quint16[leftLength];
    quint16 *dataBX = new quint16[rightLength];
    for(quint16 i=0; i<leftLength; i++)
    {
        dataAX[i] = leftOffset+i+1;
    }
    for(quint16 i=0; i<rightLength; i++)
    {
        dataBX[i] = rightOffset+i+1;
    }

    // 二乘法多项式拟合（2项）
    // 申请两个数组，存放拟合结果数据
    double tmpLeftValue[3], tmpRightValue[3];
    double calcLeft=0, calcRight=0;
    // 判断是否是垃圾数据
    // 是的话就不进行拟合
    if(leftLength > 2 && rightLength >2 )
    {
        //执行拟合
        ployFit.calc(m_FilteredRawData+leftOffset, dataAX, leftLength, 3, tmpLeftValue);
        ployFit.calc(m_FilteredRawData+rightOffset, dataBX, rightLength, 3, tmpRightValue);

        //拟合好后把阈值带入求解;
        calcLeft =  ployFit.slove(tmpLeftValue[2], tmpLeftValue[1], tmpLeftValue[0], m_ThresholdValue);
        calcRight = ployFit.slove(tmpRightValue[2], tmpRightValue[1], tmpRightValue[0], m_ThresholdValue);
    }
    // 判断是不是到左边极限
    if(leftLength > 2 && rightLength <= 2 && rightOffset != 0)
    {
        //执行拟合
        ployFit.calc(m_FilteredRawData+leftOffset, dataAX, leftLength, 3, tmpLeftValue);
        //拟合好后把阈值带入求解;
        calcLeft =  ployFit.slove(tmpLeftValue[2], tmpLeftValue[1], tmpLeftValue[0], m_ThresholdValue);

        calcRight = rightOffset;
    }
    // 判断是不是到右边边极限
    if(rightLength > 2 && leftLength <= 2 && leftOffset != 0)
    {
        //执行拟合
        ployFit.calc(m_FilteredRawData+rightOffset, dataBX, rightLength, 3, tmpRightValue);
        //拟合好后把阈值带入求解;
        calcRight = ployFit.slove(tmpRightValue[2], tmpRightValue[1], tmpRightValue[0], m_ThresholdValue);

        calcLeft = leftOffset;
    }

    // 因为拟合的是左右两个边，所以需要相减求出大小
    m_PloyLength = calcRight-calcLeft;

    if (m_PloyDataFilterFlag)
    {
        m_FilteredPloyLength = ployWindowFilter.Get(m_PloyLength);
    }
    else
    {
        m_FilteredPloyLength = m_PloyLength;
    }

    *pixels = m_FilteredPloyLength;
    return true;
}

void TCD1304XXX::setRawDataFilterFlag(bool flag)
{
    m_RawDataFilterFlag = flag;
}

void TCD1304XXX::setPloyDataFilterFlag(bool flag)
{
    m_PloyDataFilterFlag = flag;
}

void TCD1304XXX::setMaskPixel(quint16 maskLength, quint16 maskValue)
{
    m_FillLength = maskLength;
    m_FillValue = maskValue;
}

bool TCD1304XXX::RawFilter(bool flag)
{
    m_RawDataFilterFlag = flag;
    return true;
}

bool TCD1304XXX::SendIntergralData()
{
    QString intValueStr = QString::asprintf("#CCDInt:%03d%%",m_Intergral);
    return SendData(intValueStr);
}

// 获取左右两边的数据，比较陡的左右两个边沿
// 为了后面做拟合使用，取值一个范围
// 参数一 范围的最小值
// 参数二 范围的最大值
// 参数三 指针参数，为了把数据丢出来
void TCD1304XXX::GetLeftRight(quint16 *senserData, quint16 minCutValue, quint16 maxCutValue, quint16 *leftOffset,
                              quint16 *leftLength, quint16 *rightOffset, quint16 *rightLength)
{
    // 清理旧的数据
    *leftOffset = 0;
    *leftLength = 0;
    *rightOffset = 0;
    *rightLength = 0;

    bool startFlagA = true, startFlagB = true, stopFlagA = true, stopFlagB = true;
    quint16 tmpBvalue;
    for (quint16 i=0; i<3648; i++)
    {
        if((senserData[i] <= maxCutValue) && startFlagA)
        {
            *leftOffset = i;
            startFlagA = false;
        }
        if((senserData[i] <= minCutValue) && stopFlagA)
        {
            *leftLength = i - *leftOffset;
            stopFlagA = false;
        }
        if((senserData[3647-i] <= maxCutValue) && startFlagB)
        {
            //从尾到头数， 先取得尾部的maxValue；
            tmpBvalue = 3647-i;
            startFlagB = false;
        }
        if((senserData[3647-i] <= minCutValue) && stopFlagB)
        {
            *rightOffset = 3647-i;
            *rightLength = tmpBvalue - *rightOffset;
            stopFlagB = false;
        }
        if(startFlagA == false && startFlagB == false && stopFlagA == false && stopFlagB == false)
        {
            break;
        }
    }
    if (*leftLength >= 50 || *rightLength >=50)
    {
        *leftOffset = 0;
        *leftLength = 0;
        *rightOffset = 0;
        *rightLength = 0;
    }
}

void TCD1304XXX::FillHeadTail(quint16 length, quint16 value)
{
    if (length == 0)
        return;
    for(quint16 i=0; i<length; i++)
    {
        m_RawData[i] = value;
        m_RawData[3647-i] = value;
    }
}

