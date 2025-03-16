//
// Created by Simone Buccolieri on 16/03/25.
//

#include "bibliotecamodel.h"

void BibliotecaModel::aggiungiLibro(const Libro &libro) {
    libri.append(libro);
}

void BibliotecaModel::rimuoviLibro(const QString &isbn) {
    for (int i = 0; i < libri.size(); ++i) {
        if (libri[i].getIsbn() == isbn) {
            libri.removeAt(i);
            break;
        }
    }
}

QList<Libro> BibliotecaModel::getLibri() const {
    return libri;
}
void BibliotecaModel::salvaSuFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug("Errore: impossibile aprire il file per scrittura!");
        return;
    }

    QTextStream out(&file);
    for (const Libro &libro : libri) {
        out << libro.getTitolo() << "," << libro.getAutore() << "," << libro.getIsbn() << "\n";
    }

    file.close();
}
void BibliotecaModel::caricaDaFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("Errore: impossibile aprire il file per lettura!");
        return;
    }

    libri.clear();  // Pulisce la lista prima di caricare nuovi dati
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList dati = line.split(",");

        if (dati.size() == 3) {  // Controllo validità
            libri.append(Libro(dati[0], dati[1], dati[2]));
        }
    }

    file.close();
}
