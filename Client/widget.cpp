#include "widget.h"
#include "ui_widget.h"
#include "login.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    us = new User;
    Login l(this);
    connect(&l, &Login::loggined,[this](QString name, QString ip)
    {
        us->setName(name);
        us->connect(ip, 6000);
    } );
    l.exec();
}

Widget::~Widget()
{
    delete ui;
}
