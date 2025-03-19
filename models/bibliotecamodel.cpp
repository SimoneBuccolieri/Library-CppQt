//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecamodel.h"
#include <QJsonArray>
#include <QDebug>
BibliotecaModel::BibliotecaModel() {
    qDebug() << "BibliotecaModel inizializzato!";
}
void BibliotecaModel::loadFromJson() {
    QFile file("biblioteca.json");
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
            items.append(new BookModel(jsonObj));
        } else if (tipo == "film") {
            items.append(new FilmModel(jsonObj));
        } else if (tipo == "music") {
            items.append(new MusicModel(jsonObj));
        } else {
            qDebug() << "Tipologia sconosciuta:" << tipo;
        }
    }
}
void BibliotecaModel::saveToJson() {
    QJsonArray jsonArray;

    for (const ItemModel* item : items) {
        QJsonObject jsonObj;
        jsonObj["id"] = item->getId();
        jsonObj["title"] = item->getTitolo();
        jsonObj["author"] = item->getAutore();
        jsonObj["quantity"] = item->getQuantity();  // ✅ Salva la quantità aggiornata
        jsonObj["releaseYear"] = item->getReleaseYear();
        jsonObj["genre"] = item->getGenre();

        if (const BookModel* book = dynamic_cast<const BookModel*>(item)) {
            jsonObj["tipologia"] = "book";
            jsonObj["publisher"] = book->getPublisher();
            jsonObj["ISBN"] = book->getISBN();
            jsonObj["pageCount"] = book->getPageCount();
            jsonObj["language"] = book->getLanguage();
        }
        else if (const FilmModel* film = dynamic_cast<const FilmModel*>(item)) {
            jsonObj["tipologia"] = "film";
            jsonObj["director"] = film->getDirector();
            jsonObj["duration"] = film->getDuration();
            jsonObj["rating"] = film->getRating();
            jsonObj["language"] = film->getLanguage();
        }
        else if (const MusicModel* music = dynamic_cast<const MusicModel*>(item)) {
            jsonObj["tipologia"] = "music";
            jsonObj["album"] = music->getAlbum();
            jsonObj["duration"] = music->getDuration();
            jsonObj["recordLabel"] = music->getRecordLabel();
            jsonObj["format"] = music->getFormat();
        }
        jsonArray.append(jsonObj);
    }

    QJsonDocument document(jsonArray);
    QFile file("biblioteca.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "❌ Errore salvataggio JSON biblioteca!";
        return;
    }

    file.write(document.toJson());
    file.close();

    qDebug() << "✅ Dati biblioteca salvati con successo!";
}
