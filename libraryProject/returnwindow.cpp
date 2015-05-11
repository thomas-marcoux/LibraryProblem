#include "returnwindow.h"
#include "ui_returnwindow.h"
#include "createconnection.h"
#include "main.cpp"
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QMessageBox>

returnWindow::returnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnWindow)
{
    ui->setupUi(this);
}

returnWindow::~returnWindow()
{
    delete ui;
}

void returnWindow::on_buttonBox_accepted()
{
    QString userId = ui->userIdEdit->text(),
            bookId = ui->bookIdEdit->text(),
            borrowerId = ui->borrowerIdEdit->text();

    QSqlQuery query;

    query.exec ("SELECT isStaff from user where id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();
    qDebug() << query.lastError() << endl << isStaff;

    if (isStaff){
        query.exec ("UPDATE book SET lastBorrowedBy=borrowedBy WHERE bookId=" + bookId);
        qDebug() << query.lastError();
        query.exec ("UPDATE user SET numCheckedOut=numCheckedOut-1 WHERE id="+ borrowerId);
        qDebug() << query.lastError();
        QSqlQuery queryForName;
        queryForName.exec("SELECT name, numCheckedOut FROM user where id=" + borrowerId);
        queryForName.next();
        QString msg = queryForName.value(0).toString() + " now has " + queryForName.value(1).toString() + " books checked out.";
         QMessageBox::information(this, tr("Library Database"), msg);
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
    this->close();
}

void returnWindow::on_buttonBox_rejected()
{
    this->close();
}
