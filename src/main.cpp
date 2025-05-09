//
//title:        sleeptimer
//author:       Christian Schmeisser
//date:         09.05.2025
//description:  A simple desktop app to set, start and stop a shutdown timer in windows.
//              The timer runs entirely within the app and shutdown is only provoked
//              when the timer ends. So no shutdown when the app is quit.
//

#define VERSION_INFO "0.1"

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>

using std::cout, std::endl;

int main(int argc, char *argv[]) {
    cout << "starting sleeptimer " << VERSION_INFO << endl;

    QApplication app(argc, argv);

    QPushButton button_startstop("Start timer", nullptr);
    QLineEdit edit_timer("00:00:00", nullptr);

    //edit_timer.show();
    button_startstop.resize(100, 50);
    button_startstop.show();

    return QApplication::exec();
}