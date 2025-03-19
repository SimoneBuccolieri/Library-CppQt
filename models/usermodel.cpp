//
// Created by Simone Buccolieri on 18/03/25.
//

#include "usermodel.h"

UserModel::UserModel() {
    users.append(User{"", ""});// Utente di test
}

bool UserModel::registerUser(const QString &username, const QString &password) {
    for (const auto &user : users) {
        if (user.username == username) {
            return false;
        }
    }
    users.append({username, password});
    return true;
}

bool UserModel::authenticateUser(const QString &username, const QString &password) {
    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}
User* UserModel::getUser(const QString &username) {
    for (User &user : users) {  // Non uso `const` perché restituisco un puntatore
        if (user.username == username) {
            return &user;  // ✅ Restituisce un puntatore all'utente trovato
        }
    }
    return nullptr;  // ❌ Utente non trovato
}