//
// Created by Simone Buccolieri on 16/03/25.
//

#include "bibliotecamodel.h"

void BibliotecaModel::aggiungiLibro(const Libro &libro) {
    libri.append(libro);
}

void BibliotecaModel::rimuoviLibro(const QString &isbn) {
    for (int i = 0; i < libri.size(); ++i) {
        if (libri[i].getIsbn() == isbn) {
            libri.removeAt(i);
            break;
        }
    }
}

QList<Libro> BibliotecaModel::getLibri() const {
    return libri;
}
