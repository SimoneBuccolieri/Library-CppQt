//
// Created by Simone Buccolieri on 16/03/25.
//

#include "bibliotecacontroller.h"

BibliotecaController::BibliotecaController(BibliotecaModel *model) {
    this->model = model;
}

void BibliotecaController::aggiungiLibro(QString titolo, QString autore, QString isbn) {
    model->aggiungiLibro(Libro(titolo, autore, isbn));
}

void BibliotecaController::rimuoviLibro(QString isbn) {
    model->rimuoviLibro(isbn);
}

QList<Libro> BibliotecaController::getLibri() const {
    return model->getLibri();
}
