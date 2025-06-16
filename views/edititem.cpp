//
// Created by Simone Buccolieri on 22/03/25.
//

#include "edititem.h"
EditItem::EditItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {
     item = bibliotecaController->getItemById(currentItemId);


    QVBoxLayout *layout = new QVBoxLayout(this);
    formLayout = new QFormLayout();

    QPushButton *backButton = new QPushButton("Indietro");
    layout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &EditItem::back);
    //Item
    QMap<QString, QString> dettagli = item->getDettagli();

    for (auto it = dettagli.begin(); it != dettagli.end(); ++it) {
        QLineEdit *edit = new QLineEdit(it.value(), this);

        if (it.key() == "Icona") {
            edit->setReadOnly(true);
        }

        formLayout->addRow(it.key(), edit);
        campi[it.key()] = edit;
    }
    layout->addLayout(formLayout);
    QPushButton *saveButton = new QPushButton("Salva", this);
    QPushButton *deleteButton = new QPushButton("Elimina", this);
    layout->addWidget(saveButton,0,Qt::AlignHCenter);
    layout->addWidget(deleteButton,0,Qt::AlignHCenter);
    connect(saveButton, &QPushButton::clicked, this, &EditItem::saveClicked);
    connect(deleteButton, &QPushButton::clicked, this, &EditItem::eliminaClicked);


}
void EditItem::back() {
    bibliotecaController->update();
    emit backRequested();  // emetti segnale verso il controller
}
void EditItem::saveClicked() {
    QMap<QString, QString> dati;
    for (auto it = campi.begin(); it != campi.end(); ++it) {
        dati[it.key()] = it.value()->text();
    }
    item->setDettagli(dati);

    bibliotecaController->update();
    back();
}

void EditItem::eliminaClicked() {
    bibliotecaController->deleteId(currentItemId);
    bibliotecaController->update();
    back();
}