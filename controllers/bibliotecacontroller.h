//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BIBLIOTECACONTROLLER_H
#define BIBLIOTECACONTROLLER_H
#include "bibliotecamodel.h"
#include "usermodel.h"
#include "usercontroller.h"

class BibliotecaController {
public:
    explicit BibliotecaController(BibliotecaModel &model, UserController &userController);  // ✅ Usa il modello esistente


    QVector<BookModel *> getBooks() const;
    QVector<FilmModel *> getFilms() const;
    QVector<MusicModel *> getMusic() const;

    ItemModel* getItemById(int id);
    void loadFromJson();  // ✅ Carica i dati JSON
    void saveToJson();

    void prenota(int id);
    void restituisci(int id); //dafare

private:
    BibliotecaModel &bibliotecaModel;
    UserController &userController;
};



#endif //BIBLIOTECACONTROLLER_H
