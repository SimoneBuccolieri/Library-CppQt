//
// Created by Simone Buccolieri on 22/03/25.
//

#ifndef EDITITEM_H
#define EDITITEM_H



#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>
#include <QLineEdit>
#include "bibliotecacontroller.h"

class EditItem : public QWidget{
    Q_OBJECT

public:
    explicit EditItem(BibliotecaController *bibliotecaController, int id, QWidget *parent = nullptr);

signals:
    void backRequested();
    void saveRequested();
    void eliminaRequested();
private slots:
    void saveClicked();
    void eliminaClicked();
    void back();
private:
    BibliotecaController *bibliotecaController;
    int currentItemId;
    ItemModel *item;
    QFormLayout *formLayout;
    QMap<QString, QLineEdit*> campi;
    QVBoxLayout *layout;

};



#endif //EDITITEM_H
