//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef MUSICMODEL_H
#define MUSICMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>



class MusicModel {
private:
    QString titolo;
    QString artista;
public:
    MusicModel();
    MusicModel(const QJsonObject &json);

    QString getTitolo() const { return titolo; }
    QString getArtista() const { return artista; }
    //int getQty();
};



#endif //MUSICMODEL_H
