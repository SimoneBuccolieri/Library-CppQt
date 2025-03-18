//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecacontroller.h"
#include <QDebug>
#include <QDir>

BibliotecaController::BibliotecaController(BibliotecaModel &model)
    : bibliotecaModel(model) {}

void BibliotecaController::loadLibrary(const QString &filePath) {
    qDebug() << "📂 Directory di esecuzione:" << QDir::currentPath();
    bibliotecaModel.loadFromJson(filePath);
    qDebug() << "Dati caricati da:" << filePath;
}

QVector<BookModel> BibliotecaController::getBooks() const {
    return bibliotecaModel.getBooks();
}

QVector<FilmModel> BibliotecaController::getFilms() const {
    return bibliotecaModel.getFilms();
}

QVector<MusicModel> BibliotecaController::getMusic() const {
    return bibliotecaModel.getMusic();
}

// 🔍 Cerca libri per titolo o autore
QVector<BookModel> BibliotecaController::searchBooks(const QString &query) const {
    QVector<BookModel> results;
    for (const auto &book : bibliotecaModel.getBooks()) {
        if (book.getTitolo().contains(query, Qt::CaseInsensitive) ||
            book.getAutore().contains(query, Qt::CaseInsensitive)) {
            results.append(book);
            }
    }
    return results;
}

// 🔍 Cerca film per titolo o regista
QVector<FilmModel> BibliotecaController::searchFilms(const QString &query) const {
    QVector<FilmModel> results;
    for (const auto &film : bibliotecaModel.getFilms()) {
        if (film.getTitolo().contains(query, Qt::CaseInsensitive) ||
            film.getAutore().contains(query, Qt::CaseInsensitive)) {
            results.append(film);
            }
    }
    return results;
}

// 🔍 Cerca musica per titolo o artista
QVector<MusicModel> BibliotecaController::searchMusic(const QString &query) const {
    QVector<MusicModel> results;
    for (const auto &music : bibliotecaModel.getMusic()) {
        if (music.getTitolo().contains(query, Qt::CaseInsensitive) ||
            music.getAutore().contains(query, Qt::CaseInsensitive)) {
            results.append(music);
            }
    }
    return results;
}