//
// Created by Simone Buccolieri on 23/03/25.
//

#include "createitem.h"
CreateItem::CreateItem(BibliotecaController *bibliotecaController, QWidget *parent): bibliotecaController(bibliotecaController), QWidget(parent){
    layout = new QVBoxLayout(this);
    QPushButton *backButton = new QPushButton("Indietro");
    layout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &CreateItem::back);

    type = new QComboBox(this);
    type->addItem("book");
    type->addItem("film");
    type->addItem("music");

    layout->addWidget(type);


    QPushButton *createButton = new QPushButton("Crea");
    layout->addWidget(createButton, 0, Qt::AlignLeft);
    connect(createButton, &QPushButton::clicked, this, &CreateItem::crea);

  }
void CreateItem::back() {
    bibliotecaController->update();
    emit backRequested();  // emetti segnale verso il controller
}
void CreateItem::crea() {
    bibliotecaController->createItem(type->currentText());
    emit creaRequested(bibliotecaController->getLastId());  // emetti segnale verso il controller
}