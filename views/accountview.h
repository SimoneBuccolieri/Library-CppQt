//
// Created by Simone Buccolieri on 20/03/25.
//

#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>
#include <usercontroller.h>
#include <bibliotecacontroller.h>

class AccountView : public QWidget {
    Q_OBJECT

public:
    explicit AccountView(UserController *userController, BibliotecaController *bibliotecaController, QWidget *parent = nullptr);

    void aggiornaDati();

signals:
    void backRequested();
private slots:
    void back();
private:
    UserController *userController;
    BibliotecaController *bibliotecaController;
    QListWidget *listWidget;
    QVBoxLayout *layout;
    QLabel *usernameLabel;
};


#endif //ACCOUNTVIEW_H
