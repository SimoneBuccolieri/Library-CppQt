#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(BibliotecaController *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(controller) {
    ui->setupUi(this);

    connect(ui->btnAggiungi, &QPushButton::clicked, this, &MainWindow::onAggiungiLibro);
    connect(ui->btnRimuovi, &QPushButton::clicked, this, &MainWindow::onRimuoviLibro);
    aggiornaTabella();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onAggiungiLibro() {
    QString titolo = ui->inputTitolo->text();
    QString autore = ui->inputAutore->text();
    QString isbn = ui->inputISBN->text();

    if (!titolo.isEmpty() && !autore.isEmpty() && !isbn.isEmpty()) {
        controller->aggiungiLibro(titolo, autore, isbn);
        aggiornaTabella();
    }
}

void MainWindow::onRimuoviLibro() {
    QString isbn = ui->inputISBN->text();
    controller->rimuoviLibro(isbn);
    aggiornaTabella();
}

void MainWindow::aggiornaTabella() {
    ui->tableLibri->setRowCount(0);
    QList<Libro> libri = controller->getLibri();

    for (int i = 0; i < libri.size(); ++i) {
        ui->tableLibri->insertRow(i);
        ui->tableLibri->setItem(i, 0, new QTableWidgetItem(libri[i].getTitolo()));
        ui->tableLibri->setItem(i, 1, new QTableWidgetItem(libri[i].getAutore()));
        ui->tableLibri->setItem(i, 2, new QTableWidgetItem(libri[i].getIsbn()));
    }
}
