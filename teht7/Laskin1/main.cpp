#include <QApplication>
#include "Laskin.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Laskin window;
    window.show();
    return app.exec();
}
