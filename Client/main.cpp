#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget widget;

    widget.setWindowTitle("Вход в приложение");
    widget.resize(300,150);
    widget.show();

    qDebug("Открылось окно приложения");
    return app.exec();
}
