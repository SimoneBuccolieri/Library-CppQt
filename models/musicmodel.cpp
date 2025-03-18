//
// Created by Simone Buccolieri on 18/03/25.
//

#include "musicmodel.h"
MusicModel::MusicModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    artista = json["autore"].toString();
}