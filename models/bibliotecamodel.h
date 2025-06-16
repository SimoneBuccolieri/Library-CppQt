//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BIBLIOTECAMODEL_H
#define BIBLIOTECAMODEL_H

#include "bookmodel.h"
#include "filmmodel.h"
#include "musicmodel.h"
#include <QVector>
#include <QJsonDocument>
#include <QFile>

class BibliotecaModel {
public:
    BibliotecaModel();
    void loadFromJson();
    void saveToJson();

    void deleteId(int id);

    int getLastId();

    void createItem(QString tipo);

    QVector<ItemModel*> getItemModel() const { return items; }

private:
    QVector<ItemModel*> items;
    int lastId;
};



#endif //BIBLIOTECAMODEL_H
