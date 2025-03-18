//
// Created by Simone Buccolieri on 18/03/25.
//

#include "loginview.h"
#include <QMessageBox>
#include <QLabel>
LoginView::LoginView(UserController *controller, QWidget *parent)
    : QWidget(parent), userController(controller) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    loginButton = new QPushButton("Login");
    registerButton = new QPushButton("Registrati");

    QLabel *titleLabel = new QLabel("Login Page", this);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    QLabel *gotoregister = new QLabel("Non hai un account? Registrati!", this);
    layout->addWidget(gotoregister, 0, Qt::AlignHCenter);
    layout->addWidget(registerButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginView::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginView::onRegisterClicked);
}

void LoginView::onLoginClicked() {
    if (userController->login(usernameInput->text(), passwordInput->text())) {
        emit loginSuccess();
    } else {
        QMessageBox::warning(this, "Errore", "Credenziali errate!");
    }
}

void LoginView::onRegisterClicked() {
    emit registerRequested();
}
