#include "mainwindow.h"
#include "tape.h"
#include <QApplication>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    tape tape1("Tape1","Tape II",45);
    cout << tape1.getName();
    cout << tape1.getLength();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
