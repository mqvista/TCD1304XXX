#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include "windowfilter.h"

class Q_DECL_EXPORT Filter
{
public:
    explicit Filter();
    ~Filter();
    void get(quint16* originalValue, quint16* filterValue);


private:
    UWindowFilter<quint32>* uFilter;
};

#endif // FILTER_H
