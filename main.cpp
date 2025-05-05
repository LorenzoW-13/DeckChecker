//Main.cpp of DeckChecker

//QT class headers
#include "deckchecker.h"
#include <QtWidgets/QApplication>

//Main function
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    DeckChecker w;
    w.show();
    return a.exec();
}