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
    float rating;
    QString language;
public:
    FilmModel(const QJsonObject &json);
    QString getDirector() const {return director;}
    int getDuration() const { return duration;}
    float getRating() const { return rating;}
    QString getLanguage() const { return language;}
};



#endif //FILMMODEL_H
