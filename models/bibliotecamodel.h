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
    QVector<VideoModel> getFilms() const { return films; }
    QVector<MusicModel> getMusic() const { return music; }

private:
    QVector<BookModel> books;
    QVector<VideoModel> films;
    QVector<MusicModel> music;
};



#endif //BIBLIOTECAMODEL_H
