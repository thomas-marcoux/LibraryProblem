#ifndef LASTBORROWED_H
#define LASTBORROWED_H

#include <QDialog>

namespace Ui {
class lastBorrowed;
}

class lastBorrowed : public QDialog
{
    Q_OBJECT

public:
    explicit lastBorrowed(QWidget *parent = 0);
    ~lastBorrowed();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::lastBorrowed *ui;
};

#endif // LASTBORROWED_H
