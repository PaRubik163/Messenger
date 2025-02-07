#include <QApplication>
#include "server.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug("Начало работы сервера");
    Server s;

    return app.exec();
}
