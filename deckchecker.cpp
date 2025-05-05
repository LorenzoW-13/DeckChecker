//Source for main window
#include "deckchecker.h"

//Qt Libraries
#include <QLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QHeaderView>

bool dbConnection() {
    //Include an SQL Database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./test.db");

    if(!db.open()) {
        return false;
    }

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS cards (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, type TEXT NOT NULL, real INTEGER NOT NULL, deck TEXT NOT NULL)");

    return true;
}

QSqlTableModel* rowsDisplay(QObject* parent) {
    QSqlTableModel* model = new QSqlTableModel(parent);
    model->setTable("cards");
    model->setFilter("'type' = 'Artifact'");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Name");
    model->setHeaderData(2, Qt::Horizontal, "Type");
    model->setHeaderData(3, Qt::Horizontal, "");
    
    return model;
}

DeckChecker::DeckChecker(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);

    if(dbConnection()) {
        qDebug() << "False\n";
    }
    qDebug() << "True\n";

    //Recorded decks manager(s)
    QComboBox* existingDecks = new QComboBox();
    QPushButton* addDeck = new QPushButton("New Deck"); //slot: take the selected row's text and load a deck from the sql table where all the deck id equals the text

    //Deck manager(s) layout
    QWidget* decksManager = new QWidget();
    QHBoxLayout* MLayout = new QHBoxLayout(decksManager);

    //Connect to slots the managers
    connect(existingDecks, &QComboBox::activated, this, &DeckChecker::showSelected);
    connect(addDeck, &QPushButton::clicked, this, &DeckChecker::loadDecks);

    MLayout->addWidget(existingDecks);
    MLayout->addWidget(addDeck);

    //Decklist view
    QTableView* decklist = new QTableView();

    //Leftside section
    QWidget* CardList = new QWidget();
    QVBoxLayout* leftside = new QVBoxLayout(CardList);

    leftside->addWidget(decksManager);
    leftside->addWidget(decklist);

    //Deck model
    QSqlTableModel* model = rowsDisplay(this);

    //Add data and set functionalities and aspect
    decklist->setModel(model);
    decklist->setSelectionBehavior(QAbstractItemView::SelectRows);
    decklist->setEditTriggers(QAbstractItemView::DoubleClicked);
    decklist->setShowGrid(false);
    decklist->verticalHeader()->setVisible(false);

    setCentralWidget(CardList);

    //Application final layout
    QWidget* Window = new QWidget();
    QHBoxLayout* WLayout = new QHBoxLayout();
}

DeckChecker::~DeckChecker() {

}

void DeckChecker::showSelected() {
    qDebug() << "Selected a list element\n";
}

void DeckChecker::loadDecks() {
    qDebug() << "New Decks clicked\n";
    close();
}