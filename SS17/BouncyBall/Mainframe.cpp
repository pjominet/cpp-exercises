#include <QtGui>
#include <QPushButton>
#include <QGridLayout>

#include "Mainframe.h"

Mainframe::Mainframe(QWidget *parent) : QWidget(parent) {
    auto *gridLayout = new QGridLayout;
    auto const sansSerif = QFont("Helvetica", 12);

    auto *start = new QPushButton("Animate");
    start->setFont(sansSerif);
    connect(start, SIGNAL(clicked()), this, SLOT(start()));

    auto *stop = new QPushButton("Freeze");
    stop->setFont(sansSerif);
    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));

    auto *spawn = new QPushButton("Spawn one");
    spawn->setFont(sansSerif);
    connect(spawn, SIGNAL(clicked()), this, SLOT(spawn()));

    auto *spawnMany = new QPushButton("Spawn many");
    spawnMany->setFont(sansSerif);
    connect(spawnMany, SIGNAL(clicked()), this, SLOT(spawnMany()));

    canvas->setFixedSize(1600, 800);
    gridLayout->addWidget(canvas, 0, 0, 1, 4);
    gridLayout->addWidget(start, 1, 0);
    gridLayout->addWidget(stop, 1, 1);
    gridLayout->addWidget(spawn, 1, 2);
    gridLayout->addWidget(spawnMany, 1, 3);
    setLayout(gridLayout);
}

void Mainframe::start() {
    canvas->start();
}

void Mainframe::stop() {
    canvas->stop();
}

void Mainframe::spawn() {
    canvas->spawn();
}

void Mainframe::spawnMany() {
    for (unsigned int i = 0; i <= 20; i++) {
        canvas->spawn();
    }
}
