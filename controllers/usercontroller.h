//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include <QDebug>
#include <QDir>

#include "itemmodel.h"
#include "../models/usermodel.h"
class UserController {
public:
    explicit UserController(UserModel &userModel);



    bool login(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password);
    User* getLoggedUser();
    void loadFromJson();
    void saveToJson();

    void logout();

    void prenotaItem(ItemModel *item, User *user);

    void restituisciItem(ItemModel *item, User *user);

private:
    UserModel &userModel;
    User *loggedUser = nullptr;
};

#endif // USERCONTROLLER_H
