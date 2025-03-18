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
public:
    MusicModel(const QJsonObject &json);

};



#endif //MUSICMODEL_H
