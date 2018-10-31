#include <QApplication>
#include "Mainframe.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Mainframe mainframe;
    mainframe.setGeometry(100, 100, 1600, 800);
    mainframe.show();
    return app.exec();
}