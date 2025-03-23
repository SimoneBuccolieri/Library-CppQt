#include <QApplication>
#include "usercontroller.h"
#include "bibliotecacontroller.h"
#include "viewcontroller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ViewController viewController;
    viewController.show();

    return a.exec();
}
