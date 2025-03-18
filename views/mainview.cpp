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

    showLibrary();  // ✅ Chiama la funzione
}

void MainView::onLogoutClicked() {
    emit logoutRequested();
}
void MainView::showLibrary() {
    if (!libraryList) return;
    libraryList->clear();

    for (const auto &book : bibliotecaController->getBooks()) {
        libraryList->addItem("📖 " + book.getTitolo() + " - " + book.getAutore() + " - " + QString::number(book.getQuantity()));
    }

    for (const auto &film : bibliotecaController->getFilms()) {
        libraryList->addItem("🎬 " + film.getTitolo() + " - " + film.getAutore() + " - " + QString::number(film.getQuantity()));
    }

    for (const auto &music : bibliotecaController->getMusic()) {
        libraryList->addItem("🎵 " + music.getTitolo() + " - " + music.getAutore() + " - " + QString::number(music.getQuantity()));
    }
}