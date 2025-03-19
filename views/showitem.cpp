//
// Created by Simone Buccolieri on 19/03/25.
//

#include "showitem.h"
ShowItem::ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {

    ItemModel* item = bibliotecaController->getItemById(currentItemId);




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

    QPushButton *prenotaButton = new QPushButton("Prenota", this);
    QPushButton *restituisciButton = new QPushButton("Restituisci", this);

    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);
    layout->addWidget(authorLabel, 0, Qt::AlignHCenter);
    layout->addWidget(quantityLabel, 0, Qt::AlignHCenter);
    layout->addWidget(publisherLabel, 0, Qt::AlignHCenter);
    layout->addWidget(ISBNLabel, 0, Qt::AlignHCenter);
    layout->addWidget(pageCountLabel, 0, Qt::AlignHCenter);
    layout->addWidget(languageLabel, 0, Qt::AlignHCenter);

    layout->addWidget(prenotaButton,0,Qt::AlignHCenter);
    layout->addWidget(restituisciButton,0,Qt::AlignHCenter);
    connect(prenotaButton, &QPushButton::clicked, this, &ShowItem::prenota);
    connect(restituisciButton, &QPushButton::clicked, this, &ShowItem::restituisci);
}
void ShowItem::prenota() {
    bibliotecaController->prenota(currentItemId);  // ✅ Chiamata alla funzione di prenotazione
    qDebug() << "✅ Prenotazione effettuata per ID: " << currentItemId;;
}
void ShowItem::restituisci() {
    bibliotecaController->restituisci(currentItemId);  // ✅ Chiamata alla funzione di prenotazione
    qDebug() << "✅ restituzione effettuata per ID: " << currentItemId;;
}