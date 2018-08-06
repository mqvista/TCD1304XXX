#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include "windowfilter.h"

class Q_DECL_EXPORT Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = nullptr);
    ~Filter();
    void get(quint16* originalValue, quint16* filterValue);

signals:

public slots:

private:
    UWindowFilter<quint32>* uFilter;
};

#endif // FILTER_H
