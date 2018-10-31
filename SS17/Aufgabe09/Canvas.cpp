#include <QPainter>
#include <QtGui>
#include <QtWidgets/QMessageBox>
#include "Canvas.h"
#include "Ball.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setPalette(QPalette(QColor(250, 250, 150)));
    setAutoFillBackground(true);
    setMouseTracking(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));

}

Canvas::~Canvas() {
    delete timer;
    for (Ball *ball : balls) {
        delete ball;
    }
}

void Canvas::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (!balls.empty()) {
        for (Ball *ball : balls) {
            painter.setPen(ball->color); // border color
            painter.setBrush(ball->color); // fill color
            painter.drawEllipse(ball->center, ball->radius, ball->radius);
        }
    }
    painter.end();
}

void Canvas::start() {
    if (!balls.empty()) timer->start(10);
    else {
        QMessageBox::warning(this, "Error", "No balls!", QMessageBox::Ok);
        return;
    }
}

void Canvas::stop() {
    timer->stop();
}

void Canvas::spawn() {
    int x = generateInteger(100, 1100);
    int y = generateInteger(100, 600);
    auto *center = new QPoint(x, y);

    int speedX = generateInteger(-15, 15);
    int speedY = generateInteger(-10, 10);

    int radius = generateInteger(10, 30);

    int red = generateInteger(0, 255);
    int green = generateInteger(0, 255);
    int blue = generateInteger(0, 255);
    auto color = QColor(red, green, blue);

    balls.push_back(new Ball(*center, radius, speedX, speedY, color));
    update();
}

void Canvas::animate() {
    for (Ball *ball : balls) {
        ball->move(width, height);
    }
    update();
}

int Canvas::generateInteger(int min, int max) {
    return min + (rand() * (max - min) / RAND_MAX);
}
