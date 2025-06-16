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
    explicit FilmModel(int id);
    QString getDirector() const {return director;}
    int getDuration() const { return duration;}
    float getRating() const { return rating;}
    QString getLanguage() const { return language;}

    void setDirector(const QString& newDirector);
    void setDuration(int newDuration);
    void setRating(float newRating);
    void setLanguage(const QString& newLanguage);

    QMap<QString, QString> getDettagli() const;

    void setDettagli(const QMap<QString, QString> &dati);

    QJsonObject toJson() const;
};



#endif //FILMMODEL_H
