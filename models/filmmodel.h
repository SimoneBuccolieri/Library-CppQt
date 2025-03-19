//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef FILMMODEL_H
#define FILMMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <itemmodel.h>


class FilmModel : public ItemModel{
private:
    QString director;
    int duration;
    int rating;
    QString language;
public:
    FilmModel(const QJsonObject &json);
};



#endif //FILMMODEL_H
