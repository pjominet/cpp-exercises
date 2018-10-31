#include <QWidget>
#include <QTimer>
#include <QPoint>
#include <vector>

#ifndef AUFGABE07_CANVAS_H
#define AUFGABE07_CANVAS_H

class Canvas : public QWidget {
Q_OBJECT
private:
    QTimer *timer;
    std::vector<struct Ball *> balls;
    int width = 1600, height = 800;

    int generateInteger(int min, int max);

public:
    explicit Canvas(QWidget *parent = nullptr);

    ~Canvas() override;

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:

    void start();

    void stop();

    void spawn();

    void animate();
};

#endif //AUFGABE07_CANVAS_H
