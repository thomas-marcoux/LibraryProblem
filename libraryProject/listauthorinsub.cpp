#include "listauthorinsub.h"
#include "ui_listauthorinsub.h"

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


listAuthorInSub::listAuthorInSub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listAuthorInSub)
{
    ui->setupUi(this);
}

listAuthorInSub::~listAuthorInSub()
{
    delete ui;
}

void listAuthorInSub::on_buttonBox_accepted()
{
    QString author  =    ui->authorEdit->text(),
            subject =    ui->subjectEdit->text();

    QSqlQuery query;

    query.exec ("SELECT title FROM book WHERE subject=\"" + subject + "\" AND author=\"" + author + "\"");
    qDebug() << query.lastError();
    QString resultString = "List of books in subject \"" + subject + "\" by author \"" + author + "\":\n\n";

    while (query.next()){

        resultString = resultString + query.value(0).toString() + "\n";
        qDebug() << resultString;
    }
    QMessageBox::information(this, "Library Database", resultString);
}
