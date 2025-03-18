//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecamodel.h"
#include <QJsonArray>
#include <QDebug>
BibliotecaModel::BibliotecaModel() {
    qDebug() << "BibliotecaModel inizializzato!";
}
void BibliotecaModel::loadFromJson(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Errore apertura file JSON!";
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (!document.isArray()) {
        qDebug() << "Formato JSON errato!";
        return;
    }

    QJsonArray jsonArray = document.array();
    for (const QJsonValue &value : jsonArray) {
        if (!value.isObject()) continue;

        QJsonObject jsonObj = value.toObject();
        QString tipo = jsonObj["tipologia"].toString();  // ✅ Controlla il tipo

        if (tipo == "book") {
            books.append(BookModel(jsonObj));
        } else if (tipo == "film") {
            films.append(FilmModel(jsonObj));
        } else if (tipo == "music") {
            music.append(MusicModel(jsonObj));
        } else {
            qDebug() << "Tipologia sconosciuta:" << tipo;
        }
    }
}