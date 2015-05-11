#include "createconnection.h"
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>


createConnection::createConnection()
{
createConnection();
}

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("library");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok) {

        qDebug() << "database error occurred";
        return false;

    }
    else {
        QSqlQuery query;
        query.exec("SELECT * FROM user");
        query.next();
        QString result = query.value(0).toString();

    }
    return true;
}
