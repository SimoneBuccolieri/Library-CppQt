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

}