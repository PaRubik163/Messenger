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
private slots:
    void onNewMessage();
private:
    QString name;
    QMap<QString, std::function<void(const QJsonObject &)>> commands;
    void checkNameResponse(const QJsonObject &);
};

#endif // USER_H
