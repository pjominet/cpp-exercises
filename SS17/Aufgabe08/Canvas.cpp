#include <QPainter>
#include <QtGui>
#include <QMessageBox>
#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setPalette(QPalette(QColor(250, 250, 150)));
    setAutoFillBackground(true);
    // set focus to canvas, to detect key presses
    setFocusPolicy(Qt::StrongFocus);
}

void Canvas::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    // reference grid
    painter.drawLine(250, 0, 250, 500);
    painter.drawLine(0, 250, 500, 250);
    for (unsigned int i = 25; i <= 500; i += 25) {
        painter.drawLine(i, 245, i, 255);
        painter.drawLine(245, i, 255, i);
    }
    // rectangle
    painter.fillRect(x, y, 50, 50, QColor(255, 0, 0, 180));
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
        if (x >= 25)
            x -= 25;
    if (event->button() == Qt::RightButton)
        if (x <= 425) // should be 450??
            x += 25;
    update();
}

void Canvas::keyReleaseEvent(QKeyEvent *event) {
    QWidget::keyReleaseEvent(event);
    if (event->key() == Qt::Key_Left)
        if (x >= 25)
            x -= 25;
    if (event->key() == Qt::Key_Right)
        if (x <= 425)
            x += 25;
    if (event->key() == Qt::Key_Up)
        if (y >= 25)
            y -= 25;
    if (event->key() == Qt::Key_Down)
        if (y <= 425)
            y += 25;
    update();
}

void Canvas::serialize(QFile &file) {
    QTextStream out(&file);
    out << "p " << x << " " << y << endl;
}

void Canvas::deserialize(QFile &file) {
    char c;
    QTextStream in(&file);;

    while (in.status() == QTextStream::Ok) {
        in >> c;
        if (in.status() == QTextStream::ReadPastEnd) break;
        if (c != 'p') {
            QMessageBox::warning(this, "Read Error", "The file structure is unknown", QMessageBox::Ok);
            return;
        }
        in >> x >> y;
        in >> c;
    }

    update();
}
