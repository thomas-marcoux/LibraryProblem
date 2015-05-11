#include "lastborrowed.h"
#include "ui_lastborrowed.h"
#include "createconnection.h"
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlError>

lastBorrowed::lastBorrowed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lastBorrowed)
{
    ui->setupUi(this);
}

lastBorrowed::~lastBorrowed()
{
    delete ui;
}

void lastBorrowed::on_buttonBox_accepted()
{
    QString userId = ui->userIdEdit->text(),
            bookId = ui->bookIdEdit->text();

    QSqlQuery query, queryForName;

    query.exec ("SELECT isStaff FROM user WHERE id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();
    qDebug() << query.lastError() << endl << isStaff;

    if(isStaff){
        query.exec("SELECT lastBorrowedBy FROM book WHERE bookId=" + bookId);
        qDebug() << query.lastError();
        query.next();
        if(query.value(0).toInt() != 0 && query.value(0).toString() != ""){
            queryForName.exec("SELECT name FROM user WHERE id=" + query.value(0).toString());
            queryForName.next();
            QString result = "Book ID " + bookId + " was last borrowed by " + queryForName.value(0).toString() + ".";
            QMessageBox::information(this, tr("Library Database"), result);
        }
        else{
            QMessageBox::information(this, tr("Library Database"), "That book either doesn't exist or hasn't been checked out");
        }
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
}
