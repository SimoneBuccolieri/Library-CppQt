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
QMap<QString, QString> FilmModel::getDettagli() const {
    QMap<QString, QString> dettagli;
    dettagli["Tipo"] = "Film";
    dettagli["Icona"] = getIcon();
    dettagli["Titolo"] = getTitolo();
    dettagli["Autore"] = getAutore();
    dettagli["Regista"] = director;
    dettagli["Durata"] = QString::number(duration) + " minuti";
    dettagli["Rating"] = QString::number(rating);
    dettagli["Lingua"] = language;
    dettagli["Quantità"] = QString::number(getQuantity());
    dettagli["Anno di rilascio"] = QString::number(getReleaseYear());
    dettagli["Genere"] = getGenre();
    return dettagli;
}
void FilmModel::setDettagli(const QMap<QString, QString>& dati) {
    if (dati.contains("Titolo")) setTitolo(dati["Titolo"]);
    if (dati.contains("Icona")) setIcon(dati["Icona"]);
    if (dati.contains("Autore")) setAutore(dati["Autore"]);
    if (dati.contains("Regista")) director = dati["Regista"];
    if (dati.contains("Durata")) duration = dati["Durata"].remove(" minuti").toInt();
    if (dati.contains("Rating")) rating = dati["Rating"].toInt();
    if (dati.contains("Lingua")) language = dati["Lingua"];
    if (dati.contains("Quantità")) setQuantity(dati["Quantità"].toInt());
    if (dati.contains("Anno di rilascio")) setReleaseYear(dati["Anno di rilascio"].toInt());
    if (dati.contains("Genere")) setGenre(dati["Genere"]);
}
QJsonObject FilmModel::toJson() const {
    QJsonObject json;
    json["tipologia"] = "film";
    json["id"] = getId();
    json["title"] = getTitolo();
    json["author"] = getAutore();
    json["quantity"] = getQuantity();
    json["releaseYear"] = getReleaseYear();
    json["genre"] = getGenre();
    json["icon"] = getIcon();
    json["director"] = director;
    json["duration"] = duration;
    json["rating"] = rating;
    json["language"] = language;
    return json;
}
