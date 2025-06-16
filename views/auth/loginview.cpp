//
// Created by Simone Buccolieri on 18/03/25.
//

#include "loginview.h"
#include <QMessageBox>
#include <QLabel>
LoginView::LoginView(UserController *controller, QWidget *parent)
    : QWidget(parent), userController(controller) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    QFormLayout *form = new QFormLayout();

    usernameInput = new QLineEdit();
    passwordInput = new QLineEdit();
    loginButton = new QPushButton("Login");
    registerButton = new QPushButton("Registrati");

    QLabel *titleLabel = new QLabel("Login Page", this);
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

    form->addRow(loginButton);
    form->addItem(new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Fixed));
    QLabel *gotoregister = new QLabel("Non hai un account? Registrati!", this);
    gotoregister->setAlignment(Qt::AlignCenter);
    form->addRow(gotoregister);
    form->addRow(registerButton);

    layout->addLayout(form);
    layout->addStretch();
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
