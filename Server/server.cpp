#include "server.h"

#include <QMessageBox>

Server::Server()
{
    if (!listen(QHostAddress::Any, 6000))
    {
        QMessageBox::critical(nullptr, "Ошибка подключения", "Не удалось начать прослушивание на текущем порту");
        return;
    }
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

void Server::onDisconected()
{

}

void Server::onNewMessage()
{

}
