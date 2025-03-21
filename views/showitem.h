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


private slots:
    void aggiornaDati();
    void prenota();
    void restituisci();
private:
    BibliotecaController *bibliotecaController;
    int currentItemId;
    ItemModel *item;

    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *quantityLabel;
    QLabel *releaseYearLabel;
    QLabel *genreLabel;

    QLabel *publisherLabel;
    QLabel *ISBNLabel;
    QLabel *pageCountLabel;
    QLabel *languageLabelB;

    QLabel *durationLabelF;
    QLabel *directorLabel;
    QLabel *ratingLabel;
    QLabel *languageLabelF;

    QLabel *albumLabel;
    QLabel *durationLabelM;
    QLabel *formatLabel;
    QLabel *recordLabelLabel;

    QVBoxLayout *layout;

};



#endif //SHOWITEM_H
