#include <QApplication>
#include "Mainframe.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Mainframe mainframe;
    mainframe.setGeometry(400, 100, 1200, 700);
    mainframe.show();
    return app.exec();
}