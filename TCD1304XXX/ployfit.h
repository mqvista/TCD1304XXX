#ifndef PLOYFIT_H
#define PLOYFIT_H

#include <QObject>
#include <QDebug>
#include <math.h>


class Q_DECL_EXPORT PloyFit
{
public:
    explicit PloyFit();
    void calc(quint16 *dataX, quint16 *dataY, quint16 dataLength, quint8 polyN, double *value);
    double slove(double a, double b, double c, double x);

private:
};

#endif // PLOYFIT_H
