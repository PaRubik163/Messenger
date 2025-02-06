#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    User *us;
};

#endif // WIDGET_H
