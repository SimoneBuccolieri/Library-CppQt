//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef LOGINVIEW_H
#define LOGINVIEW_H



#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "usercontroller.h"

class LoginView : public QWidget {
    Q_OBJECT

public:
    explicit LoginView(UserController *controller, QWidget *parent = nullptr);

signals:
    void registerRequested();
    void loginSuccess();

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

#endif // LOGINVIEW_H