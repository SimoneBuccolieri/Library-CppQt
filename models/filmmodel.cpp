//
// Created by Simone Buccolieri on 18/03/25.
//

#include "filmmodel.h"
FilmModel::FilmModel(const QJsonObject &json) {
    titolo = json["titolo"].toString();
    regista = json["autore"].toString();
}