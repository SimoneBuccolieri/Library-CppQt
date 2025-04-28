//
// Created by Simone Buccolieri on 19/03/25.
//

#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QString>
#include <QJsonObject>

class ItemModel {
public:
    virtual QMap<QString, QString> getDettagli() const = 0;
    virtual void setDettagli(const QMap<QString, QString>& dati) = 0;
    virtual QJsonObject toJson() const = 0;

    virtual ~ItemModel() {}
    int getId() const {return id;}
    QString getTitolo() const { return titolo; }
    QString getAutore() const { return autore; }
    int getQuantity() const { return quantity;}
    int getReleaseYear() const { return releaseYear;}
    QString getGenre() const { return genre; }
    QString getIcon() const { return icon; }

    void setIcon(const QString& newIcon);
    void setTitolo(const QString& newTitolo);
    void setAutore(const QString& newAutore);
    void setQuantity(int newQuantity);
    void setReleaseYear(int newReleaseYear);
    void setGenre(const QString& newGenre);

protected:
    explicit ItemModel(const QJsonObject &json);
    explicit ItemModel(int id);


    int id;
    QString titolo;
    QString autore;
    int quantity;
    int releaseYear;
    QString genre;
    QString icon;
};




#endif //ITEMMODEL_H
