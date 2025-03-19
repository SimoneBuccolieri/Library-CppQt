//
// Created by Simone Buccolieri on 19/03/25.
//

#include "showitem.h"
ShowItem::ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController) {

    ItemModel* item = bibliotecaController->getItemById(id);




    if (BookModel* book = dynamic_cast<BookModel*>(item)) {
        ShowBook(book);
    } else if (FilmModel* film = dynamic_cast<FilmModel*>(item)) {
        qDebug() << "🎬 Questo è un film con titolo:" << film->getTitolo();
    } else {
        qDebug() << "❌ Tipo sconosciuto!";
    }
}

void ShowItem::ShowBook(BookModel* book) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel(book->getTitolo(), this);
    QLabel *authorLabel = new QLabel(book->getAutore(), this);
    QLabel *quantityLabel = new QLabel(QString::number(book->getQuantity()), this);
    QLabel *publisherLabel = new QLabel(book->getPublisher(), this);
    QLabel *ISBNLabel = new QLabel(QString::number(book->getISBN()), this);
    QLabel *pageCountLabel = new QLabel(QString::number(book->getPageCount()), this);
    QLabel *languageLabel = new QLabel(book->getLanguage(), this);

    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);
    layout->addWidget(authorLabel, 0, Qt::AlignHCenter);
    layout->addWidget(quantityLabel, 0, Qt::AlignHCenter);
    layout->addWidget(publisherLabel, 0, Qt::AlignHCenter);
    layout->addWidget(ISBNLabel, 0, Qt::AlignHCenter);
    layout->addWidget(pageCountLabel, 0, Qt::AlignHCenter);
    layout->addWidget(languageLabel, 0, Qt::AlignHCenter);

}