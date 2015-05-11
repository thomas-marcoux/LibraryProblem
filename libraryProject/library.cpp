#include "library.h"
#include "ui_library.h"
#include "checkoutwindow.h"
#include "addremovewindow.h"
#include "listauthorinsub.h"
#include "listcheckedout.h"
#include "lastborrowed.h"
#include "returnwindow.h"

library::library(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::library)
{
    ui->setupUi(this);
}

library::~library()
{
    delete ui;
}

void library::on_checkOutButton_clicked()
{
    checkOutWindow checkOutWindow;
    checkOutWindow.setModal(true);
    checkOutWindow.exec();
}

void library::on_addRemoveButton_clicked()
{
    addRemoveWindow addRemoveWindow;
    addRemoveWindow.setModal(true);
    addRemoveWindow.exec();
}

void library::on_listAuthorSubButton_clicked()
{
    listAuthorInSub listAuthorInSub;
    listAuthorInSub.setModal(true);
    listAuthorInSub.exec();
}

void library::on_listBorrowerBooksButton_clicked()
{
    listCheckedOut listCheckedOut;
    listCheckedOut.setModal(true);
    listCheckedOut.exec();
}

void library::on_lastBorrowedButton_clicked()
{
    lastBorrowed lastBorrowed;
    lastBorrowed.setModal(true);
    lastBorrowed.exec();
}

void library::on_returnBookButton_clicked()
{
    returnWindow returnWindow;
    returnWindow.setModal(true);
    returnWindow.exec();
}
