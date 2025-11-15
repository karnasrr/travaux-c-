#include <QApplication>
#include "lcdnumber.h"

using namespace Examples;

int main(int argc, char *argv[]) {
    auto application = QApplication {argc, argv};
    auto window1 = Window1 {};
    window1.show();

    auto window2 = Window2 {};
    window2.show();

    return application.exec();
}
