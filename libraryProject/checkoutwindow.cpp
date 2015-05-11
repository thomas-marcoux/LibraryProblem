#include "checkoutwindow.h"
#include "ui_checkoutwindow.h"
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




checkOutWindow::checkOutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkOutWindow)
{
    ui->setupUi(this);
}

checkOutWindow::~checkOutWindow()
{
    delete ui;
}

void checkOutWindow::on_buttonBox_accepted()
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
        query.exec("SELECT numCheckedOut from user where id=" + borrowerId);
        QInt numCheckedOut = query.value(0).toInt();

        if(query.next() && numCheckedOut < 10){
            query.exec ("UPDATE book SET borrowedBy=" + borrowerId + " WHERE bookId=" + bookId);
            qDebug() << query.lastError();
            query.exec ("UPDATE user SET numCheckedOut=numCheckedOut+1 WHERE id="+ borrowerId);
            qDebug() << query.lastError();
            QMessageBox::information(this, tr("Library Database"), tr("Transaction complete."));
        }

        else if (numCheckedOut >= 10){
            QMessageBox::information(this, tr("Library Database"), tr("User has too many books checked out already."));
        }

        else{
            QMessageBox::information(this, tr("Library Database"), tr("User does not exist."));
        }
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
}

