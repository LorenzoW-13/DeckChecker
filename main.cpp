//Main.cpp of DeckChecker

//QT class headers
#include "deckchecker.h"
#include "databaseerror.h"
#include <QtWidgets/QApplication>

//Database connection method
bool dbConnection() {
    //SQLite database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./test.db");

    //In case of errors with the databse a popup is shown and the app closes
    if(!db.open()) {
        return false;
    }

    //if database ok ensures tables existence
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS Decks (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, colors TEXT NOT NULL)");
    query.exec("CREATE TABLE IF NOT EXISTS cards (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, type TEXT NOT NULL, proxy INT, deck TEXT NOT NULL)");

    query.exec("CREATE INDEX IF NOT EXISTS idx_deck ON cards(deck)");
    query.exec("CREATE INDEX IF NOT EXISTS idx_type ON cards(type)");
    
    return true;
}

//Main function
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    DeckChecker w;
    DBError err;

    //Check for database correct behavior
    if(!dbConnection())
    {
        //Error with database only shows the error popup
        err.show();
    }
    else {
        //If database is working launch application
        w.show();
    }

    return a.exec();
}