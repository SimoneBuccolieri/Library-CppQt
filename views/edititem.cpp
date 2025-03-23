//
// Created by Simone Buccolieri on 22/03/25.
//

#include "edititem.h"
EditItem::EditItem(BibliotecaController *bibliotecaController, int id, QWidget *parent)
    : QWidget(parent), bibliotecaController(bibliotecaController), currentItemId(id) {
     item = bibliotecaController->getItemById(currentItemId);


    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    QPushButton *backButton = new QPushButton("Indietro");
    layout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(backButton, &QPushButton::clicked, this, &EditItem::back);
    //Item
    titleLabel = new QLineEdit(item->getTitolo(), this);
    formLayout->addRow("Titolo:", titleLabel);
    authorLabel = new QLineEdit(item->getAutore(), this);
    formLayout->addRow("Autore:", authorLabel);
    quantityLabel = new QLineEdit(QString::number(item->getQuantity()), this);
    formLayout->addRow("Quantità:", quantityLabel);
    releaseYearLabel = new QLineEdit(QString::number(item->getReleaseYear()), this);
    formLayout->addRow("Anno di Rilascio:", releaseYearLabel);
    genreLabel = new QLineEdit(item->getGenre(), this);
    formLayout->addRow("Genere:", genreLabel);
    iconLabel = new QLineEdit(item->getIcon(), this);
    formLayout->addRow("Icona:", iconLabel);
    //Book
    if (auto *book = dynamic_cast<BookModel*>(item)) {
        publisherLabel = new QLineEdit(book->getPublisher(), this);
        formLayout->addRow("Editore:", publisherLabel);
        ISBNLabel = new QLineEdit(book->getISBN(), this);
        formLayout->addRow("ISBN:", ISBNLabel);
        pageCountLabel = new QLineEdit(QString::number(book->getPageCount()), this);
        formLayout->addRow("Pagine:", pageCountLabel);
        languageLabelB = new QLineEdit(book->getLanguage(), this);
        formLayout->addRow("Lingua:", languageLabelB);
    }
    //Film
    if (auto *film = dynamic_cast<FilmModel*>(item)) {
        directorLabel = new QLineEdit(film->getDirector(), this);
        formLayout->addRow("Regista:", directorLabel);
        durationLabelF = new QLineEdit(QString::number(film->getDuration()), this);
        formLayout->addRow("Durata:", durationLabelF);
        ratingLabel = new QLineEdit(QString::number(film->getRating()), this);
        formLayout->addRow("Rating:", ratingLabel);
        languageLabelF = new QLineEdit(film->getLanguage(), this);
        formLayout->addRow("Lingua:", languageLabelF);
    }
    //Music
    if (auto *music = dynamic_cast<MusicModel*>(item)) {
        albumLabel = new QLineEdit(music->getAlbum(), this);
        formLayout->addRow("Album:", albumLabel);
        durationLabelM = new QLineEdit(QString::number(music->getDuration()), this);
        formLayout->addRow("Durata:", durationLabelM);
        formatLabel = new QLineEdit(music->getFormat(), this);
        formLayout->addRow("Formato:", formatLabel);
        recordLabelLabel = new QLineEdit(music->getRecordLabel(), this);
        formLayout->addRow("Etichetta discografica:", recordLabelLabel);
    }
    layout->addLayout(formLayout);
    QPushButton *saveButton = new QPushButton("Salva", this);
    QPushButton *deleteButton = new QPushButton("Elimina", this);
    layout->addWidget(saveButton,0,Qt::AlignHCenter);
    layout->addWidget(deleteButton,0,Qt::AlignHCenter);
    connect(saveButton, &QPushButton::clicked, this, &EditItem::saveClicked);
    connect(deleteButton, &QPushButton::clicked, this, &EditItem::eliminaClicked);


}
void EditItem::back() {
    bibliotecaController->update();
    emit backRequested();  // emetti segnale verso il controller
}
void EditItem::saveClicked() {
    item->setIcon(iconLabel->text());
    item->setTitolo(titleLabel->text());
    item->setAutore(authorLabel->text());
    item->setQuantity(quantityLabel->text().toInt());
    item->setReleaseYear(releaseYearLabel->text().toInt());
    item->setGenre(genreLabel->text());

    bibliotecaController->update();
    back();
}

void EditItem::eliminaClicked() {
    bibliotecaController->deleteId(currentItemId);
    bibliotecaController->update();
    back();
}