//Fill the table with test data
#include "SQLite3/sqlite3.h"

int main() {
    sqlite3* db;
    sqlite3_open("build/test.db", &db);

    char* errmsg;
    
    const char* sql0 = "CREATE TABLE IF NOT EXISTS cards (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, type TEXT NOT NULL, real INTEGER NOT NULL, deck TEXT NOT NULL)";

    const char* sql1 = "INSERT INTO cards (name, type, real, deck) VALUES ('Pine', 'Creature', 1, 'Korvold');";
    const char* sql2 = "INSERT INTO cards (name, type, real, deck) VALUES ('Gine', 'Creature', 0, 'Korvold');";
    const char* sql3 = "INSERT INTO cards (name, type, real, deck) VALUES ('Pin1', 'Artifact', 1, 'Korvold');";
    const char* sql4 = "INSERT INTO cards (name, type, real, deck) VALUES ('Gin1', 'Artifact', 0, 'Korvold');";
    const char* sql5 = "INSERT INTO cards (name, type, real, deck) VALUES ('Bobe', 'Enchant', 1, 'Korvold');";
    const char* sql6 = "INSERT INTO cards (name, type, real, deck) VALUES ('Robe', 'Enchnat', 0, 'Korvold');";
    const char* sql7 = "INSERT INTO cards (name, type, real, deck) VALUES ('Aldon', 'Land', 1, 'Korvold');";
    const char* sql8 = "INSERT INTO cards (name, type, real, deck) VALUES ('Sgnecke', 'Land', 0, 'Korvold');";

    sqlite3_exec(db, sql0, nullptr, nullptr, &errmsg);
    
    sqlite3_exec(db, sql1, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql2, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql3, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql4, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql5, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql6, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql7, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql8, nullptr, nullptr, &errmsg);

    const char* sql9 = "CREATE TABLE IF NOT EXISTS Decks (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, colors TEXT NOT NULL)";

    const char* sql10 = "INSERT INTO Decks (name, colors) VALUES ('Korvold', 'Jund');";

    sqlite3_exec(db, sql9, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql10, nullptr, nullptr, &errmsg);

    sqlite3_close(db);

    return 0;
}