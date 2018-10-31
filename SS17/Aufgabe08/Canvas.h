#include <QWidget>
#include <QFile>
#include <QKeyEvent>

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

    void keyReleaseEvent(QKeyEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    void serialize(QFile &file);

    void deserialize(QFile &file);
};

#endif //AUFGABE07_CANVAS_H
