//
// Created by Simone Buccolieri on 19/03/25.
//

#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QString>
#include <QJsonObject>

class ItemModel {
public:
    virtual ~ItemModel() {}  // ✅ Distruttore virtuale per il polimorfismo
    //virtual void printInfo() const = 0;
    QString getTitolo() const { return titolo; }
    QString getAutore() const { return autore; }
    int getQuantity() const { return quantity;}

protected:
    QString titolo;
    QString autore;  // 📌 Può essere l'autore del libro o il regista del film
    int quantity;
};




#endif //ITEMMODEL_H
