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