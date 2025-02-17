#include <QApplication>
#include "Laskin.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Laskin laskin;
    laskin.show();
    return app.exec();
}
