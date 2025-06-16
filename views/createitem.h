//
// Created by Simone Buccolieri on 23/03/25.
//

#ifndef CREATEITEM_H
#define CREATEITEM_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>
#include <QLineEdit>
#include <bibliotecacontroller.h>

class CreateItem : public QWidget {
    Q_OBJECT

public:
   explicit CreateItem(BibliotecaController *bibliotecaController, QWidget *parent = nullptr);

signals:
    void backRequested();
    void creaRequested(int itemId);

private:
    QVBoxLayout *layout;
    BibliotecaController *bibliotecaController;
    QComboBox *type;

private slots:
    void back();
    void crea();
};



#endif //CREATEITEM_H
