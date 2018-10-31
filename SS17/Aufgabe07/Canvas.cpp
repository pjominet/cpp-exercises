#include <QPainter>
#include <QtGui>
#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setPalette(QPalette(QColor(240, 248, 255)));
    setAutoFillBackground(true);
}

void Canvas::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(x, y, 50, 50, QColor(255, 0, 0));
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
        if (x >= 25)
            x -= 25;
    if (event->button() == Qt::RightButton)
        if (x <= 400)
            x += 25;
    update();
}
