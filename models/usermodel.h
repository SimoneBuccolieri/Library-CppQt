//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>
#include <QList>
struct User {
    QString username;
    QString password;
};

class UserModel {
public:
    UserModel();
    bool registerUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    User* getUser(const QString &username);
private:
    QList<User> users;
};



#endif //USERMODEL_H
