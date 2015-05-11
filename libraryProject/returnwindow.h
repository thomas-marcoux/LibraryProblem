#ifndef RETURNWINDOW_H
#define RETURNWINDOW_H

#include <QDialog>

namespace Ui {
class returnWindow;
}

class returnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit returnWindow(QWidget *parent = 0);
    ~returnWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::returnWindow *ui;
};

#endif // RETURNWINDOW_H
