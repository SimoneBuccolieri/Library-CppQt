//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

#include <itemmodel.h>

class MusicModel : public ItemModel {
private:
    QString album;
    int duration;
    QString recordLabel;
    QString format;
public:
    MusicModel(const QJsonObject &json);

    QString getAlbum() const {return album;}
    int getDuration() const { return duration;}
    QString getRecordLabel() const { return recordLabel;}
    QString getFormat() const { return format;}

};



#endif //MUSICMODEL_H
