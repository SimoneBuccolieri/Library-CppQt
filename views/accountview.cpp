#include "accountview.h"
#include "bibliotecacontroller.h"

AccountView::AccountView(UserController *userController, BibliotecaController *bibliotecaController, QWidget *parent)
    : QWidget(parent), userController(userController), bibliotecaController(bibliotecaController) {

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QPushButton *backButton = new QPushButton("Indietro", this);
    mainLayout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &AccountView::back);

    QLabel *usernameLabel = new QLabel("Account: " + userController->getLoggedUser()->username + "\nEcco i tuoi prestiti", this);
    usernameLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(usernameLabel);

    listWidget = new QListWidget(this);
    mainLayout->addWidget(listWidget);

    aggiornaDati();  // Primo caricamento della lista
}

void AccountView::aggiornaDati() {
    listWidget->clear();  // Pulisci la lista

    User *user = userController->getLoggedUser();
    for (auto it = user->prestiti.begin(); it != user->prestiti.end(); ++it) {
        int itemId = it.key();
        int quantity = it.value();
        ItemModel *item = bibliotecaController->getItemById(itemId);

        if (!item) continue;

        QListWidgetItem *listItem = new QListWidgetItem(listWidget);

        QWidget *itemWidget = new QWidget(this);
        QHBoxLayout *layout = new QHBoxLayout(itemWidget);

        QLabel *iconLabel = new QLabel(item->getIcon(), this);
        QLabel *infoLabel = new QLabel("Titolo: " + item->getTitolo() + "\nQuantità: " + QString::number(quantity), this);
        QPushButton *restituisciButton = new QPushButton("Restituisci", this);

        layout->addWidget(iconLabel);
        layout->addWidget(infoLabel);
        layout->addStretch();
        layout->addWidget(restituisciButton);

        itemWidget->setLayout(layout);
        listItem->setSizeHint(itemWidget->sizeHint()); // Imposta la dimensione corretta della riga

        listWidget->addItem(listItem);
        listWidget->setItemWidget(listItem, itemWidget);

        // Collega il bottone al metodo restituzione
        connect(restituisciButton, &QPushButton::clicked, this, [this, itemId]() {
            bibliotecaController->restituisci(itemId);
            aggiornaDati();
        });
    }
}

void AccountView::back() {
    emit backRequested();
}
