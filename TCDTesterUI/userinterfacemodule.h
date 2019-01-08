#ifndef USERINTERFACEMODULE_H
#define USERINTERFACEMODULE_H

#include <QObject>

class UserInterfaceModule
{
public:
    UserInterfaceModule();
    Q_INVOKABLE void getSenser1List();
};

#endif // USERINTERFACEMODULE_H
