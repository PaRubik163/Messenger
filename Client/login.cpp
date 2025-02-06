#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent)
{

    login = new QLabel("Логин:", this);
    ip = new QLabel("IP-адрес:", this);
    password = new QLabel("Пароль:", this);

    loginEdit = new QLineEdit(this);
    ipEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    enter = new QPushButton("Войти", this);

    loginlayout = new QHBoxLayout();
    loginlayout->addWidget(login);
    loginlayout->addWidget(loginEdit);

    iplayout = new QHBoxLayout();
    iplayout->addWidget(ip);
    iplayout->addWidget(ipEdit);

    passwordlayout = new QHBoxLayout();
    passwordlayout->addWidget(password);
    passwordlayout->addWidget(passwordEdit);

    layout = new QVBoxLayout(this);

    layout->addLayout(loginlayout);
    layout->addLayout(iplayout);
    layout->addLayout(passwordlayout);
    layout->addWidget(enter);

    setLayout(layout);

    connect(enter, &QPushButton::clicked, this, &Login::onEnterClicked);

}

void Login::onEnterClicked()
{
    QString login_ = loginEdit->text();
    QString ip_ = ipEdit->text();
    QString password_ = passwordEdit->text();

    if (login_.isEmpty() || ip_.isEmpty() || password_.isEmpty())
    {
        QMessageBox::warning(this, "ОШИБКА", "Все поля должны быть заполнены!");
    }
    else
    {
        emit loggined(login_, ip_);
        close();
    }
}
