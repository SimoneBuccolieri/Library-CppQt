#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Controller/bibliotecacontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    BibliotecaController *controller;

public:
    explicit MainWindow(BibliotecaController *controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAggiungiLibro();
    void onRimuoviLibro();
    void aggiornaTabella();
    void onSalvaSuFile();
    void onCaricaDaFile();
};

#endif // MAINWINDOW_H
