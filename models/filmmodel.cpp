//
// Created by Simone Buccolieri on 18/03/25.
//

#include "filmmodel.h"
FilmModel::FilmModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    autore = json["autore"].toString();
    quantity = json["quantity"].toInt();
}