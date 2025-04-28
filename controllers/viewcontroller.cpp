//
// Created by Simone Buccolieri on 22/03/25.
//
#include "viewcontroller.h"
#include "auth/loginview.h"
#include "auth/registerview.h"
#include "mainview.h"
#include "showitem.h"
#include "accountview.h"
#include "createitem.h"
#include "edititem.h"

ViewController::ViewController(QWidget *parent)
: QStackedWidget(parent),loginView(nullptr), registerView(nullptr),
  mainView(nullptr), showItemView(nullptr), accountView(nullptr)
{

    userModel = new UserModel();
    userController = new UserController(*userModel);
    userController->loadFromJson();

    bibliotecaModel = new BibliotecaModel();
    bibliotecaController = new BibliotecaController(*bibliotecaModel, *userController);
    bibliotecaController->loadFromJson();

    loginView = new LoginView(userController);
    registerView = new RegisterView(userController);

    addWidget(loginView);
    addWidget(registerView);

    connect(loginView, &LoginView::loginSuccess, this, &ViewController::showMain);
    connect(loginView, &LoginView::registerRequested, this, &ViewController::showRegister);
    connect(registerView, &RegisterView::loginRequested, this, &ViewController::showLogin);
    connect(registerView, &RegisterView::registerSuccess, this, &ViewController::showMain);


    showLogin();
}
void ViewController::showLogin() {
    setFixedSize(600, 1000);
    setCurrentWidget(loginView);
}
void ViewController::showRegister() {
    setFixedSize(600, 1000);
    setCurrentWidget(registerView);
}
void ViewController::showMain() {

    setFixedSize(600, 1000);
    if (!mainView) {
        mainView = new MainView(userController, bibliotecaController);
        bibliotecaController->update();
        connect(mainView, &MainView::richiestaDettagliItem, this, &ViewController::showItem);
        connect(mainView, &MainView::richiestaAccount, this, &ViewController::showAccount);
        connect(mainView, &MainView::richiestaAddItem, this, &ViewController::showAddItem);
        connect(mainView, &MainView::logoutRequested, this, &ViewController::logout);
        addWidget(mainView);
    }
    setCurrentWidget(mainView);
}
void ViewController::showItem(int itemId) {
    if (userController->getLoggedUser()->username =="admin") {
        showEditView = new EditItem(bibliotecaController, itemId);
        connect(showEditView, &EditItem::backRequested, this, &ViewController::showMain);
        addWidget(showEditView);
        setCurrentWidget(showEditView);
    }else {
        showItemView = new ShowItem(bibliotecaController, itemId);
        connect(showItemView, &ShowItem::backRequested, this, &ViewController::showMain);
        addWidget(showItemView);
        setCurrentWidget(showItemView);
    }

}

void ViewController::showAccount() {
    accountView = new AccountView(userController, bibliotecaController);
    addWidget(accountView);
    connect(accountView, &AccountView::backRequested, this, &ViewController::showMain);
    setCurrentWidget(accountView);
}
void ViewController::showAddItem() {
    showCreateView = new CreateItem(bibliotecaController);
    addWidget(showCreateView);
    connect(showCreateView, &CreateItem::backRequested, this, &ViewController::showMain);
    connect(showCreateView, &CreateItem::creaRequested, this, &ViewController::showItem);
    setCurrentWidget(showCreateView);
}
void ViewController::logout() {
    if (mainView) {
        removeWidget(mainView);
        delete mainView;
        mainView = nullptr;
    }
    if (showItemView) {
        removeWidget(showItemView);
        delete showItemView;
        showItemView = nullptr;
    }
    if (accountView) {
        removeWidget(accountView);
        delete accountView;
        accountView = nullptr;
    }

    userController->logout();



    showLogin();

}
