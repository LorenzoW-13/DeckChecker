//Cpp file for the error dialog
#include "databaseerror.h"

DBError::DBError(QWidget* parent) : QDialog(parent) {
    ui.setupUi(this);

    connect(ui.Ok, &QPushButton::clicked, this, &QDialog::close);
}