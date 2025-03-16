//
// Created by Simone Buccolieri on 16/03/25.
//

#include "libro.h"

Libro::Libro(QString titolo, QString autore, QString isbn)
    : titolo(titolo), autore(autore), isbn(isbn), disponibile(true) {}

QString Libro::getTitolo() const { return titolo; }
QString Libro::getAutore() const { return autore; }
QString Libro::getIsbn() const { return isbn; }
bool Libro::isDisponibile() const { return disponibile; }
void Libro::setDisponibile(bool stato) { disponibile = stato; }
