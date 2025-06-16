//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>
#include <QList>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
struct User {
    QString username;
    QString password;
    QMap<int, int> prestiti;
};

class UserModel {
public:
    UserModel();
    UserModel(const QJsonObject &json);

    void loadFromJson();

    bool registerUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    User* getUser(const QString &username);

    void saveToJson();

private:
    QVector<User> users;
};



#endif //USERMODEL_H
