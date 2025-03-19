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
        QListWidgetItem *item = new QListWidgetItem("📖 " + book.getTitolo() + " - " + book.getAutore() + " - " + QString::number(book.getQuantity()));
        item->setData(Qt::UserRole, book.getId());  // ✅ Salva l'ID
        libraryList->addItem(item);
    }

    for (const auto &film : bibliotecaController->getFilms()) {
        QListWidgetItem *item = new QListWidgetItem("🎬 " + film.getTitolo() + " - " + film.getAutore());
        item->setData(Qt::UserRole, film.getId());  // ✅ Salva l'ID
        libraryList->addItem(item);
    }

    for (const auto &music : bibliotecaController->getMusic()) {
        QListWidgetItem *item = new QListWidgetItem("🎵 " + music.getTitolo() + " - " + music.getAutore());
        item->setData(Qt::UserRole, music.getId());  // ✅ Salva l'ID
        libraryList->addItem(item);
    }

    connect(libraryList, &QListWidget::itemClicked, this, &MainView::onItemClicked);
}

void MainView::onItemClicked(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();  // ✅ Ottiene l'ID dell'elemento cliccato
    qDebug() << "📌 Elemento cliccato con ID:" << id;

    // ✅ Crea e mostra la finestra ShowItem passando l'ID
    ShowItem *itemView = new ShowItem(bibliotecaController, id);
    itemView->show();
}