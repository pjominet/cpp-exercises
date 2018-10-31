#include "Ball.h"

Ball::Ball(const QPoint &center, int radius, int speedX, int speedY, QColor color) : center(center), radius(radius),
                                                                                         speedX(speedX), speedY(speedY),
                                                                                         color(std::move(color)) {}

void Ball::move(int width, int height) {
    auto locationX = center.x();
    auto locationY = center.y();

    if (locationX > width - radius || locationX < radius) {
        speedX *= -1;
    }
    if (locationY > height - radius || locationY < radius) {
        speedY *= -1;
    }

    locationX += speedX;
    locationY += speedY;

    center.setX(locationX);
    center.setY(locationY);

}
