//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef BIBLIOTECACONTROLLER_H
#define BIBLIOTECACONTROLLER_H
#include "bibliotecamodel.h"
#include "usermodel.h"
#include "usercontroller.h"
#include <QObject>

class BibliotecaController : public QObject {
    Q_OBJECT
public:
    explicit BibliotecaController(BibliotecaModel &model, UserController &userController);


    QVector<ItemModel *> getItems() const;


    ItemModel* getItemById(int id);
    void loadFromJson();
    void saveToJson();

    void prenota(int id);
    void restituisci(int id);
    void update();

    void deleteId(int id);

    int getLastId();

    void createItem(QString tipo);

private:
    BibliotecaModel &bibliotecaModel;
    UserController &userController;
signals:
    void datiAggiornati();
};



#endif //BIBLIOTECACONTROLLER_H
