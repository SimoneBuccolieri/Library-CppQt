//
// Created by Simone Buccolieri on 18/03/25.
//

#include "mainview.h"

MainView::MainView(UserController *userController, BibliotecaController *bibliotecaController, QMainWindow *parent) : QMainWindow(parent), userController(userController), bibliotecaController(bibliotecaController) {
    setWindowTitle("Biblioteca");
    setFixedSize(800, 600);

    // Creazione della toolbar e pulsante logout
    QToolBar *toolBar = addToolBar("ToolBar");
    toolBar->setMovable(false);
    toolBar->setFixedHeight(40);

    logoutButton = new QPushButton("Logout");
    toolBar->addWidget(logoutButton);
    accountButton = new QPushButton("Account");
    toolBar->addWidget(accountButton);
    qDebug() << userController->getLoggedUser()->username;
    if (userController->getLoggedUser()->username == "admin") {
        addItemButton = new QPushButton("Aggiungi Elemento");
        toolBar->addWidget(addItemButton);
    }

    // ✅ Creazione del widget centrale
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // ✅ Creazione della label di benvenuto
    welcomeLabel = new QLabel(this);
    User *currentUser = userController->getLoggedUser();

    if (currentUser) {
        welcomeLabel->setText(QString("Benvenuto %1 nella Home!").arg(currentUser->username));
    } else {
        welcomeLabel->setText("Benvenuto!");
    }

    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);  // ✅ Ora è nel layout principale

    libraryList = new QListWidget(this);
    layout->addWidget(libraryList);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);  // ✅ Imposta il widget centrale

    connect(logoutButton, &QPushButton::clicked, this, &MainView::onLogoutClicked);
    connect(accountButton, &QPushButton::clicked, this, &MainView::onAccountClicked);
    connect(addItemButton, &QPushButton::clicked, this, &MainView::onAddItemClicked);
    connect(bibliotecaController, &BibliotecaController::datiAggiornati, this, &MainView::aggiornaDati);
    connect(libraryList, &QListWidget::itemClicked, this, &MainView::onItemClicked);
    aggiornaDati();  // ✅ Chiama la funzione
}

void MainView::onLogoutClicked() {
    emit logoutRequested();
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