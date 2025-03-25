#include "initialfileselector.h"
#include "../globals.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>

InitialFileSelector::InitialFileSelector(QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Seleziona i file iniziali");

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Etichetta file biblioteca
    QLabel *libLabel = new QLabel("📚 Seleziona file biblioteca (.json):", this);
    layout->addWidget(libLabel);

    QPushButton *libButton = new QPushButton("Scegli file biblioteca", this);
    layout->addWidget(libButton);

    // Etichetta file utenti
    QLabel *userLabel = new QLabel("👤 Seleziona file utenti (.json):", this);
    layout->addWidget(userLabel);

    QPushButton *userButton = new QPushButton("Scegli file utenti", this);
    layout->addWidget(userButton);

    // Pulsante conferma
    QPushButton *okButton = new QPushButton("Conferma e continua", this);
    layout->addWidget(okButton);

    // Connessioni
    connect(libButton, &QPushButton::clicked, this, [libLabel]() {
        QString path = QFileDialog::getOpenFileName(nullptr, "File biblioteca", "", "JSON (*.json)");
        if (!path.isEmpty()) {
            bibliotecaPath = path;
            libLabel->setText("Biblioteca: " + path);
        }
    });

    connect(userButton, &QPushButton::clicked, this, [userLabel]() {
        QString path = QFileDialog::getOpenFileName(nullptr, "File utenti", "", "JSON (*.json)");
        if (!path.isEmpty()) {
            usersPath = path;
            userLabel->setText("Users: " + path);
        }
    });

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
}
