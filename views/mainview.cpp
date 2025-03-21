//
// Created by Simone Buccolieri on 18/03/25.
//

#include "mainview.h"

#include "../mainwindow.h"
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
        QString icon;
        if (dynamic_cast<BookModel*>(item)) icon = "📖 ";
        else if (dynamic_cast<FilmModel*>(item)) icon = "🎬 ";
        else if (dynamic_cast<MusicModel*>(item)) icon = "🎵 ";

        QListWidgetItem *listItem = new QListWidgetItem(
            icon + item->getTitolo() + " - " + item->getAutore() + " (Disponibili: " + QString::number(item->getQuantity()) + ")"
        );

        listItem->setData(Qt::UserRole, item->getId());
        libraryList->addItem(listItem);
    }

}

void MainView::onItemClicked(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();  // ✅ Ottiene l'ID dell'elemento cliccato
    qDebug() << "📌 Elemento cliccato con ID:" << id;

    // ✅ Crea e mostra la finestra ShowItem passando l'ID
    ShowItem *itemView = new ShowItem(bibliotecaController, id);
    itemView->show();
}
void MainView::onAccountClicked() {
    AccountView *accountView = new AccountView(userController, bibliotecaController);
    accountView->show();
}