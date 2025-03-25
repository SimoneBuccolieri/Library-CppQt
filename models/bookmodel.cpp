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
        ISBN = json["ISBN"].toString();
    }
    if (json.contains("pageCount")) {
        pageCount = json["pageCount"].toInt();
    }
    if (json.contains("language")) {
        language = json["language"].toString();
    }
}
BookModel::BookModel(int id): ItemModel(id), publisher(""), ISBN(""), pageCount(0), language("") {
}
void BookModel::setPublisher(const QString& newPublisher) {
    publisher = newPublisher;
}

void BookModel::setISBN(const QString& newISBN) {
    ISBN = newISBN;
}

void BookModel::setPageCount(int newPageCount) {
    pageCount = newPageCount;
}

void BookModel::setLanguage(const QString& newLanguage) {
    language = newLanguage;
}

QMap<QString, QString> BookModel::getDettagli() const {
    QMap<QString, QString> dettagli;
    dettagli["Tipo"] = "Libro";
    dettagli["Icona"] = getIcon();
    dettagli["Titolo"] = getTitolo();
    dettagli["Autore"] = getAutore();
    dettagli["Editore"] = publisher;
    dettagli["ISBN"] = ISBN;
    dettagli["Pagine"] = QString::number(pageCount);
    dettagli["Lingua"] = language;
    dettagli["Quantità"] = QString::number(getQuantity());
    dettagli["Anno di rilascio"] = QString::number(getReleaseYear());
    dettagli["Genere"] = getGenre();
    return dettagli;
}
void BookModel::setDettagli(const QMap<QString, QString>& dati) {
    if (dati.contains("Titolo")) setTitolo(dati["Titolo"]);
    if (dati.contains("Icona")) setIcon(dati["Icona"]);
    if (dati.contains("Autore")) setAutore(dati["Autore"]);
    if (dati.contains("Editore")) publisher = dati["Editore"];
    if (dati.contains("ISBN")) ISBN = dati["ISBN"];
    if (dati.contains("Pagine")) pageCount = dati["Pagine"].toInt();
    if (dati.contains("Lingua")) language = dati["Lingua"];
    if (dati.contains("Quantità")) setQuantity(dati["Quantità"].toInt());
    if (dati.contains("Anno di rilascio")) setReleaseYear(dati["Anno di rilascio"].toInt());
    if (dati.contains("Genere")) setGenre(dati["Genere"]);
}
QJsonObject BookModel::toJson() const {
    QJsonObject json;
    json["tipologia"] = "book";
    json["id"] = getId();
    json["title"] = getTitolo();
    json["author"] = getAutore();
    json["quantity"] = getQuantity();
    json["releaseYear"] = getReleaseYear();
    json["genre"] = getGenre();
    json["icon"] = getIcon();
    json["publisher"] = publisher;
    json["ISBN"] = ISBN;
    json["pageCount"] = pageCount;
    json["language"] = language;
    return json;
}
