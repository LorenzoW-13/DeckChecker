//Fill the table with test data
#include "SQLite3/sqlite3.h"

int main() {
    sqlite3* db;
    sqlite3_open("test.db", &db);

    char* errmsg;
    
    const char* sql0 = "CREATE TABLE IF NOT EXISTS cards (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, type TEXT NOT NULL, real INTEGER NOT NULL, deck TEXT NOT NULL)";

    const char* sql1 = "INSERT INTO cards (name, type, real, deck) VALUES ('Pina', 'Creature', 1, 'Korvold');";
    const char* sql2 = "INSERT INTO cards (name, type, real, deck) VALUES ('Gina', 'Creature', 0, 'Korvold');";
    const char* sql3 = "INSERT INTO cards (name, type, real, deck) VALUES ('Pino', 'Artifact', 1, 'Korvold');";
    const char* sql4 = "INSERT INTO cards (name, type, real, deck) VALUES ('Gino', 'Artifact', 0, 'Korvold');";
    const char* sql5 = "INSERT INTO cards (name, type, real, deck) VALUES ('Bob', 'Enchant', 1, 'Korvold');";
    const char* sql6 = "INSERT INTO cards (name, type, real, deck) VALUES ('Rob', 'Enchnat', 0, 'Korvold');";
    const char* sql7 = "INSERT INTO cards (name, type, real, deck) VALUES ('Aldo', 'Land', 1, 'Korvold');";
    const char* sql8 = "INSERT INTO cards (name, type, real, deck) VALUES ('Sgneck', 'Land', 0, 'Korvold');";

    sqlite3_exec(db, sql0, nullptr, nullptr, &errmsg);
    
    sqlite3_exec(db, sql1, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql2, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql3, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql4, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql5, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql6, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql7, nullptr, nullptr, &errmsg);
    sqlite3_exec(db, sql8, nullptr, nullptr, &errmsg);

    sqlite3_close(db);

    return 0;
}