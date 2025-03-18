//
// Created by Simone Buccolieri on 18/03/25.
//

#include "musicmodel.h"
MusicModel::MusicModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    autore = json["autore"].toString();
    quantity = json["quantity"].toInt();
}