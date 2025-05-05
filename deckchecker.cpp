//Source for main window
#include "deckchecker.h"

//Qt Libraries
#include <QLayout>
#include <QComboBox>
#include <QPushButton>

DeckChecker::DeckChecker(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);

    //Recorded decks manager(s)
    QComboBox* existingDecks = new QComboBox();
    QPushButton* addDeck = new QPushButton(); //slot: take the selected row's text and load a deck from the sql table where all the deck id equals the text

    //Deck manager(s) layout

    //Application final layout
    QWidget* Window = new QWidget();
    QHBoxLayout* WLayout = new QHBoxLayout();
}

DeckChecker::~DeckChecker() {

}

void DeckChecker::loadDecks() {

}