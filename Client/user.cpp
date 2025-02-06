#include "user.h"


void User::connect(const QString &ip, quint16 port)
{
    qDebug("Начало подключения");
    connectToHost(ip, port);
}

void User::setName(const QString &name)
{
    this->name = name;
}
