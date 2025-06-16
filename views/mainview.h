//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QToolBar>

#include "usercontroller.h"
#include "bibliotecacontroller.h"
#include "showitem.h"
#include "accountview.h"
class MainView : public QMainWindow {
    Q_OBJECT

public:
    explicit MainView(UserController *userController,BibliotecaController *bibliotecaController, QMainWindow *parent = nullptr);

signals:
    void logoutRequested();
    void richiestaDettagliItem(int itemId);
    void richiestaAccount();
    void richiestaAddItem();

private slots:
    void onLogoutClicked();
    void onAccountClicked();


    void srtSearchUpdate(const QString &text);
    void onAddItemClicked();
    void onItemClicked(QListWidgetItem *item);


private:
    QLabel *welcomeLabel;
    QPushButton *logoutButton;
    QPushButton *accountButton;
    QPushButton *addItemButton;
    UserController *userController;

    BibliotecaController *bibliotecaController;
    QListWidget *libraryList;
    QLineEdit *searchBox;


private slots:
    void aggiornaDati();
};


#endif //MAINVIEW_H
