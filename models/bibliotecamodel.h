//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BIBLIOTECAMODEL_H
#define BIBLIOTECAMODEL_H

#include "bookmodel.h"
#include "filmmodel.h"
#include "musicmodel.h"
#include <QVector>
#include <QJsonDocument>
#include <QFile>

class BibliotecaModel {
public:
    BibliotecaModel();
    void loadFromJson(const QString &filePath);  // ✅ Carica tutti i dati

    QVector<BookModel> getBooks() const { return books; }
    QVector<FilmModel> getFilms() const { return films; }
    QVector<MusicModel> getMusic() const { return music; }
    QVector<ItemModel*> getItemModel() const { return items; }
private:
    QVector<BookModel> books;
    QVector<FilmModel> films;
    QVector<MusicModel> music;
    QVector<ItemModel*> items;
};



#endif //BIBLIOTECAMODEL_H
