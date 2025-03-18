//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BOOKMODEL_H
#define BOOKMODEL_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

class BookModel {
private:
  QString titolo;
  QString autore;
  //int quantity;
  //void loadFromJson(const QString &filePath);

public:
  BookModel();
  BookModel(const QJsonObject &json);

  QString getTitolo() const { return titolo; }
  QString getAutore() const { return autore; }
  //int getQty();
};



#endif //BOOKMODEL_H
