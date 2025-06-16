//
// Created by Simone Buccolieri on 19/03/25.
//

#include "showitem.h"
ShowItem::ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {
     item = bibliotecaController->getItemById(currentItemId);


    layout = new QVBoxLayout(this);
    QPushButton *backButton = new QPushButton("Indietro");
    layout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &ShowItem::back);
    formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    layout->addStretch();
    //Item
    QMap<QString, QString> dettagli = item->getDettagli();
    for (auto it = dettagli.begin(); it != dettagli.end(); ++it) {
        QLabel *keyLabel = new QLabel(it.key());
        QLabel *valueLabel = new QLabel(it.value());

        formLayout->addRow(keyLabel, valueLabel);
    }

    layout->addLayout(formLayout);
    layout->addStretch();
    QPushButton *prenotaButton = new QPushButton("Prenota", this);
    QPushButton *restituisciButton = new QPushButton("Restituisci", this);


    layout->addWidget(prenotaButton,0,Qt::AlignHCenter);
    layout->addWidget(restituisciButton,0,Qt::AlignHCenter);
    connect(prenotaButton, &QPushButton::clicked, this, &ShowItem::prenota);
    connect(restituisciButton, &QPushButton::clicked, this, &ShowItem::restituisci);

    connect(bibliotecaController, &BibliotecaController::datiAggiornati, this, &ShowItem::aggiornaDati);
    aggiornaDati();
}

void ShowItem::aggiornaDati() {
    if (!item) return;

    while (formLayout->count() > 0) {
    QLayoutItem *child = formLayout->takeAt(0);
    if (child) {
        delete child->widget();
        delete child;
        }
    }
    QMap<QString, QString> dettagli = item->getDettagli();
    for (auto it = dettagli.begin(); it != dettagli.end(); ++it) {
        QLabel *keyLabel = new QLabel(it.key());
        QLabel *valueLabel = new QLabel(it.value());

        formLayout->addRow(keyLabel, valueLabel);
    }
}


void ShowItem::prenota() {
    bibliotecaController->prenota(currentItemId);
    qDebug() << "Prenotazione effettuata per ID: " << currentItemId;;
}
void ShowItem::restituisci() {
    bibliotecaController->restituisci(currentItemId);
    qDebug() << "Restituzione effettuata per ID: " << currentItemId;;
}
void ShowItem::back() {
    bibliotecaController->update();
    emit backRequested();  // emetti segnale verso il controller
}