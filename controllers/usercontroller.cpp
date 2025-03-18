//
// Created by Simone Buccolieri on 18/03/25.
//

#include "usercontroller.h"

UserController::UserController(UserModel &userModel) : userModel(userModel) {}

bool UserController::login(const QString &username, const QString &password) {
    if (userModel.authenticateUser(username, password)) {
        loggedUser = userModel.getUser(username);  // ✅ Memorizza l'utente loggato
        return true;
    }
    return false;
}

bool UserController::registerUser(const QString &username, const QString &password) {
    if (userModel.registerUser(username, password)) {
        loggedUser = userModel.getUser(username);  // ✅ Memorizza il nuovo utente
        return true;
    }
    return false;
}

User* UserController::getLoggedUser() {
    return loggedUser;  // ✅ Restituisce l'utente attualmente loggato
}
