#ifndef LISTCHECKEDOUT_H
#define LISTCHECKEDOUT_H

#include <QDialog>

namespace Ui {
class listCheckedOut;
}

class listCheckedOut : public QDialog
{
    Q_OBJECT

public:
    explicit listCheckedOut(QWidget *parent = 0);
    ~listCheckedOut();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::listCheckedOut *ui;
};

#endif // LISTCHECKEDOUT_H
