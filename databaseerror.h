//Dialog to notify database errors to the user
#ifndef DATABASEEROORS_H
#define DATABASEERRORS_H

#include <QDialog>
#include <ui_databaseerror.h>

class DBError : public QDialog {
    Q_OBJECT

    public:
        DBError(QWidget* parent = nullptr);
        ~DBError() {};
        
    private: 
        Ui::DBError ui;

    
};

#endif //Database opening error