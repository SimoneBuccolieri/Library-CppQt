//
// Created by Simone Buccolieri on 16/03/25.
//

#ifndef BIBLIOTECACONTROLLER_H
#define BIBLIOTECACONTROLLER_H

#include "../Model/bibliotecamodel.h"

class BibliotecaController {
private:
    BibliotecaModel *model;

public:
    BibliotecaController(BibliotecaModel *model);
    void aggiungiLibro(QString titolo, QString autore, QString isbn);
    void rimuoviLibro(QString isbn);
    QList<Libro> getLibri() const;
    void salvaSuFile(const QString &filename);
    void caricaDaFile(const QString &filename);
};

#endif // BIBLIOTECACONTROLLER_H
