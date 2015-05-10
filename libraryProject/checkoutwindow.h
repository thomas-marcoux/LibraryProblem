#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include "createConnection.h"
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
class checkOutWindow;
}

class checkOutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit checkOutWindow(QWidget *parent = 0);
    ~checkOutWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::checkOutWindow *ui;
};

#endif // CHECKOUTWINDOW_H
