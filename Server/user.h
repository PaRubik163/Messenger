#ifndef USER_H
#define USER_H

#include <QObject>
#include <QTcpSocket>

class User : public QTcpSocket
{
    Q_OBJECT
public:
    User();

    QString name, status;
};

#endif // USER_H
