#include "listauthorinsub.h"
#include "ui_listauthorinsub.h"

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
    QString userId  =    ui->userIdEdit->text(),
            author  =    ui->authorEdit->text(),
            subject =    ui->subjectEdit->text();

    QSqlQuery query;

    query.exec ("SELECT isStaff from user where id=" + userId);
    query.next();
    bool isStaff = query.value(0).toBool();
    qDebug() << query.lastError() << endl << isStaff;

    if (isStaff) {
        query.exec ("SELECT author, subject WHERE subject =$subject;");
        qDebug() << query.lastError();
        QMessageBox::information(this, tr("Library Database"), tr("Transaction complete."));
    }
    else{
        QMessageBox::information(this, tr("Library Database"), tr("You do not have access to this transaction"));
    }
}
