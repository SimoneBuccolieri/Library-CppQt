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
    void loadFromJson();  // ✅ Carica tutti i dati
    void saveToJson();

    QVector<ItemModel*> getItemModel() const { return items; }

private:
    QVector<ItemModel*> items;
};



#endif //BIBLIOTECAMODEL_H
