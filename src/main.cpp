//
//title:    sleeptimer
//author:   Christian Schmeisser
//data:     09.05.2025
//

#define VERSION_INFO "0.1"

#include <iostream>
#include <QApplication>
#include <QPushButton>

using std::cout, std::endl;

int main(int argc, char *argv[]) {
    cout << "starting sleeptimer " << VERSION_INFO << endl;

    QApplication app(argc, argv);
    QPushButton button("Hello world!", nullptr);

    button.resize(200, 100);
    button.show();

    return QApplication::exec();
}