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

    QVector<std::unique_ptr<User>> users;

public slots:
    void onDisconected();
    void onNewMessage();

};


#endif // SERVER_H
