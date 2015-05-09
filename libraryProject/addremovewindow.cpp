#include "addremovewindow.h"
#include "ui_addremovewindow.h"

AddRemoveWindow::AddRemoveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRemoveWindow)
{
    ui->setupUi(this);
}

AddRemoveWindow::~AddRemoveWindow()
{
    delete ui;
}
