//
// Created by Simone Buccolieri on 18/03/25.
//

#include "musicmodel.h"
MusicModel::MusicModel(const QJsonObject &json) : ItemModel(json) {
    if (json.contains("album")) {
        album = json["id"].toString();
    }
    if (json.contains("duration")) {
        duration = json["duration"].toInt();
    }
    if (json.contains("recordLabel")) {
        recordLabel = json["recordLabel"].toString();
    }
    if (json.contains("format")) {
        format = json["format"].toString();
    }
}
MusicModel::MusicModel(int id): ItemModel(id), album(""), duration(0), recordLabel(""), format("") {
}
void MusicModel::setAlbum(const QString& newAlbum) {
    album = newAlbum;
}

void MusicModel::setDuration(int newDuration) {
    duration = newDuration;
}

void MusicModel::setRecordLabel(const QString& newRecordLabel) {
    recordLabel = newRecordLabel;
}

void MusicModel::setFormat(const QString& newFormat) {
    format = newFormat;
}
QMap<QString, QString> MusicModel::getDettagli() const {
    QMap<QString, QString> dettagli;
    dettagli["Tipo"] = "Musica";
    dettagli["Icona"] = getIcon();
    dettagli["Titolo"] = getTitolo();
    dettagli["Autore"] = getAutore();
    dettagli["Album"] = album;
    dettagli["Durata"] = QString::number(duration) + " minuti";
    dettagli["Formato"] = format;
    dettagli["Etichetta discografica"] = recordLabel;
    dettagli["Quantità"] = QString::number(getQuantity());
    dettagli["Anno di rilascio"] = QString::number(getReleaseYear());
    dettagli["Genere"] = getGenre();
    return dettagli;
}
void MusicModel::setDettagli(const QMap<QString, QString>& dati) {
    if (dati.contains("Titolo")) setTitolo(dati["Titolo"]);
    if (dati.contains("Icona")) setIcon(dati["Icona"]);
    if (dati.contains("Autore")) setAutore(dati["Autore"]);
    if (dati.contains("Album")) album = dati["Album"];
    if (dati.contains("Durata")) duration = dati["Durata"].remove(" minuti").toInt();
    if (dati.contains("Formato")) format = dati["Formato"];
    if (dati.contains("Etichetta discografica")) recordLabel = dati["Etichetta discografica"];
    if (dati.contains("Quantità")) setQuantity(dati["Quantità"].toInt());
    if (dati.contains("Anno di rilascio")) setReleaseYear(dati["Anno di rilascio"].toInt());
    if (dati.contains("Genere")) setGenre(dati["Genere"]);
}
QJsonObject MusicModel::toJson() const {
    QJsonObject json;
    json["tipologia"] = "music";
    json["id"] = getId();
    json["title"] = getTitolo();
    json["author"] = getAutore();
    json["quantity"] = getQuantity();
    json["releaseYear"] = getReleaseYear();
    json["genre"] = getGenre();
    json["icon"] = getIcon();
    json["album"] = album;
    json["duration"] = duration;
    json["recordLabel"] = recordLabel;
    json["format"] = format;
    return json;
}
