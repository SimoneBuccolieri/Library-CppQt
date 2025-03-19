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
QVector<BookModel*> BibliotecaController::getBooks() const {
    QVector<BookModel*> books;
    for (ItemModel* item : bibliotecaModel.getItemModel()) {
        if (BookModel* book = dynamic_cast<BookModel*>(item)) {
            books.append(book);
        }
    }
    return books;
}
QVector<FilmModel*> BibliotecaController::getFilms() const {
    QVector<FilmModel*> films;
    for (ItemModel* item : bibliotecaModel.getItemModel()) {
        if (FilmModel* film = dynamic_cast<FilmModel*>(item)) {
            films.append(film);
        }
    }
    return films;
}
QVector<MusicModel*> BibliotecaController::getMusic() const {
    QVector<MusicModel*> music;
    for (ItemModel* item : bibliotecaModel.getItemModel()) {
        if (MusicModel* musicItem = dynamic_cast<MusicModel*>(item)) {
            music.append(musicItem);
        }
    }
    return music;
}


ItemModel* BibliotecaController::getItemById(int id) {
    QVector<ItemModel*> items = bibliotecaModel.getItemModel();  // ✅ Ottiene tutti gli oggetti

    for (ItemModel* item : items) {
        if (item->getId() == id) {  // ✅ Confronta l'ID con quello richiesto
            return item;
        }
    }

    return nullptr;  // ❌ Se l'ID non esiste, restituisce `nullptr`
}

void BibliotecaController::prenota(int id) {
    // ✅ 1. Ottenere l'utente loggato
    User* user = userController.getLoggedUser();
    if (!user) {
        qDebug() << "❌ Nessun utente loggato!";
        return;
    }

    // ✅ 2. Ottenere l'oggetto dalla biblioteca
    ItemModel* item = getItemById(id);
    if (!item) {
        qDebug() << "❌ Nessun oggetto trovato con ID:" << id;
        return;
    }

    // ✅ 3. Verificare se l'oggetto ha copie disponibili
    if (item->getQuantity() <= 0) {
        qDebug() << "❌ Nessuna copia disponibile per questo oggetto!";
        return;
    }

    // ✅ 4. Ridurre la quantità disponibile dell'oggetto
    item->setQuantity(item->getQuantity() - 1);

    // ✅ 5. Aggiungere l'oggetto ai prestiti dell'utente
    if (user->prestiti.contains(id)) {
        user->prestiti[id]++;
    } else {
        user->prestiti[id] = 1;
    }

    qDebug() << "✅ Prenotato oggetto ID:" << id << "per l'utente:" << user->username;
    qDebug() << "📉 Nuova quantità disponibile:" << item->getQuantity();

    // ✅ 6. Salvare le modifiche nei file JSON
    saveToJson();
    userController.saveToJson();
}
void BibliotecaController::restituisci(int id) {}
