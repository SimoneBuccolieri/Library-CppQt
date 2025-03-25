// initialfileselector.h
#ifndef INITIALFILESELECTOR_H
#define INITIALFILESELECTOR_H

#include <QDialog>
#include <QLabel>

class InitialFileSelector : public QDialog {
    Q_OBJECT

public:
    explicit InitialFileSelector(QWidget *parent = nullptr);

};

#endif // INITIALFILESELECTOR_H
