//
// Created by Simone Buccolieri on 22/03/25.
//

#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include <QStackedWidget>

#include "usercontroller.h"
#include "bibliotecacontroller.h"

class LoginView;
class RegisterView;
class MainView;
class ShowItem;
class AccountView;
class EditItem;
class CreateItem;

class ViewController : public QStackedWidget {
    Q_OBJECT

public:
    explicit ViewController(QWidget *parent = nullptr);
public slots:
    void showLogin();
    void showRegister();
    void showMain();
    void showItem(int itemId);
    void showAddItem();
    void showAccount();

    void logout();

private:
    UserController* userController;
    BibliotecaController* bibliotecaController;
    UserModel *userModel;
    BibliotecaModel *bibliotecaModel;

    LoginView* loginView;
    RegisterView* registerView;
    MainView* mainView;
    ShowItem* showItemView;
    EditItem* showEditView;
    CreateItem* showCreateView;
    AccountView* accountView;
};



#endif //VIEWCONTROLLER_H
