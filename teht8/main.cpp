#include <QApplication>
#include "chessclock.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChessClock clock;
    clock.show();
    return app.exec();
}
