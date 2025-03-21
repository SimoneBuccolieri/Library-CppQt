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
private:
  QString publisher;
  QString ISBN;
  int pageCount;
  QString language;
public:
  BookModel(const QJsonObject &json);
  //BookModel(const QString &titolo, const QString &autore);

  QString getPublisher() const { return publisher; }
  QString getISBN() const { return ISBN;}
  int getPageCount() const { return pageCount;}
  QString getLanguage() const { return language; }
};



#endif //BOOKMODEL_H
