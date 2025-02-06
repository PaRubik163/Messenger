#ifndef USER_H
#define USER_H
#include <QTcpSocket>

class User : public QTcpSocket
{
    Q_OBJECT
public slots:

    void connect(const QString &ip, quint16 port);
public:
    User();
    void setName(const QString &name);
private:
    QString name;

};

#endif // USER_H
