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

    QLineEdit *titleLabel;
    QLineEdit *authorLabel;
    QLineEdit *quantityLabel;
    QLineEdit *releaseYearLabel;
    QLineEdit *genreLabel;
    QLineEdit *iconLabel;

    QLineEdit *publisherLabel;
    QLineEdit *ISBNLabel;
    QLineEdit *pageCountLabel;
    QLineEdit *languageLabelB;

    QLineEdit *durationLabelF;
    QLineEdit *directorLabel;
    QLineEdit *ratingLabel;
    QLineEdit *languageLabelF;

    QLineEdit *albumLabel;
    QLineEdit *durationLabelM;
    QLineEdit *formatLabel;
    QLineEdit *recordLabelLabel;

    QVBoxLayout *layout;

};



#endif //EDITITEM_H
