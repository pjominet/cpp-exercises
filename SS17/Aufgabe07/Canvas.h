#include <QWidget>

#ifndef AUFGABE07_CANVAS_H
#define AUFGABE07_CANVAS_H


class Canvas : public QWidget {
Q_OBJECT
private:
    int x = 225, y = 225;
public:
    explicit Canvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif //AUFGABE07_CANVAS_H
