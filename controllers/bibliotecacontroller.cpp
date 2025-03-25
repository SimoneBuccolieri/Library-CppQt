//
// Created by Simone Buccolieri on 18/03/25.
//

#include "bibliotecacontroller.h"
#include <QDebug>
#include <QDir>

BibliotecaController::BibliotecaController(BibliotecaModel &model, UserController &controller)
    : bibliotecaModel(model), userController(controller) {
}

void BibliotecaController::loadFromJson() {
    bibliotecaModel.loadFromJson();
}
void BibliotecaController::saveToJson() {
    bibliotecaModel.saveToJson();
}
QVector<ItemModel*> BibliotecaController::getItems() const {
    return bibliotecaModel.getItemModel();
}
ItemModel* BibliotecaController::getItemById(int id) {
    QVector<ItemModel*> items = bibliotecaModel.getItemModel();
    for (ItemModel* item : items) {
        if (item->getId() == id) {
            return item;
        }
    }
    return nullptr;  // ❌ Se l'ID non esiste, restituisce `nullptr`
}
void BibliotecaController::prenota(int id) {
    // ✅ 1. Ottenere l'utente loggato
    User* user = userController.getLoggedUser();
    if (!user) {
        return;
    }
    // ✅ 2. Ottenere l'oggetto dalla biblioteca
    ItemModel* item = getItemById(id);
    if (!item) {
        return;
    }
    // ✅ 3. Verificare se l'oggetto ha copie disponibili
    if (item->getQuantity() <= 0) {
        return;
    }
    item->setQuantity(item->getQuantity() - 1);
    // ✅ 5. Aggiungere l'oggetto ai prestiti dell'utente
    if (user->prestiti.contains(id)) {
        user->prestiti[id]++;
    } else {
        user->prestiti[id] = 1;
    }
    update();
}
void BibliotecaController::restituisci(int id) {
    // ✅ 1. Ottenere l'utente loggato
    User* user = userController.getLoggedUser();
    if (!user) {
        return;
    }
    // ✅ 2. Ottenere l'oggetto dalla biblioteca
    ItemModel* item = getItemById(id);
    if (!item) {
        return;
    }
    // ✅ 3. Verificare se l'oggetto ha copie disponibili
    if (user->prestiti.contains(id) && user->prestiti[id] > 0) {
        user->prestiti[id]--;
        if (user->prestiti[id]==0) {
            user->prestiti.remove(id);
        }
        item->setQuantity(item->getQuantity() + 1);
    }
    update();
}
void BibliotecaController::update() {
    saveToJson();
    userController.saveToJson();
    emit datiAggiornati();
}
void BibliotecaController::deleteId(int id) {
    bibliotecaModel.deleteId(id);
}
int BibliotecaController::getLastId() {
    return bibliotecaModel.getLastId();
}
void BibliotecaController::createItem(QString tipo) {
    bibliotecaModel.createItem(tipo);
}
