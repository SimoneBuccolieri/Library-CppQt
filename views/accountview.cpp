//
// Created by Simone Buccolieri on 20/03/25.
//

#include "accountview.h"

#include "bibliotecacontroller.h"

AccountView::AccountView(UserController *userController, BibliotecaController *bibliotecaController, QWidget *parent)
    : QWidget(parent), userController(userController), bibliotecaController(bibliotecaController) {

    User *user = userController->getLoggedUser();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QPushButton *backButton = new QPushButton("Indietro");
    mainLayout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &AccountView::back);

    // Intestazione account
    QLabel *usernameLabel = new QLabel("Account: " + user->username + "\nEcco i tuoi prestiti", this);
    usernameLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(usernameLabel);

    // Layout prestiti
    QFormLayout *formLayout = new QFormLayout();

    for (auto it = user->prestiti.begin(); it != user->prestiti.end(); ++it) {
        int itemId = it.key();
        int quantity = it.value();
        ItemModel *item = bibliotecaController->getItemById(itemId);

        if (!item) continue;

        QString infoText = "Titolo: " + item->getTitolo() + "\nQuantità: " + QString::number(quantity);
        QLabel *infoLabel = new QLabel(infoText, this);
        QLabel *iconLabel = new QLabel(item->getIcon(), this);
        formLayout->addRow(iconLabel, infoLabel);
    }

    mainLayout->addLayout(formLayout);
}

void AccountView::back() {
    emit backRequested();
}
