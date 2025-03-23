//
// Created by Simone Buccolieri on 18/03/25.
//

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
   }

MainWindow::~MainWindow() {
    delete userController;
    delete userModel;
    delete bibliotecaController;
    delete bibliotecaModel;
}

// Passa alla schermata di registrazione
void MainWindow::showRegisterView() {
    setFixedSize(300, 200);
    stackedWidget->setCurrentWidget(registerView);
}

// Torna alla schermata di login
void MainWindow::showLoginView() {
    setFixedSize(300, 200);
    stackedWidget->setCurrentWidget(loginView);
}

// Passa alla schermata principale dopo il login
void MainWindow::loginSuccessful() {
    setFixedSize(800, 600);

    mainView = new MainView(userController, bibliotecaController);
    stackedWidget->addWidget(mainView);
    connect(mainView, &MainView::logoutRequested, this, &MainWindow::showLoginView);
    stackedWidget->setCurrentWidget(mainView);
}