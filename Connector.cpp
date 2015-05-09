#include "Connector.h"

Connector::Connector()
{
  driver = sql::mysql::get_mysql_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", USER, PASSWORD);
  stmt = con->createStatement();
  stmt->execute("USE " DATABASE_NAME);
}

Connector::~Connector()
{
  delete stmt;
  delete con;
}
