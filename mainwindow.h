//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "views/auth/loginview.h"
#include "views/auth/registerview.h"
#include "views/mainview.h"
#include "controllers/usercontroller.h"
#include "controllers/bibliotecacontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRegisterView();
    void showLoginView();
    void loginSuccessful();

private:
    QStackedWidget *stackedWidget;
    LoginView *loginView;
    RegisterView *registerView;
    MainView *mainView;
    UserController *userController;
    UserModel *userModel;

    BibliotecaModel *bibliotecaModel;
    BibliotecaController *bibliotecaController;
};

#endif // MAINWINDOW_H
