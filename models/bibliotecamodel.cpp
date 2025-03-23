//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecamodel.h"
#include <QJsonArray>
#include <QDebug>

#include "bibliotecacontroller.h"

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
        lastId = jsonObj["id"].toInt();
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
        jsonObj["icon"] = item->getIcon();

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
void BibliotecaModel::deleteId(int id) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i]->getId() == id) {
            delete items[i];           // libera la memoria
            items.removeAt(i);         // rimuove dall'elenco
            return;                    // esce dopo averlo trovato
        }
    }
}
int BibliotecaModel::getLastId() {
    return lastId;
}

void BibliotecaModel::createItem(QString tipo) {
    lastId++;
    if (tipo == "book") {
        BookModel *book = new BookModel(lastId);
        book->setIcon("📖");
        items.append(book);
    } else if (tipo == "film") {
        FilmModel *film = new FilmModel(lastId);
        film->setIcon("🎬");
        items.append(film);
    } else if (tipo == "music") {
        MusicModel *music = new MusicModel(lastId);
        music->setIcon("🎵");
        items.append(music);
    }

}
