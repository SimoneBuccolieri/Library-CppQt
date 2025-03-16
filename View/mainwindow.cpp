#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>

MainWindow::MainWindow(BibliotecaController *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(controller) {
    ui->setupUi(this);

    connect(ui->btnAggiungi, &QPushButton::clicked, this, &MainWindow::onAggiungiLibro);
    connect(ui->btnRimuovi, &QPushButton::clicked, this, &MainWindow::onRimuoviLibro);
    connect(ui->btnSalva, &QPushButton::clicked, this, &MainWindow::onSalvaSuFile);
    connect(ui->btnCarica, &QPushButton::clicked, this, &MainWindow::onCaricaDaFile);

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

void MainWindow::onSalvaSuFile() {
    QString filename = QFileDialog::getSaveFileName(this, "Salva Libreria", "", "CSV Files (*.csv);;Text Files (*.txt)");
    if (!filename.isEmpty()) {
        controller->salvaSuFile(filename);
    }
}

void MainWindow::onCaricaDaFile() {
    QString filename = QFileDialog::getOpenFileName(this, "Carica Libreria", "", "CSV Files (*.csv);;Text Files (*.txt)");
    if (!filename.isEmpty()) {
        controller->caricaDaFile(filename);
        aggiornaTabella();
    }
}
