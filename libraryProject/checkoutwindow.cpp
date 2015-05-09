#include "checkoutwindow.h"
#include "ui_checkoutwindow.h"



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

}
