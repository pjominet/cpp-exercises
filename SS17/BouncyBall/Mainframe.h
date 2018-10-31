#include <QWidget>
#include "Canvas.h"

#ifndef AUFGABE07_MAINFRAME_H
#define AUFGABE07_MAINFRAME_H


class Mainframe : public QWidget {
Q_OBJECT
public:
    explicit Mainframe(QWidget *parent = nullptr);

private:
    Canvas *canvas = new Canvas;

private slots:

    void start();

    void stop();

    void spawn();

    void spawnMany();
};

#endif //AUFGABE07_MAINFRAME_H
