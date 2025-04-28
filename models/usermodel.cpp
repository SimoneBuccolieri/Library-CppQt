//
// Created by Simone Buccolieri on 18/03/25.
//

#include "usermodel.h"
#include "../globals.h"


UserModel::UserModel() {
}

void UserModel::loadFromJson() {
    QFile file(usersPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Errore apertura file JSON!";
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (!document.isArray()) {
        qDebug() << "Formato JSON errato!";
        return;
    }
    QJsonArray jsonArray = document.array();
    for (const QJsonValue &value : jsonArray) {
        if (!value.isObject()) continue;

        QJsonObject jsonObj = value.toObject();
        User user;
        user.username = jsonObj["username"].toString();
        user.password = jsonObj["password"].toString();

        QJsonObject prestitiObj = jsonObj["prestiti"].toObject();
        for (const QString &key : prestitiObj.keys()) {
            user.prestiti[key.toInt()] = prestitiObj[key].toInt();
        }

        users.append(user);

    }
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
    for (User &user : users) {
        if (user.username == username) {
            return &user;
        }
    }
    return nullptr;
}
void UserModel::saveToJson() {
    QJsonArray jsonArray;

    for (const User &user : users) {
        QJsonObject jsonObj;
        jsonObj["username"] = user.username;
        jsonObj["password"] = user.password;


        QJsonObject prestitiObj;
        for (auto it = user.prestiti.begin(); it != user.prestiti.end(); ++it) {
            prestitiObj[QString::number(it.key())] = it.value();
        }
        jsonObj["prestiti"] = prestitiObj;

        jsonArray.append(jsonObj);
    }

    QJsonDocument document(jsonArray);
    QFile file(usersPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Errore salvataggio JSON utenti!";
        return;
    }

    file.write(document.toJson());
    file.close();
}
