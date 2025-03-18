//
// Created by Simone Buccolieri on 18/03/25.
//

#include "videomodel.h"
VideoModel::VideoModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    regista = json["regista"].toString();
}