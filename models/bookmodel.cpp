//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bookmodel.h"
#include <QJsonArray>
#include <QDebug>


BookModel::BookModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    autore = json["autore"].toString();
}
