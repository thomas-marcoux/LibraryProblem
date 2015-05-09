#include "library.h"
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection()){

        qDebug() << "Not connected!";
        return 1;
    }
    else{

        qDebug() << "Connected!";

        QSqlQuery query;
        query.exec("SELECT name FROM user");

        while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << "name: " << name;
        }

        return 0;
    }

    library w;
    w.show();

    return a.exec();
}

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("librarydb");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) {

        qDebug() << "database error occurred";
        return false;

    }
    return true;
}
