//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BIBLIOTECACONTROLLER_H
#define BIBLIOTECACONTROLLER_H
#include "../models/bibliotecamodel.h"


class BibliotecaController {
public:
    explicit BibliotecaController(BibliotecaModel &model);  // ✅ Usa il modello esistente

    void loadLibrary(const QString &filePath);  // ✅ Carica i dati JSON
    QVector<BookModel> getBooks() const;  // ✅ Restituisce i libri
    QVector<FilmModel> getFilms() const;  // ✅ Restituisce i film
    QVector<MusicModel> getMusic() const;  // ✅ Restituisce la musica

    QVector<BookModel> searchBooks(const QString &query) const;  // 🔍 Cerca libri
    QVector<FilmModel> searchFilms(const QString &query) const;
    QVector<MusicModel> searchMusic(const QString &query) const;

    ItemModel* getItemById(int id);
private:
    BibliotecaModel &bibliotecaModel;
};



#endif //BIBLIOTECACONTROLLER_H
