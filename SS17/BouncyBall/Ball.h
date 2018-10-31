#include <QPoint>
#include <QtGui/QColor>

#ifndef AUFGABE09_CIRCLE_H
#define AUFGABE09_CIRCLE_H


class Ball {
public:
    QPoint center;
    int radius;
    int speedX;
    int speedY;
    QColor color;

    Ball(const QPoint &center, int radius, int speedX, int speedY, QColor color);

    void move(int width, int height);

    ~Ball() = default;
};


#endif //AUFGABE09_CIRCLE_H
