#include "listcheckedout.h"
#include "ui_listcheckedout.h"
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

listCheckedOut::listCheckedOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listCheckedOut)
{
    ui->setupUi(this);
}

listCheckedOut::~listCheckedOut()
{
    delete ui;
}

void listCheckedOut::on_buttonBox_accepted()
{
    QString userId = ui->userIdEdit->text(),
            borrowerId = ui->borrowerIdEdit->text();

    QSqlQuery query;
    query.exec ("SELECT isStaff from user where id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();

    if (isStaff){
        query.exec ("SELECT bookId, title FROM book where borrowedBy=" + borrowerId);
        qDebug() << query.lastError();
    }
    else {
        query.exec ("SELECT bookId, title FROM book where borrowedBy=" + userId);
        borrowerId = userId; //sets borrowerId to userId since non-staff can only check their checked out books
        qDebug() << query.lastError();
    }

    QString result;
    while(query.next()){
        result = result + query.value(0).toString() + " " + query.value(1).toString() + "\n";
    }

    query.exec ("SELECT name FROM user where id=" + borrowerId);
    qDebug() << query.lastError();
    query.next();
    result = query.value(0).toString() + "'s borrowed books:\n\n" + result;
    QMessageBox::information(this, "Library Database", result);
}
