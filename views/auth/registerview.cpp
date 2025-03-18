//
// Created by Simone Buccolieri on 18/03/25.
//

#include "registerview.h"
#include <QMessageBox>
#include <QLabel>

RegisterView::RegisterView(UserController *controller, QWidget *parent)
    : QWidget(parent), userController(controller) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    loginButton = new QPushButton("Login");
    registerButton = new QPushButton("Registrati");

    QLabel *titleLabel = new QLabel("Register Page", this);
    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(registerButton);

    QLabel *gotologin = new QLabel("Hai gia un account? Accedi!", this);
    layout->addWidget(gotologin, 0, Qt::AlignHCenter);
    layout->addWidget(loginButton);


    connect(loginButton, &QPushButton::clicked, this, &RegisterView::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &RegisterView::onRegisterClicked);
}

void RegisterView::onRegisterClicked() {
    if (userController->registerUser(usernameInput->text(), passwordInput->text())) {
        emit registerSuccess();
    } else {
        QMessageBox::warning(this, "Errore", "");
    }
}

void RegisterView::onLoginClicked() {
    emit loginRequested();
}