#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
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

    void saveToFile();

    void loadFromFile();
};

#endif //AUFGABE07_MAINFRAME_H
