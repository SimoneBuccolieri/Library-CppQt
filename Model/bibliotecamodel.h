//
// Created by Simone Buccolieri on 16/03/25.
//

#ifndef BIBLIOTECAMODEL_H
#define BIBLIOTECAMODEL_H

#include <QList>
#include "libro.h"

class BibliotecaModel {
private:
    QList<Libro> libri;

public:
    void aggiungiLibro(const Libro &libro);
    void rimuoviLibro(const QString &isbn);
    QList<Libro> getLibri() const;
};

#endif // BIBLIOTECAMODEL_H
