//
// Created by Simone Buccolieri on 16/03/25.
//

#ifndef LIBRO_H
#define LIBRO_H

#include <QString>

class Libro {
private:
    QString titolo;
    QString autore;
    QString isbn;
    bool disponibile;

public:
    Libro(QString titolo, QString autore, QString isbn);
    QString getTitolo() const;
    QString getAutore() const;
    QString getIsbn() const;
    bool isDisponibile() const;
    void setDisponibile(bool stato);
};

#endif // LIBRO_H
