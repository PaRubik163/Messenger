#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QVector>

#include "user.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();

    void incomingConnection(qintptr socketDescriptor) override;
private:

    QVector<std::shared_ptr<User>> users;

    QMap<QString, std::function<void(const QJsonObject &, User*)>> commands;
    void messageTo(const QJsonObject &, User*);
    void messageToAll(const QJsonObject &, User*);
    void checkName(const QJsonObject &, User*);

public slots:
    void onDisconected();
    void onNewMessage();


};


#endif // SERVER_H
