//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BOOKMODEL_H
#define BOOKMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <itemmodel.h>

class BookModel : public ItemModel {
public:
  BookModel(const QJsonObject &json);

};



#endif //BOOKMODEL_H
