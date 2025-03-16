#include "View/mainwindow.h"

#include <QApplication>

#include "Model/bibliotecamodel.h"
#include "Controller/bibliotecacontroller.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    BibliotecaModel model;
    BibliotecaController controller(&model);
    MainWindow w(&controller);

    w.show();
    return a.exec();
}
