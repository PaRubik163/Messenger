#include <QApplication>
#include "user.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    User u;

    return app.exec();
}
