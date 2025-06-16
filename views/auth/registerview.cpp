//
// Created by Simone Buccolieri on 18/03/25.
//

#include "registerview.h"
#include <QMessageBox>
#include <QLabel>

RegisterView::RegisterView(UserController *controller, QWidget *parent)
    : QWidget(parent), userController(controller) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    QFormLayout *form = new QFormLayout();

    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    loginButton = new QPushButton("Login");
    registerButton = new QPushButton("Registrati");

    QLabel *titleLabel = new QLabel("Register Page", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    form->addRow(titleLabel);
    form->addItem(new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Fixed));

    QLabel *userLabel = new QLabel("Username", this);
    userLabel->setAlignment(Qt::AlignCenter);
    form->addRow(userLabel);
    form->addRow(usernameInput);

    QLabel *passLabel = new QLabel("Password", this);
    passLabel->setAlignment(Qt::AlignCenter);
    form->addRow(passLabel);
    form->addRow(passwordInput);

    form->addRow(registerButton);
    form->addItem(new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Fixed));

    QLabel *gotologin = new QLabel("Hai gia un account? Accedi!", this);
    gotologin->setAlignment(Qt::AlignCenter);
    form->addRow(gotologin);
    form->addRow(loginButton);

    layout->addLayout(form);
    layout->addStretch();
    connect(loginButton, &QPushButton::clicked, this, &RegisterView::onLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &RegisterView::onRegisterClicked);
}

void RegisterView::onRegisterClicked() {
    if (userController->registerUser(usernameInput->text(), passwordInput->text())) {
        emit registerSuccess();
    } else {
        QMessageBox::warning(this, "Errore", "Riempire username e password");
    }
}

void RegisterView::onLoginClicked() {
    emit loginRequested();
}