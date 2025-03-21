//
// Created by Simone Buccolieri on 20/03/25.
//

#include "accountview.h"

#include "bibliotecacontroller.h"

AccountView::AccountView(UserController *userController, BibliotecaController *bibliotecaController, QWidget *parent)
    : QWidget(parent), userController(userController), bibliotecaController(bibliotecaController){

    User *user = userController->getLoggedUser();

    layout = new QVBoxLayout(this);

    usernameLabel = new QLabel("Account: "+ user->username,this);
    layout->addWidget(usernameLabel, 0, Qt::AlignHCenter);
    if (user->prestiti.isEmpty()) {
        QLabel *noPrestitiLabel = new QLabel("Nessun prestito", this);
        layout->addWidget(noPrestitiLabel, 0, Qt::AlignHCenter);
        return;
    }
    for (auto it = user->prestiti.begin(); it != user->prestiti.end(); ++it) {
        QHBoxLayout *display = new QHBoxLayout();
        int itemId = it.key();
        ItemModel *item = bibliotecaController->getItemById(itemId);
        int quantity = it.value();
        if (!item) {  // ✅ Se item è nullo, evita di usarlo
            continue;
        }
        QLabel *titleLabel = new QLabel(item->getTitolo(), this);
        QLabel *PresiLabel = new QLabel("Quantità: "+ QString::number(quantity), this);
        display->addWidget(titleLabel, 0, Qt::AlignHCenter);
        display->addWidget(PresiLabel, 0, Qt::AlignHCenter);
        layout->addLayout(display);
    }


};