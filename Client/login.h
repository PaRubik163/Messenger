#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

private:
    QLabel *login, *ip, *password;
    QLineEdit *loginEdit, *passwordEdit, *ipEdit;
    QPushButton *enter;
    QVBoxLayout *layout;
    QHBoxLayout *loginlayout, *iplayout, *passwordlayout;

signals:
    void loggined(QString name, QString ip);
private slots:
    void onEnterClicked();
};

#endif // LOGIN_H
