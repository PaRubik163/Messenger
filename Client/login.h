#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

private:
    QLabel *login_, *ip_, *password_;
    QLineEdit *loginEdit_, *passwordEdit_, *ipEdit_;
    QPushButton *enter_;
    QVBoxLayout *layout_;
    QHBoxLayout *loginlayout_, *iplayout_, *passwordlayout_;

signals:
    void loggined(QString name, QString ip);
private slots:
    void onEnterClicked();
};

#endif // LOGIN_H
