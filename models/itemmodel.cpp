//
// Created by Simone Buccolieri on 19/03/25.
//

#include "itemmodel.h"
ItemModel::ItemModel(const QJsonObject &json) {
    if (json.contains("id")) {
        id = json["id"].toInt();
    }
    if (json.contains("title") && json["title"].isString()) {
        titolo = json["title"].toString();
    }
    if (json.contains("author") && json["author"].isString()) {
        autore = json["author"].toString();
    }
    if (json.contains("quantity")) {
        quantity = json["quantity"].toInt();
    }
    if (json.contains("genre")) {
        genre = json["genre"].toString();
    }
    if (json.contains("releaseYear")) {
        releaseYear = json["releaseYear"].toInt();
    }
    if (json.contains("icon")) {
        icon = json["icon"].toString();
    }

}
ItemModel::ItemModel(int id):id(id), titolo(""), autore(""), quantity(0), releaseYear(0), genre(""), icon("") {}

void ItemModel::setIcon(const QString& newIcon) {
    icon = newIcon;
}
void ItemModel::setTitolo(const QString& newTitolo) {
    titolo = newTitolo;
}
void ItemModel::setQuantity(int newQuantity) {
    quantity = newQuantity;
}
void ItemModel::setAutore(const QString& newAutore) {
    autore = newAutore;
}
void ItemModel::setReleaseYear(int newReleaseYear) {
    releaseYear = newReleaseYear;
}
void ItemModel::setGenre(const QString& newGenre) {
    genre = newGenre;
}
