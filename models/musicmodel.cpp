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