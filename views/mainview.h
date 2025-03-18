//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>

#include "usercontroller.h"
#include "bibliotecacontroller.h"

class MainView : public QMainWindow {
    Q_OBJECT

public:
    explicit MainView(UserController *userController,BibliotecaController *bibliotecaController, QMainWindow *parent = nullptr);

signals:
    void logoutRequested();

private slots:
    void onLogoutClicked();

private:
    QLabel *welcomeLabel;
    QPushButton *logoutButton;
    UserController *userController;

    BibliotecaController *bibliotecaController;
    QListWidget *libraryList;

    void showLibrary();
};


#endif //MAINVIEW_H
