#include "user.h"

#include <QJsonDocument>
#include <QJsonObject>

User::User()
{
    QObject::connect(this, &User::connected, [this]()
    {
        QJsonObject obj;
        obj["name"] = name;
        obj["type"] = "check name";
        QJsonDocument doc(obj);
        QByteArray bytes = doc.toJson();
        write(bytes);
    });
}

void User::connect(const QString &ip, quint16 port)
{
    qDebug() << "Подключение к серверу";
    connectToHost(ip, port);
}

void User::setName(const QString &name)
{
    this->name = name;
    qDebug() << "имя изменилось";
}
