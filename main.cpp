#include <QLabel>
#include <QApplication>
#include <QWindow>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Forsyth–Edwards Notation Converter");
    w.setWindowIcon(QIcon(":/korona_bez_1.png"));
    w.show();
    return a.exec();
}
