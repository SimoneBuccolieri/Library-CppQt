//
// Created by Simone Buccolieri on 18/03/25.
//

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    bibliotecaModel = new BibliotecaModel();
    bibliotecaController = new BibliotecaController(*bibliotecaModel);
    bibliotecaController->loadLibrary("biblioteca.json");

    userModel = new UserModel();
    userController = new UserController(*userModel);

    loginView = new LoginView(userController);
    registerView = new RegisterView(userController);

    stackedWidget->addWidget(loginView);
    stackedWidget->addWidget(registerView);

    connect(loginView, &LoginView::registerRequested, this, &MainWindow::showRegisterView);
    connect(registerView, &RegisterView::loginRequested, this, &MainWindow::showLoginView);
    connect(loginView, &LoginView::loginSuccess, this, &MainWindow::loginSuccessful);
    connect(registerView, &RegisterView::registerSuccess, this, &MainWindow::loginSuccessful);

    showLoginView();
}

MainWindow::~MainWindow() {
    delete stackedWidget;
    delete loginView;
    delete registerView;
    delete mainView;
    delete userController;
    delete userModel;
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