#include "library.h"
#include "createconnection.h"
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createConnection();

    library w;
    w.show();

    return a.exec();
}


