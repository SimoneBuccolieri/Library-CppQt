//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef REGISTERVIEW_H
#define REGISTERVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "usercontroller.h"

class RegisterView : public QWidget {
    Q_OBJECT

public:
    explicit RegisterView(UserController *controller, QWidget *parent = nullptr);

signals:
    void loginRequested();
    void registerSuccess();

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QPushButton *registerButton;
    UserController *userController;
};

#endif //REGISTERVIEW_H
