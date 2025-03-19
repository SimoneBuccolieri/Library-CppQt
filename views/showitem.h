//
// Created by Simone Buccolieri on 19/03/25.
//

#ifndef SHOWITEM_H
#define SHOWITEM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>
#include "bibliotecacontroller.h"

class ShowItem : public QWidget{
    Q_OBJECT

public:
    explicit ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent = nullptr);

    void ShowBook(BookModel* book);
private slots:
    void prenota();
    void restituisci();
private:
    BibliotecaController *bibliotecaController;
    int currentItemId;

};



#endif //SHOWITEM_H
