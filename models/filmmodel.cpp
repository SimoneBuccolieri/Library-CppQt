//
// Created by Simone Buccolieri on 18/03/25.
//

#include "filmmodel.h"
FilmModel::FilmModel(const QJsonObject &json) : ItemModel(json) {
    if (json.contains("director")) {
        director = json["director"].toString();
    }
    if (json.contains("duration")) {
        duration = json["duration"].toInt();
    }
    if (json.contains("rating")) {
        rating = json["rating"].toInt();
    }
    if (json.contains("language")) {
        language = json["language"].toString();
    }
}