#ifndef ADDREMOVEWINDOW_H
#define ADDREMOVEWINDOW_H

#include <QDialog>

namespace Ui {
class AddRemoveWindow;
}

class AddRemoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddRemoveWindow(QWidget *parent = 0);
    ~AddRemoveWindow();

private:
    Ui::AddRemoveWindow *ui;
};

#endif // ADDREMOVEWINDOW_H
