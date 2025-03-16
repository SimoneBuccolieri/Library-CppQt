/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableLibri;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputTitolo;
    QLineEdit *inputAutore;
    QLineEdit *inputISBN;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnAggiungi;
    QPushButton *btnRimuovi;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableLibri = new QTableWidget(centralwidget);
        if (tableLibri->columnCount() < 3)
            tableLibri->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableLibri->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableLibri->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableLibri->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableLibri->setObjectName("tableLibri");

        verticalLayout->addWidget(tableLibri);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        inputTitolo = new QLineEdit(centralwidget);
        inputTitolo->setObjectName("inputTitolo");

        horizontalLayout->addWidget(inputTitolo);

        inputAutore = new QLineEdit(centralwidget);
        inputAutore->setObjectName("inputAutore");

        horizontalLayout->addWidget(inputAutore);

        inputISBN = new QLineEdit(centralwidget);
        inputISBN->setObjectName("inputISBN");

        horizontalLayout->addWidget(inputISBN);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnAggiungi = new QPushButton(centralwidget);
        btnAggiungi->setObjectName("btnAggiungi");

        horizontalLayoutButtons->addWidget(btnAggiungi);

        btnRimuovi = new QPushButton(centralwidget);
        btnRimuovi->setObjectName("btnRimuovi");

        horizontalLayoutButtons->addWidget(btnRimuovi);


        verticalLayout->addLayout(horizontalLayoutButtons);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestione Biblioteca", nullptr));
        inputTitolo->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci Titolo", nullptr));
        inputAutore->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci Autore", nullptr));
        inputISBN->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci ISBN", nullptr));
        btnAggiungi->setText(QCoreApplication::translate("MainWindow", "Aggiungi Libro", nullptr));
        btnRimuovi->setText(QCoreApplication::translate("MainWindow", "Rimuovi Libro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
