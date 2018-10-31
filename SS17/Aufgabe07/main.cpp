#include <QApplication>
#include "Mainframe.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Mainframe mainframe;
    mainframe.setGeometry(710, 290, 500, 500);
    mainframe.show();
    return app.exec();
}