#ifndef ADDREMOVEWINDOW_H
#define ADDREMOVEWINDOW_H

#include <QDialog>

namespace Ui {
class addRemoveWindow;
}

class addRemoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addRemoveWindow(QWidget *parent = 0);
    ~addRemoveWindow();

private:
    Ui::addRemoveWindow *ui;
};

#endif // ADDREMOVEWINDOW_H
