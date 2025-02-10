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
    QObject::connect(this, &QTcpSocket::readyRead, this, &User::onNewMessage);

    commands["check name response"] = [this](const QJsonObject &json)
    {
        checkNameResponse(json);
    };
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

void User::onNewMessage()
{
    QByteArray bytes = readAll();

    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    QJsonObject json = doc.object();

    QString type = json["type"].toString();
    commands[type](json);
}

void User::checkNameResponse(const QJsonObject &obj)
{
    qDebug() << obj;
}
