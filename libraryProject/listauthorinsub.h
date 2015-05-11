#ifndef LISTAUTHORINSUB_H
#define LISTAUTHORINSUB_H

#include <QDialog>

namespace Ui {
class listAuthorInSub;
}

class listAuthorInSub : public QDialog
{
    Q_OBJECT

public:
    explicit listAuthorInSub(QWidget *parent = 0);
    ~listAuthorInSub();

private:
    Ui::listAuthorInSub *ui;
};

#endif // LISTAUTHORINSUB_H
