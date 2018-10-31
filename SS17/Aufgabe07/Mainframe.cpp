#include <QtGui>
#include <QPushButton>
#include <QGridLayout>

#include "Mainframe.h"
#include "Canvas.h"

Mainframe::Mainframe(QWidget *parent) : QWidget(parent) {
    auto *canvas = new Canvas;
    auto *gridLayout = new QGridLayout;
    gridLayout->addWidget(canvas, 0, 0);
    setLayout(gridLayout);
}
