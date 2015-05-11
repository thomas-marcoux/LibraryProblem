#include "addremovewindow.h"
#include "ui_addremovewindow.h"
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

addRemoveWindow::addRemoveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRemoveWindow)
{
    ui->setupUi(this);
}

addRemoveWindow::~addRemoveWindow()
{
    delete ui;
}

void addRemoveWindow::on_addButton_clicked()
{
    QString userId  =    ui->userIdEdit->text(),
            title   =    ui->titleEdit->text(),
            year    =    ui->yearEdit->text(),
            author  =    ui->authorEdit->text(),
            isbn    =    ui->isbnEdit->text(),
            subject =    ui->subjectEdit->text();

    QSqlQuery query;

    query.exec ("SELECT isStaff from user where id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();
    qDebug() << query.lastError() << endl << isStaff;

    if (isStaff) {
        query.exec ("INSERT INTO book (year, author, subject, isbn, title) VALUES (" + year + "," +  author + "," + subject + "," + isbn + "," + title + ")");
        qDebug() << query.lastError();
        query.exec("SELECT bookId WHERE isbn=" + isbn + "AND title=" + title);
        query.last();
        QMessageBox::information(this, tr("Library Database"), tr("Book added as Book ID " + query.value(0).toInt()));
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
}

void addRemoveWindow::on_removeButton_clicked()
{
    QString userId  =   ui->userIdEdit->text(),
            bookId  =   ui->bookIdEdit->text();

    QSqlQuery query;

    query.exec ("SELECT isStaff from user where id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();
    qDebug() << query.lastError() << endl << isStaff;

    if (isStaff) {
        query.exec ("DELETE FROM book WHERE bookid=" + bookId);
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("Library Database"), tr("Transaction complete."));
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
}

void addRemoveWindow::on_buttonBox_rejected()
{
    this->close();
}
