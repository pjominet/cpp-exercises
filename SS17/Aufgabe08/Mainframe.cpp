#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>

#include "Mainframe.h"

Mainframe::Mainframe(QWidget *parent) : QWidget(parent) {
    auto *gridLayout = new QGridLayout;
    auto const sansSerif = QFont("Helvetica", 12);

    auto *quit = new QPushButton("Quit");
    quit->setFont(sansSerif);
    quit->setFocusPolicy(Qt::NoFocus);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    auto *save = new QPushButton("Save");
    save->setFont(sansSerif);
    save->setFocusPolicy(Qt::NoFocus);
    connect(save, SIGNAL(clicked()), this, SLOT(saveToFile()));

    auto *open = new QPushButton("Open");
    open->setFont(sansSerif);
    open->setFocusPolicy(Qt::NoFocus);
    connect(open, SIGNAL(clicked()), this, SLOT(loadFromFile()));


    canvas->setFixedSize(500, 500);
    gridLayout->addWidget(canvas, 0, 0, 0, 3);
    gridLayout->addWidget(save, 1, 0);
    gridLayout->addWidget(open, 1, 1);
    gridLayout->addWidget(quit, 1, 2);
    setLayout(gridLayout);
}

void Mainframe::saveToFile() {
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this, "Save as", ".", "*.crd");

    if (!fileName.isNull()) {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "File Error", "The following file could not be written: " + fileName,
                                 QMessageBox::Ok);
        }
        canvas->serialize(file);
        file.close();
        return;
    }
}

void Mainframe::loadFromFile() {
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this, "Open as", ".", "*.crd");

    if (!fileName.isNull()) {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "File Error", "The following file could not be read: " + fileName,
                                 QMessageBox::Ok);
        }
        canvas->deserialize(file);
        file.close();
        return;
    }
}
