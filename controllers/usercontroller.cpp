//
// Created by Simone Buccolieri on 18/03/25.
//

#include "usercontroller.h"

#include "itemmodel.h"


UserController::UserController(UserModel &userModel) : userModel(userModel) {}

void UserController::loadFromJson() {
    userModel.loadFromJson();
}
bool UserController::login(const QString &username, const QString &password) {
    if (userModel.authenticateUser(username, password)) {
        loggedUser = userModel.getUser(username);
        return true;
    }
    return false;
}

bool UserController::registerUser(const QString &username, const QString &password) {
    if (userModel.registerUser(username, password)) {
        loggedUser = userModel.getUser(username);
        saveToJson();
        return true;

    }
    return false;
}

User* UserController::getLoggedUser() {
    return loggedUser;
}

void UserController::saveToJson() {
    userModel.saveToJson();
}
void UserController::logout() {
    loggedUser=nullptr;
}