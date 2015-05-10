#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "checkoutwindow.h"
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QDebug>
#include <QApplication>
#include <QtSql/QSql>
#include <QCoreApplication>


namespace Ui {
class library;
}

class library : public QMainWindow
{
    Q_OBJECT

public:

    explicit library(QWidget *parent = 0);
    ~library();

private slots:
    void on_checkOutButton_clicked();
    void on_addRemoveButton_clicked();

private:
    Ui::library *ui;
};

bool createConnection();

#endif // LIBRARY_H
