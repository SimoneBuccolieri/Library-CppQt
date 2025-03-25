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
  explicit BookModel(int id);

  QString getPublisher() const { return publisher; }
  QString getISBN() const { return ISBN;}
  int getPageCount() const { return pageCount;}
  QString getLanguage() const { return language; }

  void setPublisher(const QString& newSetPublisher);
  void setISBN(const QString& newISBN);
  void setPageCount(int newPageCount);
  void setLanguage(const QString& newLanguage);

  QMap<QString, QString> getDettagli() const;

  void setDettagli(const QMap<QString, QString> &dati);

  QJsonObject toJson() const;
};



#endif //BOOKMODEL_H
