//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecamodel.h"
#include "../globals.h"
#include <QJsonArray>
#include <QDebug>

#include "bibliotecacontroller.h"

BibliotecaModel::BibliotecaModel() {
    qDebug() << "BibliotecaModel inizializzato!";
}
void BibliotecaModel::loadFromJson() {
    QFile file(bibliotecaPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (!document.isArray()) {
        return;
    }

    QJsonArray jsonArray = document.array();
    for (const QJsonValue &value : jsonArray) {
        if (!value.isObject()) continue;

        QJsonObject jsonObj = value.toObject();
        QString tipo = jsonObj["tipologia"].toString();

        if (tipo == "book") {
            items.append(new BookModel(jsonObj));
        } else if (tipo == "film") {
            items.append(new FilmModel(jsonObj));
        } else if (tipo == "music") {
            items.append(new MusicModel(jsonObj));
        }
        lastId = jsonObj["id"].toInt();
    }
}
void BibliotecaModel::saveToJson() {
    QJsonArray jsonArray;
    for (const ItemModel* item : items) {
        jsonArray.append(item->toJson());
    }
    QJsonDocument document(jsonArray);
    QFile file(bibliotecaPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    file.write(document.toJson());
    file.close();
}

void BibliotecaModel::deleteId(int id) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i]->getId() == id) {
            delete items[i];
            items.removeAt(i);
            return;
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
