//
// Created by Christian on 09/05/2025.
//

//title:        sleeptimer
//author:       Christian Schmeisser
//date:         09.05.2025
//description:  A simple desktop app to set, start and stop a shutdown timer in windows.
//              The timer runs entirely within the app and shutdown is only provoked
//              when the timer ends. So no shutdown when the app is quit.

#define VERSION_INFO "1.0.3" //released 10.05.2025

#include <iostream>
#include <QApplication>
#include "mainwindow.h"

using std::cout, std::endl;

int main(int argc, char *argv[]) {
    cout << "starting sleeptimer " << VERSION_INFO << endl;
    QApplication app(argc, argv);
    MainWindow win;
    win.show();

    int retval = QApplication::exec();//app.exec();
    cout << "ending sleeptimer with exit code " << retval << endl;
    return retval;
}