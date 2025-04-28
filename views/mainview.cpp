//
// Created by Simone Buccolieri on 18/03/25.
//

#include "mainview.h"

#include <QLineEdit>

MainView::MainView(UserController *userController, BibliotecaController *bibliotecaController, QMainWindow *parent) : QMainWindow(parent), userController(userController), bibliotecaController(bibliotecaController) {
    setWindowTitle("Biblioteca");
    QToolBar *toolBar = addToolBar("ToolBar");
    toolBar->setMovable(false);
    toolBar->setFixedHeight(40);

    logoutButton = new QPushButton("Logout");
    toolBar->addWidget(logoutButton);
    accountButton = new QPushButton("Account");
    toolBar->addWidget(accountButton);

    if (userController->getLoggedUser()->username == "admin") {
        addItemButton = new QPushButton("Aggiungi Elemento");
        toolBar->addWidget(addItemButton);
        connect(addItemButton, &QPushButton::clicked, this, &MainView::onAddItemClicked);
    }
    searchBox = new QLineEdit(this);
    toolBar->addWidget(searchBox);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    welcomeLabel = new QLabel(this);
    User *currentUser = userController->getLoggedUser();

    if (currentUser) {
        welcomeLabel->setText(QString("Benvenuto %1 nella Home!").arg(currentUser->username));
    } else {
        welcomeLabel->setText("Benvenuto!");
    }

    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    libraryList = new QListWidget(this);
    layout->addWidget(libraryList);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(logoutButton, &QPushButton::clicked, this, &MainView::onLogoutClicked);
    connect(accountButton, &QPushButton::clicked, this, &MainView::onAccountClicked);
    connect(bibliotecaController, &BibliotecaController::datiAggiornati, this, &MainView::aggiornaDati);
    connect(libraryList, &QListWidget::itemClicked, this, &MainView::onItemClicked);
    connect(searchBox, &QLineEdit::textChanged, this, &MainView::srtSearchUpdate);
    aggiornaDati();
}

void MainView::onLogoutClicked() {
    emit logoutRequested();
}
void MainView::srtSearchUpdate(const QString &text) {
    libraryList->clear();
    if (text.isEmpty()) {
        aggiornaDati();
        return;
    }
    for (const auto &item : bibliotecaController->getItems()) {
        if (item->getTitolo().contains(text, Qt::CaseInsensitive)) {
            QListWidgetItem *listItem = new QListWidgetItem(item->getIcon() + item->getTitolo() + " - " + item->getAutore() + " (Disponibili: " + QString::number(item->getQuantity()) + ")");
            listItem->setData(Qt::UserRole, item->getId());
            libraryList->addItem(listItem);
        }
    }

}
void MainView::aggiornaDati() {
    if (!libraryList) return;
    libraryList->clear();

    for (const auto &item : bibliotecaController->getItems()) {

        QListWidgetItem *listItem = new QListWidgetItem(item->getIcon() + item->getTitolo() + " - " + item->getAutore() + " (Disponibili: " + QString::number(item->getQuantity()) + ")");
        listItem->setData(Qt::UserRole, item->getId());
        libraryList->addItem(listItem);
    }

}

void MainView::onItemClicked(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();
    emit richiestaDettagliItem(id);
}
void MainView::onAccountClicked() {
    emit richiestaAccount();
}
void MainView::onAddItemClicked() {
    emit richiestaAddItem();
}