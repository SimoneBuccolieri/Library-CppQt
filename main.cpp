#include <QApplication>
#include <QFileDialog>
#include "usercontroller.h"
#include "bibliotecacontroller.h"
#include "viewcontroller.h"
#include "globals.h"
#include "initialfileselector.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    InitialFileSelector selector;
    if (selector.exec() == QDialog::Rejected) {
        return 0;  // utente ha chiuso o annullato
    }


    ViewController viewController;
    viewController.show();

    return a.exec();
}
