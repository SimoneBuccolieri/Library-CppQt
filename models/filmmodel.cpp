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
        rating = static_cast<float>(json["rating"].toDouble());
    }
    if (json.contains("language")) {
        language = json["language"].toString();
    }
}
FilmModel::FilmModel(int id): ItemModel(id), director(""), duration(0), rating(0), language("") {
}
void FilmModel::setDirector(const QString& newDirector) {
    director = newDirector;
}

void FilmModel::setDuration(int newDuration) {
    duration = newDuration;
}

void FilmModel::setRating(float newRating) {
    rating = newRating;
}

void FilmModel::setLanguage(const QString& newLanguage) {
    language = newLanguage;
}