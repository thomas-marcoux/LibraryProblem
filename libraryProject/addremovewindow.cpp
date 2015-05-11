#include "addremovewindow.h"
#include "ui_addremovewindow.h"

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

    query.exec ("INSERT INTO book VALUES (" + year + "," +  author + "," + subject + "," + isbn + "," + title + ")");

}
