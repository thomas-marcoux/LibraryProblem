#include "library.h"
#include "ui_library.h"
#include "checkoutwindow.h"

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
    checkOutWindow checkOutWindow;
    checkOutWindow.setModal(true);
    checkOutWindow.exec();
}
