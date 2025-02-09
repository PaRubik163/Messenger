#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent)
{

    login_ = new QLabel("Логин:", this);
    ip_ = new QLabel("IP-адрес:", this);
    password_ = new QLabel("Пароль:", this);

    loginEdit_ = new QLineEdit(this);
    ipEdit_ = new QLineEdit(this);
    passwordEdit_ = new QLineEdit(this);
    passwordEdit_->setEchoMode(QLineEdit::Password);

    enter_ = new QPushButton("Войти", this);

    loginlayout_ = new QHBoxLayout();
    loginlayout_->addWidget(login_);
    loginlayout_->addWidget(loginEdit_);

    iplayout_ = new QHBoxLayout();
    iplayout_->addWidget(ip_);
    iplayout_->addWidget(ipEdit_);

    passwordlayout_ = new QHBoxLayout();
    passwordlayout_->addWidget(password_);
    passwordlayout_->addWidget(passwordEdit_);

    layout_ = new QVBoxLayout(this);
    layout_->addLayout(loginlayout_);
    layout_->addLayout(iplayout_);
    layout_->addLayout(passwordlayout_);
    layout_->addWidget(enter_);

    setLayout(layout_);

    connect(enter_, &QPushButton::clicked, this, &Login::onEnterClicked);
}

void Login::onEnterClicked()
{
    QString name = loginEdit_->text();
    QString ip = ipEdit_->text();
    QString password = passwordEdit_->text();

    if (name.isEmpty() || ip.isEmpty() || password.isEmpty())
    {
        qWarning() << "Не все поля заполнены!";
    }
    else
    {
        emit loggined(name, ip);
        qDebug() << "Успешное подключение";
        close();
    }
}
