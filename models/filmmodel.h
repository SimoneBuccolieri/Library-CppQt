//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef FILMMODEL_H
#define FILMMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <videomodel.h>


class FilmModel : public VideoModel{
public:
    FilmModel();
    FilmModel(const QJsonObject &json);
    //int getQty();
};



#endif //FILMMODEL_H
