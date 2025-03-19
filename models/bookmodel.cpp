//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bookmodel.h"
#include <QJsonArray>
#include <QDebug>


BookModel::BookModel(const QJsonObject &json) : ItemModel(json) {
    if (json.contains("publisher")) {
        publisher = json["publisher"].toString();
    }
    if (json.contains("ISBN")) {
        ISBN = json["ISBN"].toInt();
    }
    if (json.contains("pageCount")) {
        pageCount = json["pageCount"].toInt();
    }
    if (json.contains("language")) {
        language = json["language"].toString();
    }
}
