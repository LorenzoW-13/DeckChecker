//Header for main window
#ifndef DECKCHECKER_H
#define DECKCHECKER_H

#include <QtWidgets/QMainWindow>
#include <ui_deckchecker.h>

class DeckChecker : public QMainWindow {
    Q_OBJECT

    public:
        //Construcotr and destructor
        DeckChecker(QWidget *parent = nullptr);
        ~DeckChecker();

    private:
        //Deckchecker ui object from Qt Creator
        Ui::MainWindow ui;

    private slots:
        //Show selected deck function
        void showSelected();
        //New deck function
        void loadDecks();
};

#endif