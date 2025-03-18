//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef FILMMODEL_H
#define FILMMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>



class FilmModel {
private:
    QString titolo;
    QString regista;
public:
    FilmModel();
    FilmModel(const QJsonObject &json);

    QString getTitolo() const { return titolo; }
    QString getRegista() const { return regista; }
    //int getQty();
};



#endif //FILMMODEL_H
