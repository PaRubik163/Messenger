#include "server.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include "checknameresponse.h"

Server::Server()
{
    if (!listen(QHostAddress::Any, 6000))
    {
        QMessageBox::critical(nullptr, "Ошибка подключения", "Не удалось начать прослушивание на текущем порту");
        return;
    }

    commands["message to"] = [this](const QJsonObject &json, User* user)
    {
        messageTo(json, user);
    };

    commands["message to all"] = [this](const QJsonObject &json, User *user)
    {
        messageToAll(json, user);
    };

    commands["check name"] = [this](const QJsonObject &json, User *user)
    {
        checkName(json, user);
    };
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    auto user = std::make_unique<User>();
    user->setSocketDescriptor(socketDescriptor);

    connect(user.get(), &QTcpSocket::disconnected,
            this, &Server::onDisconected);

    connect(user.get(), &QTcpSocket::readyRead,
            this, &Server::onNewMessage);

    users.push_back(std::move(user));
}

void Server::messageTo(const QJsonObject &json, User *user)
{
    for(auto &us :users)
    {
        if (us->name == json["taker"].toString())
        {
            QJsonDocument doc;
            doc.setObject(json);
            us->write(doc.toBinaryData());
        }
    }
}

void Server::messageToAll(const QJsonObject &json, User *user)
{
    for(auto &us : users)
    {
        if(!us->name.isEmpty() && us.get() != user)
        {
            QJsonDocument doc;
            doc.setObject(json);
            us->write(doc.toBinaryData());
        }
    }
}

void Server::checkName(const QJsonObject &json, User *user)
{
    QString name = json["name"].toString();
    if(name.isEmpty())
    {
        QJsonDocument doc(CheckNameResponse().success(false).description("name is empty").build());
        QByteArray bytes = doc.toJson();
        user->write(bytes);
        return;
    }

    for(auto &us : users)
    {
        if(us->name == name)
        {
            QJsonDocument doc(CheckNameResponse().success(false).description("name already used").build());
            QByteArray bytes = doc.toJson();
            user->write(bytes);
            return;
        }
    }

    QJsonDocument doc(CheckNameResponse().success(true).build());
    QByteArray bytes = doc.toJson();
    user->write(bytes);
}

void Server::onDisconected()
{

}

void Server::onNewMessage()
{
    auto user = dynamic_cast<User*>(sender());
    QByteArray bytes = user->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    QJsonObject json = doc.object();

    QString type = json["type"].toString();
    commands[type](json, user);
}

