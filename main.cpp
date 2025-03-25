#include <QApplication>
#include <QFileDialog>
#include "usercontroller.h"
#include "bibliotecacontroller.h"
#include "viewcontroller.h"
#include "globals.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString biblioteca = QFileDialog::getOpenFileName(nullptr, "Seleziona il file della biblioteca", "", "JSON (*.json)");
    if (!biblioteca.isEmpty()) {
        bibliotecaPath = biblioteca;
        qDebug() << "📁 File selezionato:" << bibliotecaPath;
    } else {
        bibliotecaPath = "biblioteca.json";
    }
    QString users = QFileDialog::getOpenFileName(nullptr, "Seleziona il file della biblioteca", "", "JSON (*.json)");
    if (!users.isEmpty()) {
        usersPath = users;
        qDebug() << "📁 File selezionato:" << usersPath;
    } else {
        usersPath = "users.json";
    }

    ViewController viewController;
    viewController.show();

    return a.exec();
}
