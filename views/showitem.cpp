//
// Created by Simone Buccolieri on 19/03/25.
//

#include "showitem.h"
ShowItem::ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {
     item = bibliotecaController->getItemById(currentItemId);

    layout = new QVBoxLayout(this);
    //Item
    titleLabel = new QLabel(this);
    authorLabel = new QLabel(this);
    quantityLabel = new QLabel(this);
    releaseYearLabel = new QLabel(this);
    genreLabel = new QLabel(this);

    layout->addWidget(titleLabel, 0, Qt::AlignHCenter);
    layout->addWidget(authorLabel, 0, Qt::AlignHCenter);
    layout->addWidget(quantityLabel, 0, Qt::AlignHCenter);
    layout->addWidget(releaseYearLabel, 0, Qt::AlignHCenter);
    layout->addWidget(genreLabel, 0, Qt::AlignHCenter);
    //Book
    if (dynamic_cast<const BookModel*>(item)) {
        publisherLabel = new QLabel(this);
        ISBNLabel = new QLabel(this);
        pageCountLabel = new QLabel(this);
        languageLabelB = new QLabel(this);

        layout->addWidget(publisherLabel, 0, Qt::AlignHCenter);
        layout->addWidget(ISBNLabel, 0, Qt::AlignHCenter);
        layout->addWidget(pageCountLabel, 0, Qt::AlignHCenter);
        layout->addWidget(languageLabelB, 0, Qt::AlignHCenter);
    }
    //Film
    if (dynamic_cast<const FilmModel*>(item)) {
        directorLabel = new QLabel(this);
        durationLabelF = new QLabel(this);
        ratingLabel = new QLabel(this);
        languageLabelF = new QLabel(this);

        layout->addWidget(directorLabel, 0, Qt::AlignHCenter);
        layout->addWidget(durationLabelF, 0, Qt::AlignHCenter);
        layout->addWidget(ratingLabel, 0, Qt::AlignHCenter);
        layout->addWidget(languageLabelF, 0, Qt::AlignHCenter);
    }
    //Music
    if (dynamic_cast<const MusicModel*>(item)) {
        albumLabel = new QLabel(this);
        durationLabelM = new QLabel(this);
        formatLabel = new QLabel(this);
        recordLabelLabel = new QLabel(this);

        layout->addWidget(albumLabel, 0, Qt::AlignHCenter);
        layout->addWidget(durationLabelM, 0, Qt::AlignHCenter);
        layout->addWidget(formatLabel, 0, Qt::AlignHCenter);
        layout->addWidget(recordLabelLabel, 0, Qt::AlignHCenter);
    }

    QPushButton *prenotaButton = new QPushButton("Prenota", this);
    QPushButton *restituisciButton = new QPushButton("Restituisci", this);
    layout->addWidget(prenotaButton,0,Qt::AlignHCenter);
    layout->addWidget(restituisciButton,0,Qt::AlignHCenter);
    connect(prenotaButton, &QPushButton::clicked, this, &ShowItem::prenota);
    connect(restituisciButton, &QPushButton::clicked, this, &ShowItem::restituisci);

    connect(bibliotecaController, &BibliotecaController::datiAggiornati, this, &ShowItem::aggiornaDati);
    aggiornaDati();
}

void ShowItem::aggiornaDati() {

    if (!item) {
        qDebug() << "❌ Errore: Nessun item trovato per ID " << currentItemId;
        return;  // Evita il crash uscendo dalla funzione
    }

    titleLabel->setText("Titolo: " + item->getTitolo());
    authorLabel->setText("Autore: " + item->getAutore());
    quantityLabel->setText("Quantità disponibile: " + QString::number(item->getQuantity()));
    releaseYearLabel->setText("Anno di pubblicazione: " + QString::number(item->getReleaseYear()));
    genreLabel->setText("Genere: " + item->getGenre());

    if (const BookModel* book = dynamic_cast<const BookModel*>(item)) {
        publisherLabel->setText("Editore: "+book->getPublisher());
        ISBNLabel->setText("ISBN: "+book->getISBN());
        pageCountLabel->setText("Num Pagine: "+QString::number(book->getPageCount()));
        languageLabelB->setText("Lingua: "+book->getLanguage());
    }
    if (const FilmModel* film = dynamic_cast<const FilmModel*>(item)) {
        directorLabel->setText("Regista: "+film->getDirector());
        durationLabelF->setText("Durata: "+QString::number(film->getDuration())+ " Minuti");
        ratingLabel->setText("Rating: "+QString::number(film->getRating()));
        languageLabelF->setText("Lingua: "+film->getLanguage());
    }
    if (const MusicModel* music = dynamic_cast<const MusicModel*>(item)) {
        albumLabel->setText("Album: "+music->getAlbum());
        durationLabelM->setText("Durata: "+QString::number(music->getDuration())+ " Minuti");
        formatLabel->setText("Formato: "+music->getFormat());
        recordLabelLabel->setText("Etichetta Discografica: "+music->getRecordLabel());
    }

}
void ShowItem::prenota() {
    bibliotecaController->prenota(currentItemId);  // ✅ Chiamata alla funzione di prenotazione
    qDebug() << "✅ Prenotazione effettuata per ID: " << currentItemId;;
}
void ShowItem::restituisci() {
    bibliotecaController->restituisci(currentItemId);  // ✅ Chiamata alla funzione di prenotazione
    qDebug() << "✅ restituzione effettuata per ID: " << currentItemId;;
}