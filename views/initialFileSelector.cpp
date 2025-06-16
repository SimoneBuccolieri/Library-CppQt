#include "initialfileselector.h"
#include "../globals.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>

InitialFileSelector::InitialFileSelector(QWidget *parent)
    : QDialog(parent) {

    setWindowTitle("Seleziona i file iniziali");
    setMinimumSize(500, 700);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    QFormLayout *form = new QFormLayout();
    // Etichetta file biblioteca
    QLabel *libLabel = new QLabel("📚 Seleziona file biblioteca (.json):", this);
    libLabel->setAlignment(Qt::AlignCenter);
    libLabel->setWordWrap(true);
    form->addRow(libLabel);

    QPushButton *libButton = new QPushButton("Scegli file biblioteca", this);
    form->addRow(libButton);

    // Etichetta file utenti
    QLabel *userLabel = new QLabel("👤 Seleziona file utenti (.json):", this);
    userLabel->setAlignment(Qt::AlignCenter);
    userLabel->setWordWrap(true);
    form->addRow(userLabel);

    QPushButton *userButton = new QPushButton("Scegli file utenti", this);
    form->addRow(userButton);

    // Pulsante conferma
    QPushButton *okButton = new QPushButton("Conferma e continua", this);
    form->addItem(new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Fixed));
    form->addRow(okButton);

    layout->addLayout(form);
    layout->addStretch();
    // Connessioni corrette
    connect(libButton, &QPushButton::clicked, this, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "File biblioteca", "", "JSON (*.json)");
        if (!path.isEmpty()) {
            bibliotecaPath = path;
            libLabel->setText("📚 Biblioteca: " + path);
        }
    });

    connect(userButton, &QPushButton::clicked, this, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "File utenti", "", "JSON (*.json)");
        if (!path.isEmpty()) {
            usersPath = path;
            userLabel->setText("👤 Utenti: " + path);

        }
    });

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
}
