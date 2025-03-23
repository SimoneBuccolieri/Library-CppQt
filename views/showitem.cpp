//
// Created by Simone Buccolieri on 19/03/25.
//

#include "showitem.h"
ShowItem::ShowItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {
     item = bibliotecaController->getItemById(currentItemId);


    layout = new QVBoxLayout(this);
    QPushButton *backButton = new QPushButton("Indietro");
    layout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &ShowItem::back);
    QFormLayout *formLayout = new QFormLayout();
    //Item
    iconLabel = new QLabel(this);
    formLayout->addRow("Icona:", iconLabel);
    titleLabel = new QLabel(this);
    formLayout->addRow("Titolo:", titleLabel);
    authorLabel = new QLabel(this);
    formLayout->addRow("Autore:", authorLabel);
    quantityLabel = new QLabel(this);
    formLayout->addRow("Quantità disponibile:", quantityLabel);
    releaseYearLabel = new QLabel(this);
    formLayout->addRow("Anno di pubblicazione:", releaseYearLabel);
    genreLabel = new QLabel(this);
    formLayout->addRow("Genere:", genreLabel);

    //Book
    if (auto *book = dynamic_cast<BookModel*>(item)) {
        publisherLabel = new QLabel(this);
        formLayout->addRow("Editore:", publisherLabel);
        ISBNLabel = new QLabel(this);
        formLayout->addRow("ISBN:", ISBNLabel);
        pageCountLabel = new QLabel(this);
        formLayout->addRow("Pagine:", pageCountLabel);
        languageLabelB = new QLabel(this);
        formLayout->addRow("Lingua:", languageLabelB);
    }
    //Film
    if (auto *film = dynamic_cast<FilmModel*>(item)) {
        directorLabel = new QLabel(this);
        formLayout->addRow("Regista:", directorLabel);
        durationLabelF = new QLabel(this);
        formLayout->addRow("Durata:", durationLabelF);
        ratingLabel = new QLabel(this);
        formLayout->addRow("Rating:", ratingLabel);
        languageLabelF = new QLabel(this);
        formLayout->addRow("Lingua:", languageLabelF);
    }
    //Music
    if (auto *music = dynamic_cast<MusicModel*>(item)) {
        albumLabel = new QLabel(this);
        formLayout->addRow("Album:", albumLabel);
        durationLabelM = new QLabel(this);
        formLayout->addRow("Durata:", durationLabelM);
        formatLabel = new QLabel(this);
        formLayout->addRow("Formato:", formatLabel);
        recordLabelLabel = new QLabel(this);
        formLayout->addRow("Etichetta discografica:", recordLabelLabel);
    }
    layout->addLayout(formLayout);
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
    iconLabel->setText(item->getIcon());
    titleLabel->setText(item->getTitolo());
    authorLabel->setText(item->getAutore());
    quantityLabel->setText(QString::number(item->getQuantity()));
    releaseYearLabel->setText(QString::number(item->getReleaseYear()));
    genreLabel->setText(item->getGenre());

    if (const BookModel* book = dynamic_cast<const BookModel*>(item)) {
        publisherLabel->setText(book->getPublisher());
        ISBNLabel->setText(book->getISBN());
        pageCountLabel->setText(QString::number(book->getPageCount()));
        languageLabelB->setText(book->getLanguage());
    }
    if (const FilmModel* film = dynamic_cast<const FilmModel*>(item)) {
        directorLabel->setText(film->getDirector());
        durationLabelF->setText(QString::number(film->getDuration())+ " Minuti");
        ratingLabel->setText(QString::number(film->getRating()));
        languageLabelF->setText(film->getLanguage());
    }
    if (const MusicModel* music = dynamic_cast<const MusicModel*>(item)) {
        albumLabel->setText(music->getAlbum());
        durationLabelM->setText(QString::number(music->getDuration())+ " Minuti");
        formatLabel->setText(music->getFormat());
        recordLabelLabel->setText(music->getRecordLabel());
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
void ShowItem::back() {
    bibliotecaController->update();
    emit backRequested();  // emetti segnale verso il controller
}